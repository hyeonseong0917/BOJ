#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll ans=1;
		vector<ll> p(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			p[i]=v[i];
		}
		sort(p.begin(),p.end());
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(v[i]!=p[i]){
				flag=1;
				break;
			}
		}
		if(!flag){
			cout<<1;
		}else{
			flag=0;
			ll cnt=0;
			for(ll i=1;i<n;++i){
				if(v[i]<v[i-1]){
					++cnt;
				}
				if(cnt && v[0]<v[i]){
					flag=1;
				}
			}
			if(!flag && cnt==1){
				cout<<2;
			}else{
				cout<<3;
			}
		}
		
	}
	return 0;
}