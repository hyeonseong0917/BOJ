#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m;
		cin>>n>>m;
		ll a,b;
		cin>>a>>b;
		vector<ll> A(n,0), B(m,0);
		for(ll i=0;i<n;++i){
			cin>>A[i];
		}
		for(ll i=0;i<m;++i){
			cin>>B[i];
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		// 1. 최소 diff을 구한다
		ll min_diff=2023101800;
		ll min_cnt=0;
		for(ll i=0;i<n;++i){
			ll cur_num=A[i];
			// 1. cur_num보다 작거나 같은 최대의 인덱스
			ll max_idx=-1;
			ll L=0, R=m-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(B[mid]<=cur_num){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			// cur_num보다 가장 크거나 같은값과 비교
			if(max_idx!=-1){
				min_diff=min(min_diff,cur_num-B[max_idx]);
			}
			// 2.cur_num보다 크거나 같은 최소의 인덱스
			L=0, R=m-1;
			ll min_idx=n;
			while(L<=R){
				ll mid=(L+R)/2;
				if(B[mid]>=cur_num){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			// cur_num보다 가장 작거나 같은 값과 비교
			if(min_idx!=n){
				min_diff=min(min_diff,B[min_idx]-cur_num);
			}
		}
		// 2. 최소 diff을 바탕으로 최소 diff 관계를 몇 개 만들 수 있는지?
		// A와 B의 관계이므로 A+diff과 A-diff이 B에 있는지 확인하면 됨
		for(ll i=0;i<n;++i){
			// fst_num이 B에 존재하는지?
			ll fst_num=A[i]-min_diff;
			ll L=0, R=m-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(B[mid]==fst_num){
					++min_cnt;
					break;
				}
				if(B[mid]<fst_num){
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			// sed_num이 B에 존재하는지?
			ll sed_num=A[i]+min_diff;
			// 만약 min_diff이 0인경우 -> sed_diff은 스킵
			if(fst_num==sed_num) continue;
			L=0, R=m-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(B[mid]==sed_num){
					++min_cnt;
					break;
				}
				if(B[mid]<sed_num){
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
		}
		min_diff+=(ll)abs(a-b);
		cout<<min_diff<<" "<<min_cnt;
	}
	return 0;
}