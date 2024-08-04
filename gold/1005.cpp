#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

const int MAX=1000+1;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o;
	cin>>o;
	while(o--){
		vector<ll> in_num[MAX],out_num[MAX];
		map<ll,ll> m;
		ll n,k;
		cin>>n>>k;
		vector<ll> d(n+1,0);
		vector<ll> dp(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>d[i];
		}
		ll w;
		for(ll i=0;i<k;++i){
			ll a,b;
			cin>>a>>b;
			in_num[b].push_back(a);
			out_num[a].push_back(b);
		}
		cin>>w;
		queue<ll> q;
		for(ll i=1;i<=n;++i){
			if(in_num[i].empty()){
				q.push(i);
				dp[i]=d[i];
			}
		}
		while(!q.empty()){
			ll cur_num=q.front();
			q.pop();
			for(ll i=0;i<out_num[cur_num].size();++i){
				ll next_num=out_num[cur_num][i];
				++m[next_num];
				if(m[next_num]==in_num[next_num].size()){
					for(ll j=0;j<in_num[next_num].size();++j){
						ll next_in_num=in_num[next_num][j];
						dp[next_num]=max(dp[next_num],dp[next_in_num]+d[next_num]);
					}
					q.push(next_num);
				}
			}
		}
		// for(ll i=1;i<=n;++i){
		// 	cout<<dp[i]<<" ";
		// }cout<<"\n";
		cout<<dp[w]<<"\n";
	}
	return 0;
}