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
		ll a=0,b=0,c=0;
		for(ll i=1;i<=n;++i){
			a+=i;
			c+=i*i*i;
		}
		cout<<a<<"\n";
		cout<<a*a<<"\n";
		cout<<c;
	}
} 