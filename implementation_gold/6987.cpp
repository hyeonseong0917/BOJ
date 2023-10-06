#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int board[4+1][18+1];
vector<pair<int,pair<int,int>>> v(7,{0,{0,0}}); //승,무패
vector<pair<int,pair<int,int>>> result(7,{0,{0,0}});
vector<pair<int,int>> bracket;
bool flag=0;

void Input(){
	for(int i=0;i<4;++i){
		for(int j=0;j<3*6;++j){
			cin>>board[i][j];
		}
	}
}
// 승 무 패

void dfs(int idx){
	if(idx==bracket.size()){
		if(flag) return;
		for(int i=1;i<=6;++i){
			if(result[i].first!=v[i].first || result[i].second.first!=v[i].second.first || result[i].second.second!=v[i].second.second){
				return;
			}
		}
		// for(int i=1;i<=6;++i){
		// 	cout<<result[i].first<<" "<<result[i].second.first<<" "<<result[i].second.second<<endl;
		// }

		flag=1;
		return;
	}
	int first_team=bracket[idx].first;
	int second_team=bracket[idx].second;

	++result[first_team].first;
	++result[second_team].second.second;
	dfs(idx+1);
	--result[first_team].first;
	--result[second_team].second.second;

	
	++result[first_team].second.first;
	++result[second_team].second.first;
	dfs(idx+1);
	--result[first_team].second.first;
	--result[second_team].second.first;

	
	++result[first_team].second.second;
	++result[second_team].first;
	dfs(idx+1);
	--result[first_team].second.second;
	--result[second_team].first;
}

void solve(){
	for(int i=1;i<=5;++i){
		for(int j=i+1;j<=6;++j){
			bracket.push_back({i,j});
		}
	}
	for(int i=0;i<4;++i){
		v.clear();
		flag=0;
		result=vector<pair<int,pair<int,int>>>(7,{0,{0,0}});
		v=vector<pair<int,pair<int,int>>>(7,{0,{0,0}});

		pair<int,pair<int,int>> p={board[i][0],{0,0}};
		bool isRange=1;
		int cur_team=1;
		for(int j=1;j<18;++j){
			if(board[i][j]<0 || board[i][j]>6){
				isRange=0;
				break;
			}
			if(j%3==0){
				v[cur_team]=p;
				++cur_team;
				p={0,{0,0}};
				p.first=board[i][j];
			}else if(j%3==1){
				p.second.first=board[i][j];
			}else{
				p.second.second=board[i][j];
			}
		}
		v[cur_team]=p;
		dfs(0);		
		if(flag){
			cout<<1<<" ";
		}else{
			cout<<0<<" ";
		}
	}
}
//0906
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}