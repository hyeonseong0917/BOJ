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
		ll n;
        cin>>n;
        for(ll i=3;i<=n;++i){
            cout<<i<<" ";
        }
        cout<<1<<" "<<2;
	} 
	return 0;
}