#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
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
		ll n,k;
		cin>>n>>k;
		stack<ll> st[k+1];
		ll cur_num=2;
		st[0].push(1);
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// vector<ll> m[n+1];
		map<ll,ll> m[n+1];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<i;++j){
				m[v[i]][v[j]]=1;
			}
		}
		bool flag=0;
		while(cur_num<=n){
			ll idx=0;
			while(idx<k){
				if(st[idx].empty()){
					st[idx].push(cur_num);
					++cur_num;
					break;
				}
				ll cur_top_num=st[idx].top();
				if(m[cur_top_num][cur_num]){
					++idx;
				}else{
					st[idx].push(cur_num);
					++cur_num;
					break;
				}
			}
			if(idx==k){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO";
		}else{
			cout<<"YES";
		}
	}
	return 0;
}
