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
		// n=6
		// n/2=k=3
		// 4 1 5 2 6 3

		// n=8
		// 5 1 6 2 7 3 8 4
		ll a=n/2+1;
		ll b=1;
		for(ll i=0;i<n;++i){
			if(i%2==0){
				cout<<a<<" ";
				++a;
			}else{
				cout<<b<<" ";
				++b;
			}
		}

	} 
	return 0;
}