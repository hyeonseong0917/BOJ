#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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
		vector<ll> v;
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll c;
			cin>>c;
			for(ll j=0;j<c;++j){
				ll cur_num;
				cin>>cur_num;
				if(j==0 || j==c-1){
					v.push_back(cur_num);
				}
			}
			// cout<<i<<" "<<sum<<endl;
		}
		sort(v.begin(),v.end());
		ll vs=v.size();
		vector<ll> l_dp(vs,0),r_dp(vs,0);
		l_dp[0]=v[0];
		for(ll i=1;i<vs;++i){
			l_dp[i]=l_dp[i-1]+v[i];
		}
		r_dp[vs-1]=v[vs-1];
		for(ll i=vs-2;i>=0;--i){
			r_dp[i]=r_dp[i+1]+v[i];
		}
		// l_dp[x]: x인덱스까지의 psum
		// r_dp[x]: x인덱스부터 끝까지의 psum
		ll fin_dist=2023101800;
		for(ll i=1;i<=m;++i){
			// i를 출입구로 설정했을 때
			// 1. i보다 작거나 같은 최대의 인덱스를 v에서 찾으면?
			ll idx=-2023101800;
			ll cur_dist=0;
			ll L=0, R=vs-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<=i){
					idx=max(idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(idx==-2023101800){
				// i보다 작은거 없음.. 다 i보다 큼
				cur_dist=r_dp[0]-i*vs;
			}else{
				// [0,idx]는 더 작음, [idx+1,vs-1]은 더 큼
				ll left_dist=(l_dp[idx]-(idx+1)*i)*-1;

				ll right_dist=0;
				if(idx+1<vs){
					right_dist=(r_dp[idx+1]-(vs-1-idx)*i);
				}
				cur_dist=left_dist+right_dist;
				// cout<<i<<" "<<left_dist<<" "<<right_dist<<endl;
			}
			// cout<<i<<" "<<cur_dist<<endl;
			if(fin_dist>cur_dist){
				fin_dist=cur_dist;
				ans=i;
			}
		}
		ans=v[n-1];
		cout<<ans;
	}
	return 0;
}