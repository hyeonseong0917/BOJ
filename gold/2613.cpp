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
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		ll L=-1;
		ll R=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			R+=v[i];
			L=max(L,v[i]);
		}
		ll ans=2023101800;
		vector<ll> ans_save;
		while(L<=R){
			ll mid=(L+R)/2;
			// cout<<L<<" "<<R<<" "<<mid<<" "<<ans<<endl;
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(v[i]>mid){
					flag=1;
					break;
				}
			}
			if(flag){
				R=mid-1;
				continue;
			}
			// mid 이하로 구간 나누었을 때, 
			// m개 이하의 구간으로 나누기 가능?
			ll seg_cnt=0;
			ll seg_sum=0;
			vector<ll> tmp;
			for(ll i=0;i<n;++i){
				// if(mid==17){
				// 	cout<<i<<" "<<seg_cnt<<endl;
				// }
				if(seg_sum+v[i]<=mid){
					seg_sum+=v[i];
					++seg_cnt;
				}else{
					
					tmp.push_back(seg_cnt);
					seg_cnt=1;
					seg_sum=v[i];
				}
			}
			tmp.push_back(seg_cnt);
			ll ts=tmp.size();
			if(ts<=m){
				ans=min(ans,mid);
				ans_save.clear();
				ans_save=tmp;
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<ans<<"\n";
		ll idx=0;
		bool is_pass=0;
		// 4 2 2
		// 2 2 2 2
		for(ll i=0;i<ans_save.size();++i){
			while(ans_save.size()<m && ans_save[i]>1){
				ans_save.insert(ans_save.begin()+i+1,ans_save[i]/2);
				ans_save[i]-=ans_save[i]/2;
			}
		}
		for(ll i=0;i<ans_save.size();++i){
			cout<<ans_save[i]<<" ";
		}
		

	}
	return 0;
}