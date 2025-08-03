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

ll n,m;
string board[100+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		ll ans=0;
		for(ll i=n-1;i>=0;--i){
			for(ll j=m-1;j>=0;--j){
				if(board[i][j]=='1'){
					// [0,0]~[i,j] 뒤집기
					for(ll k=0;k<=i;++k){
						for(ll p=0;p<=j;++p){
							if(board[k][p]=='1'){
								board[k][p]='0';
							}else{
								board[k][p]='1';
							}
						}
					}
					++ans;
				}
			}
		}
		cout<<ans;

	} 
	return 0;
}