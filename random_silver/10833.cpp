#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		ll sum=0;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			sum+=b%a;
		}
		cout<<sum;
	}
	return 0;
}