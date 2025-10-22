#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

string board[5];
ll min_num,cnt;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<5 && x<8);
}
void dfs(ll cur_num, ll cur_cnt){
	// 1. o가 없는경우
	bool fst_flag=0;
	ll o_cnt=0;
	for(ll i=0;i<5;++i){
		for(ll j=0;j<8;++j){
			if(board[i][j]=='o'){
				++o_cnt;
				fst_flag=1;
			}
		}
	}
	// 2. o가 움직일 수 없는경우
	bool flag=0;
	for(ll i=0;i<5;++i){
		if(flag) break;
		for(ll j=0;j<8;++j){
			if(flag) break;
			if(board[i][j]=='o'){
				for(ll k=0;k<4;++k){
					if(flag) break;
					ll ny=i+dy[k];
					ll nx=j+dx[k];
					if(!isRange(ny,nx)) continue;
					if(board[ny][nx]=='o'){
						// k번째 방향으로 움직일 수 있는 곳이 있는지?
						if(!isRange(ny+dy[k],nx+dx[k])) continue;
						if(board[ny+dy[k]][nx+dx[k]]=='.'){
							flag=1;
							break;
						}
					}
				}
			}
		}
	}
	if(!fst_flag || flag){
		if(!o_cnt){
			if(min_num>o_cnt){
				min_num=o_cnt;
				cnt=cur_cnt;
			}
			return;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		for(ll i=0;i<5;++i){
			cin>>board[i];
		}
		min_num=2023101800;
		cnt=0;
		dfs();
	}
	return 0;
}