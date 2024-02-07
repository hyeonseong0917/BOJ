#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

const int MAX=100+1;
int board[MAX][MAX];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	for(int i=0;i<N;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j=a;j<=c;++j){
			for(int k=b;k<=d;++k){
				++board[j][k];
			}
		}
	}
	int cnt=0;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			if(board[i][j]>M){
				++cnt;
			}
		}
	}
	cout<<cnt;
	return 0;
}