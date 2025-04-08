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
	cin>>t;
	while(t--){
		ll a, b, result = 1;
        cin >> a >> b;

        for (ll j = 0; j < b; j++) 
        {
            result = (result * a) % 10;
        }

        if (result == 0) 
        {
            cout << 10 << endl;
        }
        else 
        {
            cout << result << endl;
        }
		

	} 
	return 0;
}