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
		ll n;
		cin>>n;
		if(n==1){
			cout<<10;
			break;
		}
		if(n==2){
			cout<<11;
			break;
		}
		// daldidalgo
		// 1번의 daldidalgo: 8초
		// 2번: 1초 - 1복시
		// 3번: 2초 - 1복사+1복사
		// daldidalgo daldidalgo daldidalgodaldida n
		// 4번: 2초 - 1복사+2복사
		// dal dal [dal dal] [dal dal dal dal] +2
		// 5번: 3초 - 1복사+2복사+1복사
		// 6번: 3초+1초 - 1복사+1복사+3복사
		// dal dal [dal dal] [dal dal da] +1

		// 7번: 3초+1초 - 1복사+2복사+3복사
		// dal dal [dal dal] [dal dal dal da]
		// 

		// 8번: 3초+2초 - 1복사+2복사+4복사
		// dal dal [dal dal] [dal] [dal dal dal dal da]+1
		// dal dal [dal dal] [dal dal dal dal] +2
		// n/2+1

		// 9번: 5초 - 1복사+2복사+4복사+1복사
		// dal dal [dal dal] [dal] [dal dal dal dal da]+1

		// 10번
		// dal dal [dal dal] [dal dal] [dal dal dal dal dal da]+1

		// 11번
		// dal dal [dal dal] [dal dal dal dal] []
		
		// (n-sum)개+1이 필요한 상황을 만들기. n-sum+1보다 현재 cnt가 크거나 같다면 +2
		ll cnt=1;
		ll sum=1;
		ll ans=8;
		// n=8
		while(1){
			if(n-sum+1<=sum){
				ans+=2;
				break;
			}else{
				sum+=cnt;
				cnt*=2;
				++ans;
			}
		}
		cout<<ans;
	} 
	return 0;
}