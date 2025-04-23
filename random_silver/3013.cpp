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
		double PI=3.1415926535897932;
		double r;
		cin >> r;

		cout << fixed;
		cout.precision(6);
		cout << r * r*PI << "\n" << 2 * r*r << "\n";
	}
} 