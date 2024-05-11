#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int dp[1000+1][1000+1];
int main() {
	// your code goes here
	int t=1;
	while(t--){
		int n,m;
		cin>>n>>m;
		
		for(int i=0;i<1000+1;++i){
			for(int j=0;j<1000+1;++j){
				dp[i][j]=0;
			}
		}
		vector<int> v(n,0);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}	
		dp[0][0]=(m-v[0])*(m-v[0]);
		for(int i=1;i<n;++i){
			int cur_sum=0;
			for(int j=0;j<=i;++j){
				cur_sum+=v[j];
			}
			cur_sum+=i;
			if(cur_sum>m){
				break;
			}
			int next_sum=0;
			for(int j=i;j<n;++j){
				next_sum+=v[j];
			}
			if(next_sum+(n-i-1)<=m){
				dp[i][0]=0;
			}else{
				dp[i][0]=(m-cur_sum)*(m-cur_sum);
			}
		}
		
		for(int i=1;i<n;++i){
			// i번째 줄
			for(int j=1;j<n;++j){
				// j번째 수를 i번째 줄의 마지막 수로

				// j번째 수부터 n-1번째 수까지 다 더했을 때 m보다 작다면 0
				// dp[j][i]=min(dp[j-1][i-1]+(m-v[j])*(m-v[j]), );
				int fst_num=dp[j-1][i-1];
				int sed_num=(sqrt(dp[j-1][i])-(v[j]+1))*(sqrt(dp[j-1][i])-(v[j]+1));
				dp[j][i]=min(fst_num,sed_num);
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(!dp[i][j]) continue;
				cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}
	}

	return 0;
}