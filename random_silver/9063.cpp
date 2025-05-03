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
		int n;
        scanf("%d", &n);

        int x, y, max_x = -10001, max_y = -10000, min_x = 10001, min_y = 10001;
        while (n--) {
            scanf("%d %d", &x, &y);
            if (x > max_x) max_x = x;
            if (y > max_y) max_y = y;
            if (x < min_x) min_x = x;
            if (y < min_y) min_y = y;
        }

        printf("%d\n", (max_x - min_x) * (max_y - min_y));
        return 0;
	} 
	return 0;
}