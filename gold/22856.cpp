#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long
ll node_cnt;
ll n;
vector<bool> visited;
vector<ll> parent;
vector<vector<ll>> v;
ll ans;
void dfs(ll cur_num, ll cnt){
	if(v[cur_num][0]==-1 && v[cur_num][1]==-1){
		if(node_cnt==n){
			ans=cnt;
			return;
		}
		dfs(parent[cur_num],cnt+1);
	}else{
		ll left_num=v[cur_num][0];
		ll right_num=v[cur_num][1];
		if(left_num!=-1 && !visited[left_num]){
			visited[left_num]=1;
			++node_cnt;
			dfs(left_num, cnt+1);
			return;
		}
		if(right_num==-1 || visited[right_num]){
			dfs(parent[cur_num],cnt+1);
			return;
		}
		if(right_num!=-1 && !visited[right_num]){
			visited[right_num]=1;
			++node_cnt;
			dfs(right_num,cnt+1);
			return;
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		cin>>n;
		parent=vector<ll>(100000+1,0);
		visited=vector<bool>(100000+1,0);
		for(ll i=1;i<=100000;++i){
			vector<ll> tmp;
			v.push_back(tmp);
		}
		node_cnt=1;
		ans=0;
		for(ll i=1;i<=100000;++i){
			v[i].push_back(-1);
			v[i].push_back(-1);
		}
		parent[1]=1;
		
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v[a][0]=b;
			v[a][1]=c;
			parent[b]=a;
			parent[c]=a;
		}
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}