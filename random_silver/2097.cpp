#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=1;
	while(t--){
		ll n;
		cin>>n;
		if(n<=4){
			cout<<4;
		}else{
			ll ans=1222232421;
			for(ll i=2;i<=sqrt(n);++i){
				ll q=n/i;
				ll m=n%i;
				ll cur_num=(i-1)*2+(q-1)*2;
				if(m){
					cur_num+=2;
				}
				ans=min(ans,cur_num);
			}
			cout<<ans;
		}
	}
	return 0;
}