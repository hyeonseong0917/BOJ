#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll h, w, n, y, x,t;
		cin>>t;
		for (ll i = 0; i < t; ++i) {
			cin>>h>>w>>n;
			x = n / h + 1;
			y = n % h;

			if (y == 0) {
				y = h;
				x -= 1;
			}
			cout<<y*100+x<<"\n";
		}
	}

	return 0;
}