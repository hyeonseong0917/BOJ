#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main(){
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v[n+1];
		for(ll i=1;i<=n;++i){
			ll a;
			cin>>a;
			if(i==1) continue;
			v[a].push_back(i);
		}
		vector<ll> A(n+1,0);
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			A[a]+=b;
		}
		queue<ll> q;
		q.push(1);
		vector<ll> dp(n+1,0);
		while(!q.empty()){
			ll cur_num=q.front();
			q.pop();
			for(ll i=0;i<v[cur_num].size();++i){
				ll next_num=v[cur_num][i];
				dp[next_num]=dp[cur_num]+A[next_num];
				q.push(next_num);
			}
		}
		for(ll i=1;i<=n;++i){
			cout<<dp[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}