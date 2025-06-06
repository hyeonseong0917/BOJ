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
		ll ans=0;
		while(n%5){
			n-=3;
			++ans;
		}
		if(n<0){
			cout<<-1;
		}else{
			cout<<ans+n/5;
		}
	} 
	return 0;
}