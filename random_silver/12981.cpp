#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll r,g,b;
		cin>>r>>g>>b;
		ll ans=0;
		// 1. 모두 다른거?
		ll c=min(r,min(g,b));
		ans=c;
		r-=c;
		g-=c;
		b-=c;
		ans+=r/3;
		r%=3;
		ans+=g/3;
		g%=3;
		ans+=b/3;
		b%=3;
		while(r & g){
			--r;
			--g;
			++ans;
		}
		while(r && b){
			--r;
			--b;
			++ans;
		}
		while(g && b){
			--g;
			--b;
			++ans;
		}
		while(r>0){
			++ans;
			r-=3;
		}
		while(g>0){
			++ans;
			g-=3;
		}
		while(b>0){
			++ans;
			b-=3;
		}
		cout<<ans;
	}
	return 0;
}