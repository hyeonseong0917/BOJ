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
		int x1, y1, x2, y2, x3, y3;
		scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		
		int x, y;

		if (x1 == x2) x = x3;
		else if (x1 == x3) x = x2;
		else x = x1;

		if (y1 == y2) y = y3;
		else if (y1 == y3) y = y2;
		else y = y1;

		printf("%d %d\n", x, y);
		return 0;
	} 
	return 0;
}