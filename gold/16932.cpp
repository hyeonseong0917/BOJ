#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll n,m;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
ll board[1000+1][1000+1];
ll check[1000+1][1000+1];
ll visited[1000+1][1000+1];
ll cnt=0;
ll p_cnt=0;

void dfs(ll y, ll x, ll cur_num){
	for(ll i=0;i<4;++i){
		ll ny=y+dy[i];
		ll nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(visited[ny][nx]) continue;
		if(!board[ny][nx]) continue;
		++visited[ny][nx];
		check[ny][nx]=cur_num;
		++p_cnt;
		dfs(ny,nx,cur_num);
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
		bool flag=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				check[i][j]=0;
				visited[i][j]=0;
				if(!board[i][j]){
					flag=1;
				}
			}
		}
		if(!flag){
			cout<<n*m-1;
			continue;
		}
		vector<ll> dp(n*m+1,0);
		// dp[x]: check값이 x를 가지는 클러스터의 크기
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(board[i][j] && !visited[i][j]){
					visited[i][j]=1;
					++cnt;
					// i,j에 연결된 부분을 cnt로 채우기
					check[i][j]=cnt;
					p_cnt=1;
					dfs(i,j,cnt);
					dp[cnt]=p_cnt;
				}
			}
		}
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<m;++j){
		// 		cout<<check[i][j];
		// 	}cout<<endl;
		// }
		ll ans=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(!check[i][j]){
					ll cur_num=1;
					vector<ll> tmp;
					map<ll,ll> tmp_check;
					for(ll k=0;k<4;++k){
						ll ny=i+dy[k];
						ll nx=j+dx[k];
						if(!isRange(ny,nx)) continue;
						if(!check[ny][nx]) continue;
						if(tmp_check[check[ny][nx]]) continue;
						++tmp_check[check[ny][nx]];
						tmp.push_back(check[ny][nx]);
					}
					for(ll k=0;k<tmp.size();++k){
						cur_num+=dp[tmp[k]];
					}
					ans=max(ans,cur_num);
				}
			}
		}
		cout<<ans;


	}
	return 0;
}