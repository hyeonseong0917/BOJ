#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,w;
		cin>>n>>w;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<w;
			continue;
		}
		// 0 1 2 3 4 5 6 7 8 9
		// 5 7 5 4 2 7 8 5 3 4

		// 5 7
		// 2 7 8
		// 3 4
		// 5 7 7 7 8 6
		ll idx=0;
		ll cur_money=w;
		ll L=-1;
		while(idx<n){
			if(idx==n-1){
				if(L==-1){
					++idx;
				}else{
					ll cur_coin=cur_money/v[L];
					cur_money-=cur_coin*v[L];
					cur_money+=cur_coin*v[idx];
					++idx;
					L=-1;
				}
				break;
			}
			if(v[idx]>v[idx+1]){
				if(L==-1){
					++idx;
				}else{
					ll cur_coin=cur_money/v[L];
					cur_money-=cur_coin*v[L];
					cur_money+=cur_coin*v[idx];
					++idx;
					L=-1;
				}
			}else{
				if(L==-1){
					L=idx;
				}
				++idx;
			}
		}
		cout<<cur_money;
	} 
	return 0;
}