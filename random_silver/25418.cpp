#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> dp(k+1,1222232421);
		dp[n]=0;
		queue<pair<ll,ll>> q;
		q.push({n,0});
		while(!q.empty()){
			ll cur_num=q.front().first;
			ll cur_cnt=q.front().second;
			// cout<<cur_num<<" "<<cur_cnt<<endl;
			q.pop();
			if(cur_num*2<=k && dp[cur_num*2]>dp[cur_num]+1){
				dp[cur_num*2]=dp[cur_num]+1;
				q.push({cur_num*2,cur_cnt+1});
			}
			if(cur_num+1<=k && dp[cur_num+1]>dp[cur_num]+1){
				dp[cur_num+1]=dp[cur_num]+1;
				q.push({cur_num+1,cur_cnt+1});
			}
		}
		cout<<dp[k];
	}
	return 0;
}