#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int n;
const int MAX=10000+1;
vector<int> v[MAX];
vector<int> t(MAX,0);
vector<int> dp(MAX,0);
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>t[i];
		int k;
		cin>>k;
		if(k==0){
			dp[i]=t[i];
		}
		for(int j=0;j<k;++j){
			int a;
			cin>>a;
			v[i].push_back(a);
		}
	}
	for(int i=2;i<=n;++i){
		if(dp[i]!=0) continue;
		int max_num=0;
		for(int j=0;j<v[i].size();++j){
			max_num=max(max_num,dp[v[i][j]]);
		}
		max_num+=t[i];
		dp[i]=max_num;
		// cout<<i<<" "<<dp[i]<<"\n";
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}