#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int dp[5000+1][5000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		int n;
		cin>>n;
		vector<int> v;
		for(ll i=0;i<n;++i){
			int a;
			cin>>a;
			v.push_back(a);
			for(ll j=0;j<n;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=2;i<=n;++i){
			for(ll j=0;j+i-1<=n-1;++j){
				// j는 시작점, i는 길이, k는 끝점
				ll k=j+i-1;
				if(v[j]==v[k]){
					dp[j][k]=dp[j+1][k-1];
				}else{
					dp[j][k]=min(1+dp[j+1][k],1+dp[j][k-1]);
				}
			}
		}
		cout<<dp[0][n-1];
		// 0 1 2 3 4 5
		// 1 2 3 2 2 1
		
		

	}
	return 0;
}