#include <iostream>
using namespace std;

const int MAX=100+1;
char board[MAX][MAX];
int N=0;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
}
void solve(){
	int first_cnt=0, second_cnt=0;
	for(int i=0;i<N;++i){
		int max_continue=0;
		for(int j=0;j<N;++j){
			if(board[i][j]=='.'){
				++max_continue;
			}else{
				if(max_continue>=2){
					++first_cnt;
				}
				max_continue=0;
			}
		}
		if(max_continue>=2){
			++first_cnt;
		}
	}
	cout<<first_cnt<<" ";
	for(int i=0;i<N;++i){
		int max_continue=0;
		for(int j=0;j<N;++j){
			if(board[j][i]=='.'){
				++max_continue;
			}else{
				if(max_continue>=2){
					++second_cnt;
				}
				max_continue=0;
			}
		}
		if(max_continue>=2){
			++second_cnt;
		}
	}
	cout<<second_cnt;
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}