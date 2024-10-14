#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll c,r; // c*r
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<c && x<r);
}
ll board[1000+1][1000+1];
bool check[1000+1][1000+1];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		for(ll i=0;i<1000+1;++i){
			for(ll j=0;j<1000+1;++j){
				board[i][j]=0;
			}
		}
		cin>>r>>c;
		ll k;
		cin>>k;
		if(k>r*c){
			cout<<0;
		}else{
			ll y=c-1;
			ll x=0;
			ll cnt=1;
			board[y][x]=cnt++;
			check[y][x]=1;
			ll d=0;
			while(cnt<=r*c){
				y+=dy[d];
				x+=dx[d];
				if(!isRange(y,x) || check[y][x]){
					y-=dy[d];
					x-=dx[d];
					d=(d+1)%4;
					y+=dy[d];
					x+=dx[d];
					if(!isRange(y,x) || check[y][x]){
						break;
					}
				}
				check[y][x]=1;
				board[y][x]=cnt++;
				// cout<<y<<" "<<x<<" "<<cnt<<endl;
			}
			for(ll i=0;i<c;++i){
				for(ll j=0;j<r;++j){
					// cout<<board[i][j]<<" ";
					if(board[i][j]==k){
						cout<<j+1<<" "<<c-i;
						break;
					}
				}
			}
		}

		
	}
	
	
	
	
	return 0;
}