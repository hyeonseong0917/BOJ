#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,b,a;
		cin>>n>>b>>a;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		// 2 4 6 8 10 12
		// a개의 선물에 대해서는 반값 할인을 받을 수 있음
		// 현재 b의 예산을 가지고 있음
		// 최대 선물을 몇 개 살 수 있는지??

		// 20 4
		// 0 1 2 3 4
		// 2 4 6 8 10

		// [idx-a+1,idx]
		// 이 구간에서 할인했는데 sum이 예산보다 크다면..
		// idx를 더 줄여야..
		// sum이 더 작음 -> 더 욕심 부려도 됨
		// idx를 더 크게 해도?
		ll L=0;
		ll R=n-1;
		ll ans=0;
		while(L<=R){
			// cout<<L<<" "<<R<<endl;
			ll idx=(L+R)/2;
			// [idx-a+1,idx] 할인
			ll c=max(0ll,idx-a+1);
			// [c,idx] 할인
			ll k=psum[c]-v[c]; // psum[c-1]
			ll sum=k+(psum[idx]-k)/2;
			if(sum>b){
				R=idx-1;
			}else{
				ans=max(ans,idx+1);
				L=idx+1;
			}
		}
		cout<<ans;
	} 
	return 0;
}