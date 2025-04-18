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
		int c, n, cnt;
	int score[1000];
	double avg;

	scanf("%d", &c);

	for (int i = 0; i < c; ++i) {
		scanf("%d", &n);
		avg = 0.0;

		for (int j = 0; j < n; ++j) {
			scanf("%d", &score[j]);
			avg += score[j];
		}
		avg /= n;

		cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (score[j] > avg) ++cnt;
		}

		printf("%.3f%\n", 100.0 * cnt / n);
	}
	} 
	return 0;
}