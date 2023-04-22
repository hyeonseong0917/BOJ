#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

string board[20+1];
vector<string> res;
map<string,int> m;
int R,C;
void Input(){
	cin>>R>>C;
	for(int i=0;i<R;++i){
		cin>>board[i];
	}
}
// 가로
void search_width(int h){
	string cur_str="";
	for(int i=0;i<C;++i){
		if(board[h][i]!='#'){
			cur_str+=board[h][i];
		}else{
			if(cur_str.size()>=2){
				res.push_back(cur_str);
			}
			cur_str="";
		}
	}
	if(cur_str.size()>=2){
		res.push_back(cur_str);
	}
}
//세로
void search_height(int w){
	string cur_str="";
	for(int i=0;i<R;++i){
		if(board[i][w]!='#'){
			cur_str+=board[i][w];
		}else{
			if(cur_str.size()>=2){
				res.push_back(cur_str);
			}
			cur_str="";
		}
	}
	if(cur_str.size()>=2){
		res.push_back(cur_str);
	}
}

void solve(){
	for(int i=0;i<R;++i){
		search_width(i);
	}
	for(int i=0;i<C;++i){
		search_height(i);
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	sort(res.begin(), res.end());
	cout<<res[0];
	return 0;
}