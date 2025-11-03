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
		ll a,b,c;
		cin>>a>>b>>c;
		vector<ll> A(a,0), B(b,0), C(c,0);
		for(ll i=0;i<a;++i){
			cin>>A[i];
		}
		for(ll i=0;i<b;++i){
			cin>>B[i];
		}
		for(ll i=0;i<c;++i){
			cin>>C[i];
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		sort(C.begin(),C.end());
		ll ans=2023101800;
		for(ll i=0;i<a;++i){
			// A의 i번째를 max로 한다면?
			ll cur_num=A[i];
			for(ll j=0;j<b;++j){
				if(cur_num<B[j]) break;
				// B의 j번째를 min으로 한다면?
				// C에서 B의 j번째보다 크거나 같고, cur_num보다 작거나 같은값을 찾는다.
				// C에서 B의 j번째보다 큰 최솟값을 찾아서 cur_num과 비교
				ll L=0, R=c-1;
				ll min_num=2023101800;
				ll sed_num=B[j];
				while(L<=R){
					ll mid=(L+R)/2;
					if(C[mid]>=sed_num){
						min_num=min(min_num,C[mid]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num<=cur_num){
					ll m=(ll)abs(cur_num-sed_num);
					ans=min(ans,m);
				}
			}
			for(ll j=0;j<c;++j){
				if(cur_num<C[j]) break;
				ll L=0, R=b-1;
				ll min_num=2023101800;
				ll sed_num=C[j];
				while(L<=R){
					ll mid=(L+R)/2;
					if(B[mid]>=sed_num){
						min_num=min(min_num,B[mid]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num<=cur_num){
					ll m=(ll)abs(cur_num-sed_num);
					ans=min(ans,m);
				}
			}
		}
		// cout<<ans<<"\n";
		for(ll i=0;i<b;++i){
			ll cur_num=B[i];
			for(ll j=0;j<a;++j){
				if(cur_num<A[j]) break;
				ll L=0, R=c-1;
				ll min_num=2023101800;
				ll sed_num=A[j];
				// sed_num보다 크거나 같은 최솟값
				while(L<=R){
					ll mid=(L+R)/2;
					if(C[mid]>=sed_num){
						min_num=min(min_num,C[mid]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num<=cur_num){
					ll m=(ll)abs(cur_num-sed_num);
					ans=min(ans,m);
				}
				// cout<<i<<" "<<j<<" "<<ans<<endl;
			}
			// cout<<i<<" "<<ans<<endl;
			for(ll j=0;j<c;++j){
				if(cur_num<C[j]) break;
				ll L=0, R=a-1;
				ll min_num=2023101800;
				ll sed_num=C[j];
				while(L<=R){
					ll mid=(L+R)/2;
					if(A[mid]>=sed_num){
						min_num=min(min_num,A[mid]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num<=cur_num){
					ll m=(ll)abs(cur_num-sed_num);
					ans=min(ans,m);
				}
			}
			// cout<<i<<" "<<ans<<"\n";
		}
		// cout<<ans<<"\n";
		for(ll i=0;i<c;++i){
			ll cur_num=C[i];
			for(ll j=0;j<a;++j){
				if(cur_num<A[j]) break;
				ll L=0, R=b-1;
				ll min_num=2023101800;
				ll sed_num=A[j];
				while(L<=R){
					ll mid=(L+R)/2;
					if(B[mid]>=sed_num){
						min_num=min(min_num,B[mid]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num<=cur_num){
					ll m=(ll)abs(cur_num-sed_num);
					ans=min(ans,m);
				}
			}
			for(ll j=0;j<b;++j){
				if(cur_num<B[j]) break;
				ll L=0, R=a-1;
				ll min_num=2023101800;
				ll sed_num=B[j];
				while(L<=R){
					ll mid=(L+R)/2;
					if(A[mid]>=sed_num){
						min_num=min(min_num,A[mid]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num<=cur_num){
					ll m=(ll)abs(cur_num-sed_num);
					ans=min(ans,m);
				}
			}
		}
		// cout<<ans<<"\n";
		cout<<ans;
	}
	return 0;
}