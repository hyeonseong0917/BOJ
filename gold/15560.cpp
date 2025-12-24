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
		ll N,Q,U,V;
		cin>>N>>Q>>U>>V;
		vector<ll> v(N,0);
		for(ll i=0;i<N;++i){
			cin>>v[i];
		}
		while(Q--){
			ll C,A,B;
			cin>>C>>A>>B;
			if(C==0){
				// 10000
				--A;
				vector<ll> dp(N,-2023101800);
				// [A,B]에서 해당 값의 최댓값?
				dp[A]=U*v[A];
				ll ans=dp[A];
				for(ll i=A+1;i<B;++i){
					dp[i]=max(U*v[i],dp[i-1]+U*v[i]+V);
					ans=max(ans,dp[i]);
				}
				cout<<ans<<"\n";
			}else{
				v[A-1]=B;
			}
		}
	}
	return 0;
}