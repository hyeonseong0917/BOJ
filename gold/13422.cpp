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
	cin>>o;
	while(o--){
		// 1331
		ll n,m,k;
		cin>>n>>m>>k;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum[i]=(i==0)?v[i]:v[i]+psum[i-1];
		}
		if(n==m){
			if(psum[n-1]<k){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
		// m개 연속 훔칠 수 있음
		// k이상 되면 붙잡힘
		ll ans=0;
		for(ll i=0;i<m-1;++i){
			// 앞에서 i+1개, 뒤에서 m-i-1개
			// [x,n-1] n-1-x+1=n-x=m-i-1
			// x=n-m+i+1
			ll fst_sum=psum[i];
			ll sed_sum=psum[n-1]-psum[n-m+i+1]+v[n-m+i+1];
			if(fst_sum+sed_sum<k){
				++ans;
			}
		}
		ll L=0, R=m-1;
		while(R<n){
			if(psum[R]-psum[L]+v[L]<k){
				++ans;
			}
			++L;
			++R;
		}
		cout<<ans<<"\n";
	}
	return 0;
}