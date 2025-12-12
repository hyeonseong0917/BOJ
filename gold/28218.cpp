#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,k;
string board[300+1];
ll check[300+1][300+1];
ll dy[3]={0,1,1};
ll dx[3]={1,1,0};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m>>k;
		for(ll i=0;i<n;++i){
			cin>>board[i];
			
		}
		// 0번째 사람과 1번째 사람
		// 선공이 이길 수 있는 위치를 표시하자
		ll dp[n][m];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				dp[i][j]=0;
			}
		}
		// dp[i][j]: 선공이 해당 위치에 있으면 이길 수 있음
		for(ll i=n-1;i>=0;--i){
			for(ll j=m-1;j>=0;--j){
				if(board[i][j]=='#') continue;
				if(isRange(i,j+1)){
					// i,j에 대해
					if(!dp[i][j+1] && board[i][j+1]!='#'){
						dp[i][j]=1;
						continue;
					}
				}
				if(isRange(i+1,j)){
					if(!dp[i+1][j] && board[i+1][j]!='#'){
						dp[i][j]=1;
						continue;
					}
				}
				// 대각선을 본다
				for(ll p=1;p<=k;++p){
					ll ny=i+p;
					ll nx=j+p;
					if(!isRange(ny,nx)) continue;
					if(board[ny][nx]=='#') continue;
					if(!dp[ny][nx]){
						dp[i][j]=1;
					}
				}
			}
		}
		ll qq;
		cin>>qq;
		while(qq--){
			ll y,x;
			cin>>y>>x;
			--y;
			--x;
			if(dp[y][x]){
				cout<<"First"<<"\n";
			}else{
				cout<<"Second"<<"\n";
			}
		}
	}
	return 0;
}