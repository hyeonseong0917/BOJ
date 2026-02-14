#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,q;
ll board[2000+1][2000+1];
ll psum[2000+1][2000+1];
ll tmp[2000+1][2000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		for(ll i=0;i<=2000;++i){
			for(ll j=0;j<=2000;++j){
				board[i][j]=0;
				psum[i][j]=0;
				tmp[i][j]=0;
			}
		}
		cin>>n>>m>>q;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=m;++j){
				cin>>board[i][j];
			}
		}
		for(ll i=1;i<=m;++i){
			for(ll j=1;j<=n;++j){
				tmp[j][i]=(j==1)?board[j][i]:tmp[j-1][i]+board[j][i];
			}
		}
		for(ll i=1;i<=m;++i){
			psum[1][i]=board[1][i];
		}
		for(ll i=2;i<=n;++i){
			psum[i][1]=psum[i-1][1]+board[i][1];
		}
		for(ll i=2;i<=m;++i){
			for(ll j=2;j<=n;++j){	
				psum[j][i]=psum[j-1][i-1]+tmp[j][i];
			}
		}
		while(q--){
			ll a,b;
			cin>>a>>b;
			cout<<psum[a][b]<<"\n";
		}
	}
	return 0;
}