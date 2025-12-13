#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// 사탕 M개를 담은 박스
		// N명의 친구들에게 나눠주고 싶음
		// 분노의 합을 최소화하고싶음
		ll M,n;
		cin>>M>>n;
		// __int128 mod = (__int128)1 << 64; // OK
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> psum(n,0);
		sort(v.begin(),v.end());
		psum[n-1]=v[n-1];
		for(ll i=n-2;i>=0;--i){
			psum[i]=psum[i+1]+v[i];
		}
		ll L=1, R=v[n-1];
		ll max_num=R;
		// max_num의 최솟값을 구한다
		while(L<=R){
			ll mid=(L+R)/2;
			// mid를 최댓값으로 가정했을 때
			// mid보다 크거나 같은 최소의 인덱스는?
			ll l=0, r=n-1;
			ll min_idx=r;
			while(l<=r){
				ll m=(l+r)/2;
				if(v[m]>=mid){
					min_idx=min(min_idx,m);
					r=m-1;
				}else{
					l=m+1;
				}
			}
			// cout<<min_idx<<endl;
			// k: mid보다 크거나 같은 값의 개수
			// 최댓값을 mid로 설정한 상태
			ll k=n-min_idx;
			ll diff=psum[min_idx]-k*mid;
			// M: 내가 가진 사탕의 개수
			// diff: 최소로 필요한 개수?
			if(M<diff){
				L=mid+1;
			}else{
				// [2,3,4,5]
				// [1,1,1,1]
				if(k-1>=M-diff){
					max_num=min(max_num,mid);
				}
				R=mid-1;
			}
			// cout<<min_idx<<endl;
		}
		// cout<<max_num<<"\n";
		ll cur_sum=0;
		for(ll i=n-1;i>=0;--i){
			if(v[i]>max_num){
				cur_sum+=v[i]-max_num;
				v[i]=max_num;
			}
		}
		M-=cur_sum;
		for(ll i=n-1;i>=0;--i){
			if(M){
				--v[i];
				--M;
			}
		}
		unsigned long long ans=0;
		for(ll i=0;i<v.size();++i){
			unsigned long long c = (unsigned long long)v[i];
			ans += c * c;  // 자동으로 2^64 모듈로 연산됨
		}
		// cout<<"\n";
		cout<<ans;

	}
	return 0;
}