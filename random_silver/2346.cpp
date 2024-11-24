#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
ll ans=0;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0),check(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> ans;
		ll idx=0;
		check[idx]=1;
		ans.push_back(1);
		while(1){
			if(!ans.empty()){
				ll as=ans.size();
				if(as==n) break;
			}
			// idx번째 인덱스 터트리기
			ll cur_step=v[idx];
			
			// !check인 값들 중 cur_step만큼 이동
			if(cur_step>0){
				// ++idx
				while(cur_step){
					++idx;
					if(idx==n){
						idx=0;
					}
					if(!check[idx]){
						--cur_step;
					}
				}
			}else{
				// --idx
				cur_step*=-1;
				while(cur_step){
					--idx;
					if(idx==-1){
						idx=n-1;
					}
					if(!check[idx]){
						--cur_step;
					}
				}
			}
			check[idx]=1;
			ans.push_back(idx+1);

		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}
	}
	

	

	return 0;
}