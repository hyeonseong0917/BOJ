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
		// n명의 학생, n개의 기숙사
		ll n;
		cin>>n;
		// 아무도 재배정이 되지 않는 경우의 수
		// A B C D
		// 1 2 3 4
		// n!-1명만 재배정-2명만재배정-3명만재배정..
		
		// A B
		// 1 2
		// 2 1 -> 1가지

		// A B C
		// 1 2 3
		// 3 1 2
		// 2 3 1 => 2가지(n-1)*()

		// A B C D
		// 1 2 3 4
		// 4 3 1 2 => (n-1)*(dp[3]+1)
		vector<ll> dp(20+1,0);
		dp[2]=1;
		dp[3]=2;
		for(ll i=4;i<=20;++i){
			dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
		}
		cout<<dp[n]<<"\n";
		// A B C D
		// 1 2 3 4
		//       1
		// 4 3 2 1
		// 3 4 2
		// 2 3 4

		// A B C D E
		// 1 2 3 4 5

		// 2 3 4 5
		// 2 4 5 3
		// 2 5 4 3
		// 3 4 2 5
		// 3 4 5 2
		// 3 5 4 2
		// 4 3 2 5
		// 4 3 5 2
		// 4 5 2 3
		// 5 3 4 2
		// 5 4 2 3
	}
	return 0;
}