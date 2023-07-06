#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string,int> m;
char board[3][3];

void dfs(int cnt){
	bool isFinished=1;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(board[i][j]=='.'){
				isFinished=0;
			}
		}
	}
	//맵이 꽉 참
	if(isFinished==1){
		// cout<<"h";
		string cur_str="";
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				cur_str+=board[i][j];
			}
		}
		m[cur_str]=1;
		return;
	}
	vector<string> str_pick;
	for(int i=0;i<3;++i){
		string s="";
		s+=board[i][0];
		s+=board[i][1];
		s+=board[i][2];
		str_pick.push_back(s);
	}
	for(int i=0;i<3;++i){
		string s="";
		s+=board[0][i];
		s+=board[1][i];
		s+=board[2][i];
		str_pick.push_back(s);
	}
	string s="";
	s+=board[0][0];
	s+=board[1][1];
	s+=board[2][2];
	str_pick.push_back(s);
	s="";
	s+=board[0][2];
	s+=board[1][1];
	s+=board[2][0];
	str_pick.push_back(s);
	
	for(int i=0;i<str_pick.size();++i){
		if(str_pick[i]=="OOO" || str_pick[i]=="XXX"){
			isFinished=1;
			break;
		}
	}
	if(isFinished==1){
		string cur_str="";
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				cur_str+=board[i][j];
			}
		}
		m[cur_str]=1;
		return;
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(board[i][j]=='.'){
				if(cnt%2==0){
					board[i][j]='X';
					dfs(cnt+1);
					board[i][j]='.';
				}else{
					board[i][j]='O';
					dfs(cnt+1);
					board[i][j]='.';
				}
			}
		}
	}
}
void solve(){
	int idx=0;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			board[i][j]='.';
			// board[i][j]=s[s_idx++];
		}
	}
	dfs(0);
	while(1){
		string s;
		cin>>s;
		if(s=="end"){
			break;
		}
		int x_num=0, o_num=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='X'){
				++x_num;
			}
			if(s[i]=='O'){
				++o_num;
			}
		}
		// input[idx++]=s;
		if(x_num<o_num){
			cout<<"invalid"<<"\n";
			continue;
		}
		int s_idx=0;
		if(m[s]==1){
			cout<<"valid"<<"\n";
		}else{
			cout<<"invalid"<<"\n";
		}
		
	}
}


int main() {
	// your code goes here
	solve();
	
	// cout<<m[board];
	return 0;
}