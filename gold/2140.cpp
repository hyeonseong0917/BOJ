#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dy[8]={-1,-1,-1,0,1,1,1,0};
ll dx[8]={-1,0,1,1,1,0,-1,-1};
ll n;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}
const int MAX=100+1;
string board[MAX];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		if(n<4){
			if(n<=2){
				cout<<0;
			}
			if(n==3){
				if(board[0][0]=='1'){
					cout<<1;
				}else{
					cout<<0;
				}
			}
			break;
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if(board[i][j]=='#' || board[i][j]=='*') continue;
				if(board[i][j]=='0') continue;
				for(ll k=0;k<8;++k){
					ll ny=i+dy[k];
					ll nx=j+dx[k];
					if(!isRange(ny,nx) || board[ny][nx]!='#') continue;
					// ny,nx에 지뢰를 놓을 수 있는지?
					bool flag=0;
					for(ll p=0;p<8;++p){
						ll nny=ny+dy[p];
						ll nnx=nx+dx[p];
						if(!isRange(nny,nnx) || board[nny][nnx]=='#') continue;
						if(board[nny][nnx]=='*') continue;
						if(board[nny][nnx]=='0'){
							flag=1;
							break;
						}
					}
					if(!flag){
						// 지뢰 o
						board[ny][nx]='*';
						for(ll p=0;p<8;++p){
							ll nny=ny+dy[p];
							ll nnx=nx+dx[p];
							if(!isRange(nny,nnx) || board[nny][nnx]=='#') continue;
							if(board[nny][nnx]=='0' || board[nny][nnx]=='*') continue;
							int a=(board[nny][nnx]-'0')-1;
							board[nny][nnx]=(a+'0');
						}
						// for(ll p=0;p<n;++p){
						// 	for(ll q=0;q<n;++q){
						// 		cout<<board[p][q]<<" ";
						// 	}cout<<endl;
						// }cout<<endl;
						break;
					}
				}
			}
		}
		ll cnt=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if(board[i][j]=='*'){
					++cnt;
				}
			}
		}
		cnt+=(n-4)*(n-4);
		cout<<cnt;
		
	}
	return 0;
}