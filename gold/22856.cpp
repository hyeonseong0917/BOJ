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
ll last_num;
vector<bool> visited;
vector<ll> parent;
vector<vector<ll>> v;
ll ans=0;
void mid_traverse(ll cur_num){
	if(v[cur_num][1]==-1){
		last_num=cur_num;
		// cout<<last_num<<endl;
		return;
	}else{
		mid_traverse(v[cur_num][1]);
	}
}
void dfs(ll cur_num, ll cnt){
	// cout<<cur_num<<" "<<cnt<<endl;
	if(parent[cur_num]==cur_num && cnt!=0){
		if(v[cur_num][1]!=-1 && !visited[v[cur_num][1]]){
			visited[v[cur_num][1]]=1;
			dfs(v[cur_num][1],cnt+1);
			return;
		}
		
	}
	if(cur_num==last_num){
		if(v[cur_num][0]==-1 && v[cur_num][1]==-1){
			ans=cnt;
			return;
		}
		if(v[cur_num][0]!=-1){
			if(visited[v[cur_num][0]]){
				ans=cnt;
				return;
			}
		}
		if(v[cur_num][1]!=-1){
			if(visited[v[cur_num][1]]){
				ans=cnt;
				return;
			}
		}
	}
	if(v[cur_num][0]==-1 && v[cur_num][1]==-1){
		
		dfs(parent[cur_num],cnt+1);
	}else{
		ll left_num=v[cur_num][0];
		ll right_num=v[cur_num][1];
		if(left_num!=-1){
			if(!visited[left_num]){
				visited[left_num]=1;
				++node_cnt;
				dfs(left_num, cnt+1);
				return;
			}
			
		}
		// visited[left_num]=1
		if(right_num==-1){
			dfs(parent[cur_num],cnt+1);
			return;
		}
		if(visited[right_num]){
			dfs(parent[cur_num],cnt+1);
			return;
		}
		if(!visited[right_num]){
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
		parent=vector<ll>(n+1,0);
		visited=vector<bool>(n+1,0);
		for(ll i=0;i<=n;++i){
			vector<ll> tmp;
			v.push_back(tmp);
		}
		node_cnt=1;
		ans=0;
		for(ll i=1;i<=n;++i){
			v[i].push_back(-1);
			v[i].push_back(-1);
		}
		parent[1]=1;
		
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v[a][0]=b;
			v[a][1]=c;
			if(b!=-1){
				parent[b]=a;
			}
			if(c!=-1){
				parent[c]=a;
			}
		}
		mid_traverse(1);
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}