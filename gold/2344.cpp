#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


ll n,m;
ll board[1000+1][1000+1];
// board[i][j]
// 1이면 / 이렇게 생긴 거울
// 0이면 그냥빈칸
// 바라보는 방향, 좌표
pair<ll,pair<ll,ll>> exit_num[4000+4];
map<pair<ll,pair<ll,ll>>,ll> reverse_exit_num;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
// dp[y][x][z]: y,x에 z방향으로 가고있을 때의 도착위치
ll dp[1000+1][1000+1][4];
vector<pair<ll,pair<ll,ll>>> tmp;
ll last_num=-1;
void dfs(ll y, ll x, ll d){
	if(!isRange(y,x)){
		// cout<<y<<" "<<x<<" "<<d<<endl;
		ll rd=(d+2)%4;
		// cout<<rd<<" r"<<y-dy[d]<<" "<<x-dx[d]<<endl;
		last_num=reverse_exit_num[{rd,{y-dy[d],x-dx[d]}}];
		// cout<<last_num<<endl;
		return;
	}
	ll cd=d;
	if(board[y][x]==1){
		if(cd==0){
			cd=1;
		}else if(cd==1){
			cd=0;
		}else if(cd==2){
			cd=3;
		}else{
			cd=2;
		}
	}
	if(dp[y][x][cd]!=-1){
		last_num=dp[y][x][cd];
		return;
	}
	tmp.push_back({cd,{y,x}});
	dfs(y+dy[cd],x+dx[cd],cd);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				for(ll k=0;k<4;++k){
					dp[i][j][k]=-1;
				}
			}
		}
		// 1. exit_num[x]: x번 출구의 좌표 구하기
		ll y=0, x=0;
		ll cnt=1;
		// (1) 밑으로 내려가기
		exit_num[cnt]={1,{y,x}};
		++y;
		++cnt;
		while(1){
			if(!isRange(y,x)){
				exit_num[cnt]={0,{y-1,x}};
				++cnt;
				--y;
				++x;
				break;
			}
			exit_num[cnt]={1,{y,x}};
			++y;
			++cnt;
		}
		// (2) 오른쪽으로 가기
		exit_num[cnt]={0,{y,x}};
		++x;
		++cnt;
		while(1){
			if(!isRange(y,x)){
				exit_num[cnt]={3,{y,x-1}};
				++cnt;
				--x;
				--y;
				break;
			}
			exit_num[cnt]={0,{y,x}};
			++cnt;
			++x;
		}
		// (3) 위로 가기 
		exit_num[cnt]={3,{y,x}};
		--y;
		++cnt;
		while(1){
			if(!isRange(y,x)){
				exit_num[cnt]={2,{y+1,x}};
				++cnt;
				--x;
				++y;
				break;
			}
			exit_num[cnt]={3,{y,x}};
			++cnt;
			--y;
		}
		// (4) 왼쪽으로 가기
		exit_num[cnt]={2,{y,x}};
		--x;
		++cnt;
		while(1){
			if(!isRange(y,x)){
				break;
			}
			exit_num[cnt]={2,{y,x}};
			++cnt;
			--x;
		}
		for(ll i=1;i<cnt;++i){
			ll d=exit_num[i].first;
			ll y=exit_num[i].second.first;
			ll x=exit_num[i].second.second;
			// cout<<d<<" s"<<y<<" "<<x<<endl;
			reverse_exit_num[{d,{y,x}}]=i;
		}
		// for(ll i=1;i<cnt;++i){
		// 	cout<<i<<" "<<exit_num[i].first<<" "<<exit_num[i].second.first<<" "<<exit_num[i].second.second<<"\n";
		// }
		vector<ll> ans;
		for(ll i=1;i<cnt;++i){
			// i에서 출발
			ll d=exit_num[i].first;
			ll y=exit_num[i].second.first;
			ll x=exit_num[i].second.second;
			tmp.clear();
			// cout<<d<<" "<<y<<" "<<x<<endl;
			dfs(y,x,d);
			for(ll j=0;j<tmp.size();++j){
				ll td=tmp[j].first;
				ll ty=tmp[j].second.first;
				ll tx=tmp[j].second.second;
				dp[ty][tx][td]=last_num;
			}
			ans.push_back(last_num);
			// break;
		}
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}