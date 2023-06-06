#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//1230
vector<int> v;
int N=0;
long long dp[100+1][20+1];
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		long long a=0;
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<101;++i){
		for(int j=0;j<21;++j){
			dp[i][j]=0;
		}
	}
}
void solve(){
	dp[0][v[0]]=1;
	for(int i=1;i<=N-2;++i){
		for(int j=0;j<=20;++j){
			if(j-v[i]>=0){
				dp[i][j]+=dp[i-1][j-v[i]];
			}
			if(j+v[i]<=20){
				dp[i][j]+=dp[i-1][j+v[i]];
			}
		}
	}
	cout<<dp[N-2][v[N-1]];
	
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
