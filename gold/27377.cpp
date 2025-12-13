#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		ll s,t;
		cin>>s>>t;
		ll ans=0;
		while(n){
			if(n%2==1){
				ans+=s;
				--n;
			}else{
				ll c=n/2;
				ll k=c*s;
				ans+=min(k,t);
				n/=2;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}