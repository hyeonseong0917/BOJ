#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
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
		//입력
		int n,m,k;
		cin >> n >> m >> k; //n명, m개 장르, 본선진출인원 k
		vector<float>arr(n, 0.0);
		
		int person; float ability;
		for (int i = 0; i < m; i++) { //장르
			for (int j = 0; j < n; j++) { //참가자별 능력
				cin >> person >> ability;

				//전체 장르를 통틀어, 참가자의 가장 높은 능력을 저장
				//사람 번호는 1번부터 시작하기 때문에 person-1
				arr[person - 1] = max(ability, arr[person - 1]);
			}
		}

		//문제 해결
		sort(arr.begin(), arr.end(),greater<float>()); //내림차순 정렬

		float ans = 0.0;
		for (int i = 0; i < k; i++) { 
			ans += arr[i]; //앞에서부터 k개 더하기
		}

		//결과 출력
		cout << fixed;
		cout.precision(1); //소수점 첫째짜리까지 출력
		cout << ans << '\n';
	} 
	return 0;
}