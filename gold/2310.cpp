#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


ll n;
ll check[1000+1];
ll cost[1000+1];
// dp[x]: 1번에서 x까지 도달했을 때, 가지고 있던 비용의 최댓값
ll dp[1000+1];
vector<ll> g[1000+1];

ll BFS(){
	// 1번에서 n번 가능한지?
	// 돈,위치
	queue<pair<ll,ll>> q;
	if(check[1]==2){
		return 0;
	}
	if(check[1]==1){
		q.push({cost[1],1});
		dp[1]=cost[1];
	}else{
		q.push({0,1});
		dp[1]=0;
	}
	
	ll c=0;
	while(!q.empty()){
		// cur_num위치에 있고, cur_cost의 돈을 가지고 있음
		ll cur_cost=q.front().first;
		ll cur_num=q.front().second;
		// cout<<cur_num<<" "<<cur_cost<<"\n";
		q.pop();
		if(cur_num==n){
			c=1;
			break;
		}
		for(ll i=0;i<g[cur_num].size();++i){
			ll next_num=g[cur_num][i];
			// next_num위치로 갈까말까?
			if(check[next_num]==0){
				// 빈 방
				if(dp[next_num]<cur_cost){
					dp[next_num]=cur_cost;
					q.push({dp[next_num],next_num});
				}
			}else if(check[next_num]==1){
				// 레프리콘 방 -> 돈 채울 수 있음
				ll next_cost=max(cost[next_num],cur_cost);
				if(dp[next_num]<next_cost){
					dp[next_num]=next_cost;
					q.push({dp[next_num],next_num});
				}
			}else{
				// 트롤 방 -> 가려면 돈 지불해야함
				ll next_cost=cur_cost-cost[next_num];
				if(next_cost>=0){
					if(dp[next_num]<next_cost){
						dp[next_num]=next_cost;
						q.push({dp[next_num],next_num});
					}
				}
			}
		}
	}
	return c;
}
void Init(){
	n=0;
	for(ll i=0;i<=1000;++i){
		check[i]=0;
		cost[i]=0;
		dp[i]=-1;
		g[i].clear();
	}
}
void Input(){
	string t;
	getline(cin,t);
	n=stoll(t);
	for(ll i=1;i<=n;++i){
		string s;
		getline(cin,s);
		vector<string> v;
		string k="";
		k+=s[0];
		v.push_back(k);
		string tmp="";
		for(ll j=2;j<s.size();++j){
			if(s[j]==' '){
				v.push_back(tmp);
				tmp="";
			}else{
				tmp+=s[j];
			}
		}
		v.push_back(tmp);
		// if(i==1){
		// 	cout<<v[0];
		// }
		if(v[0]=="E"){
			check[i]=0;
		}else if(v[0]=="L"){
			check[i]=1;
		}else{
			check[i]=2;
		}
		for(ll j=1;j<v.size()-1;++j){
			ll cur_num=stoll(v[j]);
			if(j==1){
				cost[i]=cur_num;
			}else{
				if(cur_num!=i){
					g[i].push_back(cur_num);
				}
			}
		}
	}

	// for(ll i=1;i<=n;++i){
	// 	cout<<i<<endl;
	// 	for(ll j=0;j<g[i].size();++j){
	// 		cout<<g[i][j]<<" ";
	// 	}cout<<"\n";
	// }
}

void solve(){
	while(1){
		Init();
		Input();
		if(n==0) break;
		// 1번방에서 n번방으로 갈 수 있는지?
		ll ans=BFS();
		if(ans==1){
			cout<<"Yes"<<"\n";
		}else{
			cout<<"No"<<"\n";
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		// Input();
		solve();
	}

	return 0;
}