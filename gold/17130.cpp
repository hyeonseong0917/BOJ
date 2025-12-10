#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dy[3]={0,1,-1};
ll dx[3]={1,1,1};
ll n,m;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
	
		cin>>n>>m;
		string board[n];
		ll y=0, x=0;
		vector<pair<ll,ll>> fin_pos;
		for(ll i=0;i<n;++i){
			cin>>board[i];
			for(ll j=0;j<m;++j){
				if(board[i][j]=='R'){
					y=i;
					x=j;
				}else if(board[i][j]=='O'){
					fin_pos.push_back({i,j});
				}
			}
		}
		ll dp[n][m][3];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				for(ll k=0;k<3;++k){
					dp[i][j][k]=-1;
				}
			}
		}
		dp[y][x][0]=0;
		dp[y][x][1]=0;
		dp[y][x][2]=0;
		for(ll j=x+1;j<m;++j){
			for(ll i=0;i<n;++i){
				// 1. i,j의 좌표값이 #이라면
				if(board[i][j]=='#') continue;
				// 2. i,j에 애초에 도달할 수 없다면
				bool flag=0;
				for(ll k=0;k<3;++k){
					if(flag) break;
					ll ny=i-dy[k];
					ll nx=j-dx[k];
					if(!isRange(ny,nx)) continue;
					for(ll p=0;p<3;++p){
						if(dp[ny][nx][p]!=-1){
							flag=1;
							break;
						}
					}
				}
				if(!flag) continue;
				// 3. i,j에 도달할 수 있음 이론상
				ll c=0;
				if(board[i][j]=='C') ++c;
				for(ll k=0;k<3;++k){
					ll ny=i-dy[k];
					ll nx=j-dx[k];
					if(!isRange(ny,nx)) continue;
					for(ll p=0;p<3;++p){
						if(dp[ny][nx][p]!=-1){
							dp[i][j][k]=max(dp[i][j][k],dp[ny][nx][p]+c);
						}
					}
				}
			}
		}
		// cout<<dp[0][4][2]<<endl;
		ll max_num=-1;
		for(ll i=0;i<fin_pos.size();++i){
			ll cy=fin_pos[i].first;
			ll cx=fin_pos[i].second;
			// cout<<cy<<" "<<cx<<endl;
			for(ll j=0;j<3;++j){
				max_num=max(max_num,dp[cy][cx][j]);
			}
		}
		if(max_num==-1){
			cout<<-1;
		}else{
			cout<<max_num;
		}
	}
	return 0;
}