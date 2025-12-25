#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n;
ll check[200000+1][2];
vector<ll> v[200000+1];
vector<ll> visited(200000+1,0);
ll a,b,c;
void dfs(ll cur_num, ll cur_cnt, ll flag){
	check[cur_num][flag]=cur_cnt;
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(!visited[next_num]){
			visited[next_num]=1;
			dfs(next_num,cur_cnt+1,flag);
		}
	}
}
bool flag=0;
void player_go(ll cur_num, ll cur_cnt){
	if(flag) return;
	if(v[cur_num].size()==1){
		flag=1;
		return;
	}
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(visited[next_num]) continue;
		ll fst_check=check[next_num][0];
		ll sed_check=check[next_num][1];
		if(cur_cnt+1!=fst_check && cur_cnt+1!=sed_check && cur_cnt!=fst_check && cur_cnt!=sed_check){
			visited[next_num]=1;
			player_go(next_num,cur_cnt+1);
		}
	}

}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;		
		for(ll i=0;i<n-1;++i){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(ll i=1;i<=n;++i){
			check[i][0]=-1;
			check[i][1]=-1;
		}
		cin>>a>>b>>c;
		visited=vector<ll>(200000+1,0);
		visited[b]=1;
		dfs(b,0,0);

		visited=vector<ll>(200000+1,0);
		visited[c]=1;
		dfs(c,0,1);

		visited=vector<ll>(200000+1,0);
		visited[a]=1;
		player_go(a,0);
		if(flag){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
	return 0;
}