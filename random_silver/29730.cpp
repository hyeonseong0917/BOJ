#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	cin>>o;
	while(o--){
		// A와 B가 있다. A는 n개의 정수, B는 m개의 서로 다른 양수
		ll n,m;
		cin>>n>>m;
		vector<ll> A(n,0);
		vector<ll> B(m,0);
		for(ll i=0;i<n;++i){
			cin>>A[i];
		}
		for(ll i=0;i<m;++i){
			cin>>B[i];
		}
		vector<ll> C(n,0);
		sort(B.begin(),B.end());
		for(ll i=0;i<n;++i){
			ll cur_num=A[i];
			// 1. cur_num보다 큰 최솟값
			ll L=0, R=m-1;
			ll min_idx=m-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(B[mid]>=cur_num){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			// 2. cur_num보다 작은 최댓값
			L=0, R=m-1;
			ll max_idx=0;
			while(L<=R){
				ll mid=(L+R)/2;
				if(B[mid]<=cur_num){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			ll fst_diff=(ll)abs(cur_num-B[min_idx]);
			ll sed_diff=(ll)abs(cur_num-B[max_idx]);
			if(fst_diff<sed_diff){
				C[i]=B[min_idx];
			}else{
				C[i]=B[max_idx];
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans+=C[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}