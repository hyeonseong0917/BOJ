#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

const int MAX=1000+1;
vector<ll> v[MAX];
bool visited[MAX];
ll ans=0;
void dfs(ll cur_num){
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(!visited[next_num]){
			visited[next_num]=1;
			++ans;
			dfs(next_num);
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ans=0;
		for(ll i=0;i<MAX;++i){
			v[i].clear();
			visited[i]=0;
		}
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		for(ll i=1;i<=n;++i){
			if(!visited[i]){
				visited[i]=1;
				// ++ans;
				dfs(i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}