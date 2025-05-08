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
        ll a=0, b=0;
        for(ll i=0;i<n;++i){
            ll c;
            cin>>c;
            a+=abs(c);
        }
        for(ll i=0;i<n;++i){
            ll c;
            cin>>c;
            b+=abs(c)*-1;
        }
        cout<<a-b;
        
        return 0;
	} 
	return 0;
}