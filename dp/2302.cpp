#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=50+5;

int dp[MAX];
int vip[MAX];
vector<pair<int,int>> seg;
int main() {
	// your code goes here
	for(int i=0;i<MAX;++i){
		dp[i]=0;
		vip[i]=0;
	}
	int N,M;
	cin>>N;
	cin>>M;
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		vip[a]=1;
	}
	if(N==M){
		cout<<1;
		return 0;
	}
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=N;++i){
		dp[i]=dp[i-1]+dp[i-2];
	}
	int sum=1;
	int pre_idx=1;
	int cnt=0;
	for(int i=1;i<=N;++i){
		if(vip[i]==1){
			sum*=dp[cnt];
			cnt=0;
		}else{
			++cnt;
		}
	}
	if(cnt!=0){
		sum*=dp[cnt];
	}
	cout<<sum;


	


	return 0;
}