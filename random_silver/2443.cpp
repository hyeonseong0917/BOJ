#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin >> N;
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 1; j <= (2 * (N - i)) - 1; j++)
			cout << '*';
		cout << '\n';
	}
 
	return 0;
}
