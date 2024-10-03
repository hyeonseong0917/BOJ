#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

vector<pair<ll,ll>> v[100+1];
vector<pair<ll,ll>> g[100+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<bool> visited(n+1,0);
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			visited[a]=1;
			v[a].push_back({b,c});
		}
		map<ll,ll> default_num;
		map<ll,ll> check_num;
		for(ll i=1;i<=n;++i){
			if(!visited[i]){
				default_num[i]=1;
				g[i].push_back({i,1});
				check_num[i]=1;
			}
		}
		while(1){
			bool flag=0;
			for(ll i=1;i<=n;++i){
				if(default_num[i]) continue;
				if(check_num[i]) continue;
				flag=1;
				bool is_all_check=1;
				for(ll j=0;j<v[i].size();++j){
					if(!check_num[v[i][j].first]){
						is_all_check=0;
						break;
					}
				}
				if(!is_all_check) continue;
				// is_all_check
				check_num[i]=1;
				for(ll j=0;j<v[i].size();++j){
					ll cur_num=v[i][j].first;
					ll cur_cnt=v[i][j].second;
					if(default_num[cur_num]){
						g[i].push_back({cur_num,cur_cnt});
						continue;
					}
					for(ll k=0;k<g[cur_num].size();++k){
						ll cur_def_num=g[cur_num][k].first;
						ll cur_def_cnt=g[cur_num][k].second;
						// g[i]에 cur_def_num이 있는지?
						ll idx=-1;
						for(ll u=0;u<g[i].size();++u){
							if(g[i][u].first==cur_def_num){
								idx=u;
								break;
							}
						}
						if(idx==-1){
							g[i].push_back({cur_def_num,cur_cnt*cur_def_cnt});
						}else{
							g[i][idx].second+=cur_cnt*cur_def_cnt;
						}
						
					}
				}
			}

			if(!flag){
				break;
			}
		}
		vector<ll> check(n+1,0);
		for(ll i=0;i<g[n].size();++i){
			if(default_num[g[n][i].first]){
				check[g[n][i].first]+=g[n][i].second;
			}
		}
		for(ll i=1;i<=n;++i){
			if(default_num[i] && check[i]){
				cout<<i<<" "<<check[i]<<"\n";
			}
		}


	}
	return 0;
}