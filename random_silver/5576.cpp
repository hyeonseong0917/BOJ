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

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		vector<ll> a(10,0),b(10,0);
        for(ll i=0;i<10;++i){
            cin>>a[i];
        }
        for(ll i=0;i<10;++i){
            cin>>b[i];
        }
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        cout<<a[0]+a[1]+a[2]<<" "<<b[0]+b[1]+b[2];
	} 
	return 0;
}