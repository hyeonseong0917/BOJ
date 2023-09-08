#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=250000+5;

int main() {
	// your code goes here
	int N,X;
	cin>>N>>X;
	vector<int> v;
	int dp[MAX];
	for(int i=0;i<MAX;++i){
		dp[i]=0;
	}
	bool is_all_zero=0;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		if(a!=0){
			is_all_zero=1;
		}
		v.push_back(a);
	}
	if(!is_all_zero){
		cout<<"SAD";
	}else{
		dp[0]=v[0];
		for(int i=1;i<N;++i){
			dp[i]=dp[i-1]+v[i];
		}
		int maxNum=-1;
		int cnt=0;
		for(int i=X-1;i<N;++i){
			// cout<<dp[i]<<" "<<dp[i-(X-1)]<<endl;
			if(i==X-1){
				maxNum=dp[i];
			}else{
				maxNum=max(maxNum,dp[i]-dp[i-X]);
			}
			
		}
		for(int i=X-1;i<N;++i){
			if(i==X-1){
				if(dp[i]==maxNum){
					++cnt;
				}
			}else{
				if(dp[i]-dp[i-X]==maxNum){
					++cnt;
				}
			}
			
		}
		cout<<maxNum<<"\n";
		cout<<cnt;
		
	}
	


	return 0;
}