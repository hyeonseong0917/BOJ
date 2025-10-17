#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll ans=0;
		while(b!=c){
			b=(b+1)/2;
			c=(c+1)/2;
			++ans;
		}
		cout<<ans;
	}
	return 0;
}