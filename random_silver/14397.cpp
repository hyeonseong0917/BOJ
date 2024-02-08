#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

const int MAX=50+1;
string board[MAX];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>board[i];
	}
	int cnt=0;
	for(int i=0;i<N-1;++i){
		for(int j=0;j<M-1;++j){
			if(board[i][j]!=board[i][j+1]){
				++cnt;
			}
		}
		if(i%2==0){
			if(board[i][0]!=board[i+1][0]){
				++cnt;
			}
			for(int j=1;j<M;++j){
				if(board[i+1][j-1]!=board[i][j]){
					++cnt;
				}
				if(board[i+1][j]!=board[i][j]){
					++cnt;
				}
			}
		}else{
			if(board[i][M-1]!=board[i+1][M-1]){
				++cnt;
			}
			for(int j=0;j<M-1;++j){
				if(board[i+1][j]!=board[i][j]){
					++cnt;
				}
				if(board[i+1][j+1]=board[i][j]){
					++cnt;
				}
			}
		}
	}
	for(int j=0;j<M-1;++j){
		if(board[N-1][j]!=board[N-1][j+1]){
			++cnt;
		}
	}
	cout<<cnt;
	return 0;
}