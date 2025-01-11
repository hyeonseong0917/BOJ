#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

string board[500+1];
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll r,c;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<r && x<c);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>r>>c;
		for(ll i=0;i<r;++i){
			cin>>board[i];
		}
		bool flag=0;
		for(ll i=0;i<r;++i){
			for(ll j=0;j<c;++j){
				if(board[i][j]=='W'){
					for(ll k=0;k<4;++k){
						ll ny=i+dy[k];
						ll nx=j+dx[k];
						if(!isRange(ny,nx)) continue;
						if(board[ny][nx]=='S'){
							flag=1;
							break;
						}
					}
				}
			}
		}
		if(flag){
			cout<<0<<"\n";
		}else{
			cout<<1<<"\n";
			for(ll i=0;i<r;++i){
				for(ll j=0;j<c;++j){
					if(board[i][j]=='S'){
						for(ll k=0;k<4;++k){
							ll ny=i+dy[k];
							ll nx=j+dx[k];
							if(!isRange(ny,nx)) continue;
							if(board[ny][nx]=='.'){
								board[ny][nx]='D';
							}
						}
					}

				}
			}
			for(ll i=0;i<r;++i){
				for(ll j=0;j<c;++j){
					cout<<board[i][j];
				}cout<<"\n";
			}
		}

	}
	return 0;
}