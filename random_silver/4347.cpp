#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


// x.000.xxx
string init_board;
map<string,int> m;
bool isWinOrLose(string board){
	
	for(int j=0;j<3;++j){
		int i=j*3;
		if(board[i]==board[i+1] && board[i+1]==board[i+2] && (board[i]=='X' || board[i]=='O')){
			return 1;
		}	
	}
	for(int j=0;j<3;++j){
		if(board[j]==board[j+3] && board[j+3]==board[j+6] && (board[j]=='X' || board[j]=='O')){
			return 1;
		}	
	}
	if(board[0]==board[4] && board[4]==board[8] && (board[0]=='X' || board[0]=='O')){
		return 1;
	}
	if(board[2]==board[4] && board[4]==board[6] && (board[2]=='X' || board[2]=='O')){
		return 1;
	}
	return 0;
}
bool visited[9+1];
void dfs(int turn_cnt, string cur_board, bool init){
	// 현재 board가 승패가 났는지?
	// cout<<cur_board<<"\n";
	m[cur_board]=1;
	if(isWinOrLose(cur_board) && init){
		return;
	}
	// 현재 board가 꽉 찼는지?
	if(turn_cnt==9 && init){
		return;
	}
	for(int i=0;i<9;++i){
		//i번째에 turn_cnt에 해당하는 돌을 넣기
		if(!visited[i] && cur_board[i]=='.'){
			visited[i]=1;
			if(turn_cnt%2==0){
				cur_board[i]='X';
			}else{
				cur_board[i]='O';
			}
			dfs(turn_cnt+1, cur_board, 1);
			visited[i]=0;
			cur_board[i]='.';
		}
	}
	
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	init_board=".........";
	for(int i=0;i<10;++i){
		visited[i]=0;
	}
	dfs(0,init_board,0);
	while(N--){
		string ans_board="";
		for(int i=0;i<3;++i){
			string tmp;
			cin>>tmp;
			ans_board+=tmp;
		}
		// cout<<ans_board<<endl;
		if(m[ans_board]){
			cout<<"yes"<<"\n";
		}else{
			cout<<"no"<<"\n";	
		}
		
	}
	return 0;
}