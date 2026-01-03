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

vector<pair<int,int>> check[11];
vector<int> visited(11+1,0);
int ans=0;
void dfs(int cur_num, int sum){
  if(cur_num==11){
    ans=max(ans,sum);
    return;
  }
  // cur_num번째 열에서 어떤 선수를 선택할지?
  for(int i=0;i<check[cur_num].size();++i){
    int next_num=check[cur_num][i].first;
    int next_val=check[cur_num][i].second;
    if(visited[next_num]) continue;
    visited[next_num]=1;
    dfs(cur_num+1,sum+next_val);
    visited[next_num]=0;
  }
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		int t;
		cin>>t;
		while(t--){
			ans=0;
			visited=vector<int>(11+1,0);
			for(int i=0;i<11;++i){
			check[i].clear();
			}
			vector<vector<int>> board(11,vector<int>(11,0));
			for(int i=0;i<11;++i){
			for(int j=0;j<11;++j){
				cin>>board[i][j];
			}
			}
			// i번째 선수는 j번째 능력을 가지고 있음
			// j번째 능력에 대해 모든 포지션을 채웠을 때 값의 최댓값?
			for(int i=0;i<11;++i){
			for(int j=0;j<11;++j){
				if(board[i][j]){
				// j번째 열은 어떤 숫자들을 가지고 있는지
				check[j].push_back({i,board[i][j]});
				}
			}
		}
		dfs(0,0);
		cout<<ans<<"\n";
		}
	}
	return 0;
}