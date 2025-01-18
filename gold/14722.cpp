#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

ll dp[1000+1][1000+1][3];
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll board[1000+1][1000+1];
ll n;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 처음에 딸기우유
		// 딸기우유->초코우유->바나나우유->딸기우유
		// 0: 딸기 , 1: 쵸코, 2: 바나나
		// dp[y][x][z]=max(dp[y-1][x][p],dp[y][x-1][p])+1
		// vs dp[ny][nx][pre_num 아닌 것들](안마시는 경우)
		// z=0,1,2
		cin>>n;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				cin>>board[i][j];
				for(ll k=0;k<3;++k){
					dp[i][j][k]=0;
				}
			}
		}
		bool is_eat_straw=0;
		if(board[0][0]==0){
			dp[0][0][board[0][0]]=1;	
			is_eat_straw=1;
		}
		
		for(ll y=0;y<n;++y){
			for(ll x=0;x<n;++x){
				if(y==0 && x==0) continue;
				// dp[y][x][z]: y,x에 왔을 때, 마지막으로 마신게 z였을 때 최대개수
				// dp[y][x][cur_num]=dp[y-1][x][cur_num],dp[y][x-1][cur_num]
				// dp[y][x][cur_num]=dp[y-1][x][pre_num],dp[y][x-1][pre_num]
				// dp[y][x][k] -> cur_num아닌 k는
				// dp[y][x]
				ll cur_num=board[y][x];
				if(cur_num!=0 && !is_eat_straw) continue;
				is_eat_straw=1;
				if(cur_num==0){
					dp[y][x][cur_num]=max(dp[y][x][cur_num],(ll)1);
				}
				ll pre_num=(cur_num+2)%3;
				if(y>0 && (is_eat_straw || cur_num==0)){
					if(dp[y-1][x][pre_num]){
						dp[y][x][cur_num]=max(dp[y][x][cur_num],dp[y-1][x][pre_num]+1);
					}
					
				}
				if(x>0 && (is_eat_straw || cur_num==0)){
					if(dp[y][x-1][pre_num]){
						dp[y][x][cur_num]=max(dp[y][x][cur_num],dp[y][x-1][pre_num]+1);
					}
				}
				// if(y==0 && x==1){
				// 	cout<<cur_num<<" "<<pre_num<<endl;
				// 	cout<<"YE"<<dp[y][x][2]<<endl;
				// }
				for(ll k=0;k<3;++k){
					if(y>0){
						dp[y][x][k]=max(dp[y][x][k],dp[y-1][x][k]);
					}
					if(x>0){
						dp[y][x][k]=max(dp[y][x][k],dp[y][x-1][k]);
					}
				}

			}
		}
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<n;++j){
		// 		for(ll k=0;k<3;++k){
		// 			cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
		// 		}
		// 	}
		// }
		cout<<max(dp[n-1][n-1][0],max(dp[n-1][n-1][1],dp[n-1][n-1][2]));
	}
	return 0;
}