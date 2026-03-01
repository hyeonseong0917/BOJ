#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back

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
		ll K;
		cin>>K;
		deque<pair<ll,ll>> dq;
		// (0)이면 오름차순
		// (1)이면 내리차순
		for(ll i=0;i<K;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			// [0,a]까지는 오름차순
			// [0,b]까지는 내림차순
			while(!dq.empty()){
				ll last_num=dq.back().first;
				if(last_num<=a){
					dq.pop_back();
				}else{
					break;
				}
			}
			dq.push_back({a,0});
			while(!dq.empty()){
				ll last_num=dq.back().first;
				if(last_num<=b){
					dq.pop_back();
				}else{
					break;
				}
			}
			dq.push_back({b,1});
		}
		ll max_idx=dq.front().first;
		sort(v.begin(),v.begin()+max_idx+1);
		vector<ll> ans(n,0);
		for(ll i=max_idx+1;i<n;++i){
			ans[i]=v[i];
		}
		ll L=0, R=max_idx;
		while(!dq.empty()){
			ll cur_num=dq.front().first;
			ll cur_flag=dq.front().second;
			dq.pop_front();
			ll next_num;
			if(dq.empty()){
				next_num=-1;
			}else{
				next_num=dq.front().first;
			}
			// [cur_num,next_num+1] 까지
			if(cur_flag==0){
				// 오름차순임
				for(ll i=cur_num;i>=next_num+1;--i){
					ans[i]=v[R--];
				}
			}else{
				// 내림차순임
				for(ll i=cur_num;i>=next_num+1;--i){
					ans[i]=v[L++];
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";

	}
		

	return 0;
}