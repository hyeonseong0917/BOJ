#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string A,B;
const int MAX=1000+1;
int dp[MAX][MAX];
void Input(){
	cin>>A;
	cin>>B;
	memset(dp,0,MAX);
}
vector<char> ans;
void Print(int a, int b){
	if(dp[a][b]==0){
		return;
	}
	if(A[a-1]==B[b-1]){
		Print(a-1,b-1);
		cout<<A[a-1];
	}else{
		if(dp[a-1][b]>dp[a][b-1]){
			Print(a-1,b);
		}else{
			Print(a,b-1);
		}
	}
	
}
void solve(){
	for(int i=0;i<A.size();++i){
		for(int j=0;j<B.size();++j){
			if(A[i]==B[j]){
				dp[i+1][j+1]=dp[i][j]+1;	
			}else{
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
			
		}
	}
	cout<<dp[A.size()][B.size()]<<endl;
	Print(A.size(),B.size());
}

int main() {
	// your code goes here
	Input();
	solve();
	// for(int i=1;i<=A.size();++i){
	// 	for(int j=1;j<=B.size();++j){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }
	return 0;
}