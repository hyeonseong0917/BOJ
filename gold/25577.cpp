#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> tmp;
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			tmp.push_back(v[i]);
		}
		sort(tmp.begin(),tmp.end());
		ll cnt=1;
		for(ll i=0;i<n;++i){
			m[tmp[i]]=cnt++;
		}
		vector<ll> check(n+1,0);
		for(ll i=0;i<n;++i){
			v[i]=m[v[i]];
			check[v[i]]=i;
		}
		// check[x]: 수 x가 현재 어떤 idx에 있는지?
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(v[i]!=i+1){
				ll next_idx=check[i+1];
				v[next_idx]=v[i];
				check[v[next_idx]]=next_idx;
				++ans;
			}
		}
		cout<<ans;

		// [1,3,2,5,4]
		// i,j를 바꿀 수 있음. 최소횟수를 구한다면?
		// 최대횟수:n-1
		
	}
	return 0;
}