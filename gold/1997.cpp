#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

const int MAX=100+1;
char board[MAX*2][MAX*2];
char tmp_board[MAX][MAX];
int N,W,B;
vector<vector<string>> puzzle;
vector<int> ans;
// N은 조각 개수, W는 폭, B는 박스 높이
void Input(){
	cin>>N>>W>>B;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]='.';
			tmp_board[i][j]='.';
		}
	}
	for(int i=0;i<N;++i){
		int H=0;
		cin>>H;
		vector<string> tmp;
		for(int j=0;j<H;++j){
			string s;
			cin>>s;
			tmp.push_back(s);
		}
		puzzle.push_back(tmp);
	}
}
void solve(){
	int idx=0;
	bool is_fit=0;
	while(1){
		if(idx==N){
			int max_height=0;
			for(int i=B-1;i>=0;--i){
				for(int j=0;j<W;++j){
					if(board[i][j]=='X'){
						++max_height;
						break;
					}
				}
			}
			ans.push_back(max_height);
			for(int i=0;i<B;++i){
				for(int j=0;j<W;++j){
					board[i][j]='.';
				}
			}
			break;
		}
		vector<string> cur_puzzle=puzzle[idx];
		int H=cur_puzzle.size();
		int cnt=0;
		bool is_fit=1;
		while(1){
			if(cnt+H>B){
				--cnt;
				break;
			}
			for(int i=cnt;i<cnt+H;++i){
				for(int j=0;j<W;++j){
					if(cur_puzzle[i-cnt][j]=='X'){
						if(board[i][j]!='.'){
							is_fit=0;
							break;
						}
					}
				}
				if(!is_fit){
					break;
				}
			}
			if(!is_fit){
				--cnt;
				break;
			}
			++cnt;

		}
		if(!is_fit && cnt<0){
			int max_height=0;
			for(int i=B-1;i>=0;--i){
				for(int j=0;j<W;++j){
					if(board[i][j]=='X'){
						++max_height;
						break;
					}
				}
			}
			ans.push_back(max_height);
			for(int i=0;i<B;++i){
				for(int j=0;j<W;++j){
					board[i][j]='.';
				}
			}
		}else{
			for(int i=cnt;i<cnt+H;++i){
				for(int j=0;j<W;++j){
					board[i][j]=cur_puzzle[i-cnt][j];
				}
			}
			++idx;
		}
	}
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<" ";
	}
}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	Input();
	solve();
	return 0;
}