#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll N;
		cin>>N;
		ll mod=987654321;
		vector<ll> K(N+1,0);
		K[0]=1;
		K[2]=1;
		for(ll i=4;i<=N;++i){
			for(ll j=2;j<=i;j+=2){
				// 1과 j가 악수
				K[i]+=(K[i-j]*K[j-2])%mod;
				K[i]%=mod;
			}
		}
		cout<<K[N];
	}

	return 0;
}