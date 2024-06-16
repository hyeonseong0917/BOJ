#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		ll ans=0;
		for(ll i=1;i<=n;++i){
			ans+=(n/i)*i;
		}
		cout<<ans;
	}

	return 0;
}