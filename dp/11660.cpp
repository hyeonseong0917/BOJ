#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


int N,M;
const int MAX=1024+1;
ll board[MAX][MAX];
ll dp[MAX][MAX];
vector<pair<pair<int,int>,pair<int,int>>> v;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			dp[i][j]=0;
		}
	}	
	dp[0][0]=board[0][0];
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(i==0 && j==0) continue;
			dp[i][j]=board[i][j];
			if(i-1>=0){
				dp[i][j]+=dp[i-1][j];
			}
			if(j-1>=0){
				dp[i][j]+=dp[i][j-1];
			}
			if(i-1>=0 && j-1>=0){
				dp[i][j]-=dp[i-1][j-1];
			}
			// cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	}
	// cout<<dp[N-1][N-1];
	for(int i=0;i<M;++i){
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		--x1;
		--y1;
		--x2;
		--y2;
		// v.push_back({{x1,y1},{x2,y2}});
		ll sum=dp[x2][y2]-dp[x1][y1]+board[x1][y1];
		ll first_num=0;
		if(y1-1>=0){
			first_num=dp[x2][y1-1]-dp[x1][y1-1];
			// cout<<dp[x2][y1-1]<<" "<<dp[x1-1][y1-1]<<endl;
		}
		ll second_num=0;
		if(x1-1>=0){
			second_num=dp[x1-1][y2]-dp[x1-1][y1];
		}
		// cout<<first_num<<" "<<second_num<<"\n";
		sum-=first_num;
		sum-=second_num;
		cout<<sum<<"\n";

	}


	return 0;
}