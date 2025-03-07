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
		// 0957
		// 1을 01으로, 0을 10으로 치환
		// 1 -> 01 -> 1001 -> 01101001
		//       1      1       3
		// n번째 이진수에서 연속된 0들의 그룹이 몇 개?
		// 1001011001101001
		// 01에 대해서 연속한 0이 하나 생김
		// 01은 1001로 둔갑하기때문
		// 문자열 길이는 2배가 됨
		// 2번째 단계에서 전체 문자의 길이는 2
		// 01 1개, 나머지 문자 0개
		// 3번째 단계에서 01 1개, 나머지 문자 2개
		// 4번째 단계에서 01 3개, 나머지 문자 2개
		// 5번째 단계에서 1001 3개 생기고, 나머지 문자 4개
		// 5번째 단계에서 01 5개, 나머지 문자 16-(이전단계 01개수*4)
		ll n;
		cin>>n;
		vector<ll> dp(1000+1,0);
		dp[1]=0;
		dp[2]=1;
		for(ll i=3;i<=n;++i){
			dp[i]=(ll)pow(2,i-2)-dp[i-1];
		}
		cout<<dp[n];
	}
	return 0;
}