#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N=0;
const int MAX=50+1;
int board[MAX][10+1];
map<vector<int>,int> m; 
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=1;j<=9;++j){
			cin>>board[i][j];
		}
	}
}
int game(vector<int> pick){
	int cnt=0;
	// vector<int> pick={5,6,7,1,4,3,2,8,9};
	// vector<int> pick={5,6,7,1,4,3,2,8,9};
	vector<pair<int,int>> base; //{베이스 번호, 선수 번호}
	int curPlayer=0;
	// cout<<board[0][1]<<endl;
	for(int i=0;i<N;++i){
		base.clear();
		int curOut=0;
		vector<pair<int,int>> new_base;
		while(1){
			// cout<<curPlayer<<" "<<pick[curPlayer]<<" "<<board[i][pick[curPlayer]]<<endl;
			int curNum=board[i][pick[curPlayer]];
			++curPlayer;
			
			if(curPlayer==9){
				curPlayer=0;
			}
			if(curNum==0){
				++curOut;
			}else{
				// cout<<curNum<<" "<<curOut<<endl;
				new_base.clear();
				base.push_back({0,pick[curPlayer]});
				for(int j=0;j<base.size();++j){
					base[j].first+=curNum;
					if(base[j].first>=4){
						++cnt;
					}else{
						new_base.push_back(base[j]);
					}
				}
				base.clear();
				base=new_base;
			}
			
			if(curOut==3){
				break;
			}
		}
	}
	return cnt;
	
}
int maxNum=-122232421;
// vector<int> player_order;
bool visited[10+1];
void dfs(int cnt, vector<int> player_order){
	if(cnt==9){
		if(m[player_order]==0){
			m[player_order]=1;
			maxNum=max(maxNum,game(player_order));
		}
		
		
		return;
	}
	if(cnt==3){
		player_order.push_back(1);
		visited[1]=1;
		
	}
	for(int i=1;i<=9;++i){
		if(!visited[i] && i!=1){
			visited[i]=1;
			player_order.push_back(i);
			if(cnt==3){
				dfs(cnt+2,player_order);
			}else{
				dfs(cnt+1,player_order);	
			}
			player_order.pop_back();
			visited[i]=0;
		}
	}
}
void solve(){
	// visited[3]=1;
	vector<int> player_order;
	dfs(0,player_order);
}

int main() {
	// your code goes here
	Input();
	solve();
	cout<<maxNum;
	// cout<<game();
	return 0;
}