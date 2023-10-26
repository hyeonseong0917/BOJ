#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const int MAX=1000+1;

ll dp[10001][21];
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	vector<ll> A;
	
	while(t--){
		for(ll i=0;i<10001;++i){
			for(ll j=0;j<21;++j){
				dp[i][j]=0;
			}
		}
		A.clear();
		ll N;
		ll X=0;
		cin>>N;
		for(ll i=0;i<N;++i){
			ll a=0;
			cin>>a;
			A.push_back(a);
		}
		cin>>X;
		for(ll i=0;i<N;++i){
			dp[0][i]=1;
		}
		for(ll i=1;i<=X;++i){
			for(ll j=0;j<N;++j){
				if(i<A[j]){
					if(j>=1){
						dp[i][j]=dp[i][j-1];
					}
					continue;
				}
				if(j==0){
					if(i%A[j]==0){
						dp[i][j]=1;
					}
				}else{
					ll q=i/A[j];
					//A[j]를 0에서 q개만큼 사용
					for(ll k=0;k<=q;++k){
						dp[i][j]+=dp[i-k*A[j]][j-1];
					}
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<N;++i){
			ans=max(ans,dp[X][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}