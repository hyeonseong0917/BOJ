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
		int num1, num2, total = 0, max = 0;

		for (int i = 0; i < 4; i++) {
			cin >> num1 >> num2;
			total += num2 - num1;
			if (total > max) {
				max = total;
			}
		}
		cout << max;
	}
} 