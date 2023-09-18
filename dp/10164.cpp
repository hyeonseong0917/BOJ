#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

int a,b,c;

const int MAX=15+1;
ll board[MAX][MAX];
ll dp[MAX][MAX];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M,K;
	cin>>N>>M>>K;
	ll cnt=1;
	int y,x;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(cnt==K){
				y=i;
				x=j;
			}
			board[i][j]=cnt++;
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(i-1>=0){
				dp[i][j]+=dp[i-1][j];
			}
			if(j-1>=0){
				dp[i][j]+=dp[i][j-1];
			}
		}
	}
	if(K==0){
		cout<<dp[N-1][M-1];
	}else{
		
		cout<<dp[y][x]*(dp[N-1-y][M-1-x]);
	}

	return 0;
}