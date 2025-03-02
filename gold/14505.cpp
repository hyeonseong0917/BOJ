#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll dp[30+1][30+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		// 1503
		// 문자열의 부분수열 중 팰린드롬의 개수
		// dp[idx][len]: idx인덱스까지 봤을 때
		// 길이 len인 팰린드롬의 개수?
		// dp[idx][len]=dp[idx-1][len]+(idx번째 문자를 추가함으로써)
		// 새로 생기는 팰린드롬의 개수

		// abbcbba
		string s;
		cin>>s;
		ll n=s.size();
		for(ll i=0;i<=30;++i){
			for(ll j=0;j<=30;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=0;i<n;++i){
			dp[i][i]=1;
		}
		// dp[i][j]: [i,j]의 원소로 이루어진 부분수열 중
		// 팰린드롬의 개수
		// dp[i][j]=dp[i][j-1]+[i,j-1]에서 s[j]와 같은 문자 있다면
		// +=(1+dp[k+1][j-1])
		for(ll i=2;i<=n;++i){
			// i는 길이
			for(ll j=0;i+j<=n;++j){
				// j와 j+i-1
				// [j,j+i-1] 사이의 부분 문자열 중중
				// 팰린드롬 개수를 구한다
				// dp[L][R]=dp[]
				ll L=j;
				ll R=j+i-1;
				dp[L][R]+=dp[L][R-1]+1;
				for(ll k=L;k<R;++k){
					if(s[k]==s[R]){
						++dp[L][R];
						dp[L][R]+=dp[k+1][R-1];
					}
				}
			}
		}
		cout<<dp[0][n-1];
	}

	return 0;
}