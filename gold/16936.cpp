#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> ans;
		for(ll i=0;i<n;++i){
			map<ll,ll> check;
			ans.clear();
			for(ll j=0;j<n;++j){
				++check[v[j]];
			}
			ans.push_back(v[i]);
			--check[v[i]];
			ll x=v[i];
			while(1){
				if(x%3==0){
					if(check[x/3]){
						--check[x/3];
						ans.push_back(x/3);
						x/=3;
					}else{
						if(check[x*2]){
							--check[x*2];
							ans.push_back(x*2);
							x*=2;
						}else{
							break;
						}
					}
				}else{
					if(check[x*2]){
						--check[x*2];
						ans.push_back(x*2);
						x*=2;
					}else{
						break;
					}
				}
			}
			ll as=ans.size();
			if(as==n) break;
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i];
			if(i!=n-1){
				cout<<" ";
			}
		}
	}
		

	return 0;
}