#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// 1334
		// 대표 자연수?
		// 주여진 자연수들과의 차이의 합을 가장 작게 하는 자연수
		// 4,3,2,2,10,10
		// 
		ll n;
		cin>>n;
		vector<ll> v(n,0),psum(n,0),sq_psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<n;++i){
			psum[i]=(i==0)?v[i]:psum[i-1]+v[i];
			sq_psum[i]=(i==0)?v[i]*v[i]:sq_psum[i-1]+v[i]*v[i];	
		}
		
		
		// 0 1 2 3 4 5
		// 2 2 3 4 10 10
		ll INF=50000000000;
		ll fst_num=INF;
		ll fst_sum=INF;
		ll sed_num=INF*10000;
		ll sed_sum=INF*10000;
		// 2 2 3 4 10 10
		// 5 5 5 5 5 5
		// 5^2*4+제곱psum[idx]-2*psum[idx]*i

		for(ll i=1;i<=10000;++i){
			// i보다 작은 수들의 합, i보다 작은 수들의 개수
			// cur_num+=개수*i-합
			// i보다 작은 최대의 인덱스 idx를 구하기
			ll cur_sum=0;
			ll sq_sum=0;
			ll L=0, R=n-1;
			ll idx=-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<i){
					idx=max(mid,idx);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(idx!=-1){
				cur_sum+=i*(idx+1)-psum[idx];
				// sq_sum+=i*i*(idx+1)+sq_psum[idx]-2*psum[idx]*i;
			}
			// i보다 큰 최소의 인덱스 idx를 구하기
			L=0, R=n-1;
			idx=INF;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]>i){
					idx=min(idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			// 2 2 3 4 10 10
			// 5 5 5 5 5 5
			// 5^2*4+제곱psum[idx]-2*psum[idx]*i
			if(idx!=INF){
				cur_sum+=psum[n-1]-psum[idx]+v[idx]-i*(n-idx);
				// sq_sum+=sq_psum[n-1]-sq_psum[idx]+v[idx]*v[idx]+i*i*(n-idx)-2*(psum[n-1]-psum[idx]+v[idx])*i;
			}
			if(cur_sum<fst_sum){
				fst_num=i;
				fst_sum=cur_sum;
			}
			sq_sum=sq_psum[n-1]+i*i*n-2*psum[n-1]*i;
			if(sed_sum>sq_sum){
				sed_num=i;
				sed_sum=sq_sum;
			}
		}
		cout<<fst_num<<" "<<sed_num;
		
	}	
	return 0;
}