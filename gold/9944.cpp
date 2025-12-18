#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll n=0,m=0;
char board[30+1][30+1];
ll ans=0;
ll empty_cnt=0;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll visited[30+1][30+1];


bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
// void dfs(ll cy, ll cx, ll cd, ll cur_empty_cnt, ll cur_change_cnt){
//     if(cur_change_cnt >= ans) return; // 가지치기

//     if(cur_empty_cnt == empty_cnt){
//         ans = min(ans, cur_change_cnt);
//         return;
//     }

//     ll y = cy;
//     ll x = cx;
//     ll d = cd;
//     ll c = cur_empty_cnt;

//     vector<pair<ll,ll>> path;

//     // 🔹 한 방향으로 끝까지 이동
//     while(true){
//         ll ny = y + dy[d];
//         ll nx = x + dx[d];
//         if(!isRange(ny,nx)) break;
//         if(visited[ny][nx]) break;
//         if(board[ny][nx] == '*') break;

//         y = ny;
//         x = nx;
//         visited[y][x] = 1;
//         path.push_back({y,x});
//         ++c;
//     }

//     // 🔴 한 칸도 못 움직였으면 이 방향은 불가능
//     if(path.empty()) return;

//     // 🔹 이동 끝난 지점에서 방향 전환
//     for(ll nd = 0; nd < 4; ++nd){
//         if(nd == d) continue;
//         dfs(y, x, nd, c, cur_change_cnt + 1);
//     }

//     // 🔹 백트래킹
//     for(auto &p : path){
//         visited[p.first][p.second] = 0;
//     }
// }


void dfs(ll cy, ll cx, ll cd, ll cur_empty_cnt, ll cur_change_cnt, ll p, ll q, ll r){
	if(empty_cnt==cur_empty_cnt){
		ans=min(ans,cur_change_cnt);
		return;
	}
	ll c=cur_empty_cnt;
	ll y=cy;
	ll x=cx;
	ll d=cd;
	vector<pair<ll,ll>> path; // 이동 경로 저장
	bool flag=0;
	while(1){
		y+=dy[d];
		x+=dx[d];
		if(!isRange(y,x)){
			y-=dy[d];
			x-=dx[d];
			break;
		}
		if(visited[y][x]){
			y-=dy[d];
			x-=dx[d];
			break;
		}
		if(board[y][x]=='*'){
			y-=dy[d];
			x-=dx[d];
			break;
		}
		flag=1;
		visited[y][x]=1;
		path.push_back({y,x}); // 경로 저장
		++c;
	}
	if(path.empty()) return;
	// 방향바꾸기
	for(ll i=0;i<4;++i){
		if(i==d) continue;
		dfs(y,x,i,c,cur_change_cnt+1,p,q,r);
	}
	// 🔥 백트래킹: 이동한 모든 칸 복원
    for(auto& p : path){
        visited[p.first][p.second] = 0;
    }

}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(cin>>n>>m){
		ans=2023101800;
		empty_cnt=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				board[i][j]='.';
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				if(board[i][j]=='.'){
					++empty_cnt;
				}
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(board[i][j]=='.'){
					// i,j에서 출발한다고 했을때
					for(ll k=0;k<4;++k){
						// k방향으로 출발
						for(ll p=0;p<n;++p){
							for(ll q=0;q<m;++q){
								visited[p][q]=0;
							}
						}
						// cout<<i<<" "<<j<<" "<<k<<" "<<"\n";
						visited[i][j]=1;
						dfs(i,j,k,1,0,i,j,k);
						// dfs(i, j, k, 1, 0);

					}
					

				}
			}
		}
		if(ans==2023101800){
			ans=-1;
		}

		cout<<"Case "<<o<<": "<<ans<<"\n";
		++o;
	}
	return 0;
}