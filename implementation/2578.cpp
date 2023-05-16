#include <iostream>
#include <vector>
#include <map>
using namespace std;

int board[5+1][5+1];
bool check[5+1][5+1];
vector<int> ans;
map<int,pair<int,int>> m;
void Input(){
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			cin>>board[i][j];
			m[board[i][j]]={i,j};
			check[i][j]=0;
		}
	}
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			int a=0;
			cin>>a;
			ans.push_back(a);
		}
	}
}
int is_bingo(){
	int cnt=0;
	//가로줄
	for(int i=0;i<5;++i){
		bool rflag=1;
		for(int j=0;j<5;++j){
			if(!check[i][j]){
				rflag=0;
				break;
			}
		}
		bool cflag=1;
		for(int j=0;j<5;++j){
			if(!check[j][i]){
				cflag=0;
				break;
			}
		}
		if(rflag==1){
			++cnt;
		}
		if(cflag==1){
			++cnt;
		}
	}
	//대각선
	bool flag=1;
	for(int i=0;i<5;++i){
		
		for(int j=0;j<5;++j){
			if(i!=j) continue;
			if(!check[i][j]){
				flag=0;
				break;
			}
		}
	}
	if(flag==1){
		++cnt;
	}
	bool reverse_flag=1;
	int y_idx=0;
	int	x_idx=4;
	while(1){
		if(y_idx>4){
			break;
		}
		if(!check[y_idx][x_idx]){
			reverse_flag=0;
			break;
		}
		y_idx+=1;
		x_idx-=1;
	}
	if(reverse_flag==1){
		++cnt;
	}
	return cnt;
}
void solve(){
	for(int i=0;i<25;++i){
		int cur_num=ans[i];
		int y=m[cur_num].first;
		int x=m[cur_num].second;
		check[y][x]=1;
		int cur_cnt=is_bingo();
		// cout<<cur_cnt<<endl;
		if(cur_cnt>=3){
			cout<<i+1;
			return;
		}
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}