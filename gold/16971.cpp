#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll board[1000+1][1000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
			}
		}
		// 임의의 두 행이나 두 열 교환 최대 1번 가능
		// 그 때 합의 최댓값은??
		// 9 8 7
		// 3 2 1
		// 6 5 4

		// 22 18
		// 16 12

		// 3 2 1
		// 9 8 7
		// 6 5 4

		// 1. 두 행을 교환하는 경우?
	}
	return 0;
}