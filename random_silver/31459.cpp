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
bool check[50+2][50+2];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll X,Y,x,y;
		cin>>X>>Y>>x>>y;
		if(Y==1 || X==1){
			ll ans=max(X,Y);
			cout<<ans<<"\n";
			continue;
		}
		for(ll i=0;i<=Y;++i){
			for(ll j=0;j<=X;++j){
				check[i][j]=0;
			}
		}
		// x . x .
		// . . x .
		// x x x .
		// . . . .
		for(ll i=1;i<=Y;++i){
			for(ll j=1;j<=X;++j){
				if(check[i][j]) continue;
				if(i+y>Y || j+x>X) continue;
				check[i+y][j+x]=1;
			}
		}
		ll ans=0;
		for(ll i=1;i<=Y;++i){
			for(ll j=1;j<=X;++j){
				if(!check[i][j]){
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}