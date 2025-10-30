#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


ll ans=0;
ll mod=1000000007;
vector<ll> v(1000,0);
vector<ll> g[1000+1];
vector<ll> visited(1000+1,0);
bool flag=0;
ll fin_ans;
void dfs(ll cur_num, ll fin_num){
	// cout<<cur_num<<" "<<fin_num<<" "<<ans<<"\n";
	if(flag) return;
	if(cur_num==fin_num){
		flag=1;
		fin_ans=ans;
		return;
	}
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(visited[next_num]) continue;
		// ans와 next_num 합침
		string next_num_str=to_string(v[next_num]);
		ll ns=next_num_str.size();
		ll tmp_ans=ans;
		for(ll i=0;i<ns;++i){
			ans*=10;
			ans%=mod;
		}
		ans+=v[next_num];
		ans%=mod;
		visited[next_num]=1;
		dfs(next_num,fin_num);
		ans=tmp_ans;
		visited[next_num]=0;
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,q;
		cin>>n>>q;
		
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			ans=0;
			if(a==b){
				cout<<v[a]<<"\n";
			}else{
				for(ll j=0;j<=n;++j){
					visited[j]=0;
				}
				flag=0;
				ans=v[a];
				visited[a]=1;
				fin_ans=0;
				dfs(a,b);
				cout<<fin_ans<<"\n";
			}
		}
	}
	return 0;
}