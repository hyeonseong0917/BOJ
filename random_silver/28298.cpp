#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
ll ans=0;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		string board[n+1];
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		for(ll i=0;i<k;++i){
			for(ll j=0;j<k;++j){
				// i,j와 i,j+k, i,j+2k...i+xk,j+xk
				ll y=i, x=j;
				vector<ll> v(26,0);
				while(1){
					if(y>=n) break;
					if(x>=m){
						x=j;
						y+=k;
					}else{
						++v[board[y][x]-'A'];
						x+=k;
					}
				
				}
				ll max_num=-1;
				ll max_idx=-1;
				for(ll p=0;p<26;++p){
					if(v[p]>max_num){
						max_num=v[p];
						max_idx=p;
					}
				}
				char c='A'+max_idx;
				y=i, x=j;
				while(1){
					if(y>=n) break;
					if(x>=m){
						x=j;
						y+=k;
					}else{
						if(board[y][x]!=c){
							board[y][x]=c;
							++ans;
						}				
						x+=k;
					}
				}
			}
		}
		cout<<ans<<"\n";
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cout<<board[i][j];
			}cout<<"\n";
		}

	}
	

	

	return 0;
}