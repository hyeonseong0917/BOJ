#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int board[100+1][100+1];
	for(int i=0;i<101;++i){
		for(int j=0;j<101;++j){
			board[i][j]=0;
		}
	}
	int cnt=0;
	for(int i=0;i<4;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j=a;j<c;++j){
			for(int k=b;k<d;++k){
				if(board[j][k]==0){
					board[j][k]=1;
					++cnt;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}