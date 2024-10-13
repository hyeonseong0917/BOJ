#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll a,b;
		cin>>a>>b;
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll ans=0;
		ans=abs(a-b);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll cnt=1;
		for(ll i=0;i<n;++i){
			ans=min(ans,cnt+abs(v[i]-b));
		}
		cout<<ans;
	}
	return 0;
}