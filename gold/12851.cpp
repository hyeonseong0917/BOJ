#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll INF=2023101800;
vector<ll> dp(200000+1,INF);
ll n,k;
ll min_num=INF;
bool isRange(ll cur_num){
	return (cur_num>=0 && cur_num<=200000);
}
ll cnt=0;
void getMinNum(){
	queue<ll> q;
	q.push(n);
	while(!q.empty()){
		ll cur_num=q.front();
		q.pop();
		if(cur_num==k){
			if(min_num>dp[cur_num]){
				cnt=1;
				min_num=dp[cur_num];
			}else if(min_num==dp[cur_num]){
				++cnt;
			}
			continue;
		}
		ll fst_num=cur_num+1;
		if(isRange(fst_num)){
			if(dp[fst_num]>=dp[cur_num]+1){
				dp[fst_num]=dp[cur_num]+1;
				q.push(fst_num);
			}
		}
		ll sed_num=cur_num-1;
		if(isRange(sed_num)){
			if(dp[sed_num]>=dp[cur_num]+1){
				dp[sed_num]=dp[cur_num]+1;
				q.push(sed_num);
			}
		}
		ll trd_num=cur_num*2;
		if(isRange(trd_num)){
			if(dp[trd_num]>=dp[cur_num]+1){
				dp[trd_num]=dp[cur_num]+1;
				q.push(trd_num);
			}
		}
	}
}
// n에서 출발하면서, min_num의 시간이 걸려서 위치 k에 도착하는 경우의 수는 몇 개?


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n>>k;		
		// dp[x]: x위치까지 가장 빠르게 도달했을 때의 시간
		// dp[k]를 구하고, bfs를 통해 dp[k]만큼 시간이 걸리는 경우의 수가 몇 개인지 확인
		dp[n]=0;
		getMinNum();
		cout<<min_num<<"\n";
		cout<<cnt;
	}
	return 0;
}
