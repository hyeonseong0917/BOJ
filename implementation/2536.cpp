#include <iostream>
using namespace std;

const int MAX=100+1;
int main() {
	// your code goes here
	int board[MAX][MAX];
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	int n=0;
	cin>>n;
	int cnt=0;
	while(n--){
		int x,y=0;
		cin>>x>>y;
		for(int i=y;i<y+10;++i){
			for(int j=x;j<x+10;++j){
				if(board[i][j]==0){
					++cnt;				
				}
				++board[i][j];
			}
		}
	}
	cout<<cnt;
	// int cnt=0;
	// for(int i=0;i<MAX;++i){
	// 	for(int j=0;j<MAX;++j){
	// 		if(board[i][j])
	// 	}
	// }
	return 0;
}