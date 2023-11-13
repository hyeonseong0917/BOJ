#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

int T,W;
int dp[1000+1][30+1];
vector<int> v;
int main() {
	// your code goes here
	cin>>T>>W;
	for(int i=0;i<T;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<1000+1;++i){
		for(int j=0;j<30+1;++j){
			dp[i][j]=0;
		}
	}
	if(v[0]==1){
		dp[0][W]=1;
	}else{
		dp[0][W]=0;
		dp[0][W-1]=1;
	}
	for(int i=1;i<T;++i){
		// 0에서 i-1번째 인덱스까지 탐색
		for(int j=0;j<i;++j){
			if(v[i]==v[j]){
				//i번째 값과  j번째 값이 같았다면
				for(int w=W;w>=0;--w){
					dp[i][w]=max(dp[i][w],dp[j][w]+1);
				}
			}else{
				dp[i][W]=max(dp[i][W],1);
				for(int w=W-1;w>=0;--w){
					dp[i][w]=max(dp[i][w],dp[j][w+1]+1);
				}
			}
		}
	}
	int max_num=-1;
	for(int i=0;i<T;++i){
		for(int j=0;j<=W;++j){
			max_num=max(max_num,dp[i][j]);
		}
	}
	cout<<max_num;
	return 0;
}