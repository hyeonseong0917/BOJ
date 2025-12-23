#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<ll> psum(n,0);
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			if(i-k>=0){
				psum[i]=psum[i-k]+v[i];
			}else{
				psum[i]=v[i];
			}
			
			// if(i%k==0){
			// 	psum[i]=psum[i-1]+v[i];
			// }else{
			// 	psum[i]=psum[i-1]+v[i]-v[i-1];
			// }
		}
		ll max_idx=-1;
		for(ll i=n-1;i>=0;--i){
			if(v[i]<=m){
				max_idx=i;
				break;
			}
		}
		if(max_idx==-1){
			cout<<0;
		}else{
			ll ans=0;
			for(ll i=max_idx;i>=0;--i){
				// i를 최대 인덱스로 했을 때 경우의 수
				ll cnt=min(k,i+1);
				ll L=0, R=i-k;
				// 현재 v[i]만큼 썼으니까 diff만큼 남음
				// diff보다 작거나 같은 최대의 인덱스를 구한다
				ll diff=m-v[i];
				ll c=-1;
				while(L<=R){
					ll mid=(L+R)/2;
					if(psum[mid]<=diff){
						c=max(c,mid);
						L=mid+1;
					}else{
						R=mid-1;
					}
				}
				cnt+=c+1;
				// cout<<i<<" "<<cnt<<endl;
				ans=max(ans,cnt);
			}
			cout<<ans;
		}
	}
	return 0;
}