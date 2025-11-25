#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

ll n,m;
ll board[30+1][30+1];
ll result_board[30+1][30+1];
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll visited[30+1][30+1];
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}

void dfs(ll y, ll x, ll cur_num, ll origin_num){
	// cout<<y<<" "<<x<<" "<<cur_num<<endl;
	for(ll i=0;i<4;++i){
		ll ny=y+dy[i];
		ll nx=x+dx[i];
		if(!isRange(ny,nx));
		if(board[ny][nx]!=origin_num) continue;
		if(visited[ny][nx]) continue;
		visited[ny][nx]=1;
		board[ny][nx]=cur_num;
		dfs(ny,nx,cur_num,origin_num);
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>result_board[i][j];
				visited[i][j]=0;
			}
		}
		bool flag=0;
		ll cy,cx;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(board[i][j]!=result_board[i][j]){
					flag=1;
					cy=i;
					cx=j;
					break;
				}
			}
		}
		if(!flag){
			cout<<"YES";
		}else{
			visited[cy][cx]=1;
			ll tmp=board[cy][cx];
			board[cy][cx]=result_board[cy][cx];
			dfs(cy,cx,result_board[cy][cx],tmp);
			// cout<<endl;
			for(ll i=0;i<n;++i){
				for(ll j=0;j<m;++j){
					// cout<<board[i][j]<<" ";
					if(board[i][j]!=result_board[i][j]){
						flag=0;
						break;
					}
				}
			}
			if(!flag){
				cout<<"NO";
			}else{
				cout<<"YES";
			}
		}
	}
	return 0;
}