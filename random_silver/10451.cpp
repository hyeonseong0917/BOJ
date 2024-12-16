#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

ll n;
vector<ll> v;
bool visited[1000+1];
ll g[1000+1];
bool flag=0;

void dfs(ll cur_num){
	if(!visited[g[cur_num]]){
		visited[g[cur_num]]=1;
		dfs(g[cur_num]);
	}else{
		flag=1;
		return;
	}
	
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll t;
		cin>>t;
		while(t--){
			v.clear();
			cin>>n;
			for(ll i=0;i<n;++i){
				ll a=0;
				visited[i+1]=0;
				cin>>a;
				g[i+1]=a;
				v.push_back(a);
			}
			ll ans=0;
			for(ll i=1;i<=n;++i){
				if(visited[i]) continue;
				if(g[i]==i){
					visited[i]=1;
					++ans;
					continue;
				}
				visited[i]=1;
				flag=0;
				dfs(i);
				if(flag) ++ans;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}