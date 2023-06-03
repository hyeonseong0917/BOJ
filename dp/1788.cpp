#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n=0;
	cin>>n;
	int dp[1000000+1]={0,};
	int mdp[1000000+1]={0,};
	dp[0]=0;
	
	mdp[0]=0;
	if(n<0){
		mdp[1]=1;
		for(int i=2;i<=n*-1;++i){
			mdp[i]=(mdp[i-2]-mdp[i-1])%1000000000;
		}
		// cout<<mdp[7];
		if(mdp[n*-1]<0){
			mdp[n*-1]*=-1;
			cout<<-1<<"\n";
		}else{
			cout<<1<<"\n";
		}
		cout<<mdp[n*-1];
	}else{
		if(n==0){
			cout<<0<<"\n";
			cout<<0;
			return 0;
		}
		dp[1]=1;	
		for(int i=2;i<=n;++i){
			dp[i]=(dp[i-2]+dp[i-1])%1000000000;
		}
		cout<<1<<"\n";
		cout<<dp[n];
	}
	return 0;
}