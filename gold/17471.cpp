#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

// 2050
// 
ll N;
vector<ll> v;
vector<ll> g[10+1];
bool visited[10+1];
bool con[10+1][10+1];
ll ans=2023101800;
map<pair<ll,ll>,ll> v_check;
void Input(){
	cin>>N;
	v=vector<ll>(N+1,0);
	for(ll i=1;i<=N;++i){
		cin>>v[i];
		visited[i]=0;
	}
	for(ll i=1;i<=N;++i){
		ll c;
		cin>>c;
		for(ll j=0;j<c;++j){
			ll a;
			cin>>a;
			if(v_check[{i,a}]) continue;
			++v_check[{i,a}];
			++v_check[{a,i}];
			con[i][a]=1;
			con[a][i]=1;
			g[i].push_back(a);
			g[a].push_back(i);
		}
	}
}

void dfs(ll cur_num){
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(visited[next_num]) continue;
		visited[next_num]=1;
		dfs(next_num);
	}
}
vector<ll> fst_team;
ll fst_check[10+1];
ll sed_check[10+1];
bool fst_in[11];
bool sed_in[11];
void fst_dfs(ll cur_num){
	// fst_team 선수들 이어져 있는지?
	bool fst_flag=0;
	queue<ll> fq;
	fq.push(fst_team[0]);
	for(ll i=1;i<=N;++i){
		fst_check[i]=0;
		sed_check[i]=0;
		fst_in[i]=false;
        sed_in[i]=false;
	}
	++fst_check[fst_team[0]];
	for(ll i=0;i<fst_team.size();++i){
		fst_in[fst_team[i]]=true;
	}
	while(!fq.empty()){
		ll cur_fst_num=fq.front();
		fq.pop();
		for(ll i=0;i<g[cur_fst_num].size();++i){
			ll next_num=g[cur_fst_num][i];
			if(fst_check[next_num]) continue;
			if(!fst_in[next_num]) continue;
			++fst_check[next_num];
			fq.push(next_num);
		}
	}
	for(ll i=1;i<=N;++i){
		if(!fst_in[i]) continue;
		if(!fst_check[i]){
			fst_flag=1;
			break;
		}
	}
	if(fst_flag) return;
	// fst_team기준으로 sed_team 만들기 가능?

	ll sed_sum=0;
	ll fst_sum=0;
	vector<ll> sed_team;
	for(ll i=1;i<=N;++i){
		if(!fst_check[i]){
			sed_team.push_back(i);
			sed_sum+=v[i];
			sed_in[i]=true;
		}else{
			fst_sum+=v[i];
		}
	}
	if(sed_team.empty()) return;
	// sed_team의 원소들이 이어져있는지?
	bool flag=0;
	queue<ll> q;
	q.push(sed_team[0]);
	++sed_check[sed_team[0]];
	while(!q.empty()){
		ll cur_sed_num=q.front();
		q.pop();
		for(ll i=0;i<g[cur_sed_num].size();++i){
			ll next_num=g[cur_sed_num][i];
			if(sed_check[next_num]) continue;
			if(!sed_in[next_num]) continue;
			++sed_check[next_num];
			q.push(next_num);
		}
	}
	for(ll i=1;i<=N;++i){
		if(!sed_in[i]) continue;
		if(!sed_check[i]){
			flag=1;
			break;
		}
	}
	if(!flag){
		ans=min(ans,(ll)abs(fst_sum-sed_sum));
	}
    if(fst_team.size()>=N-1){
		return;
	}
	for(ll i=2;i<=N;++i){
		if(visited[i]) continue;
		bool f=0;
		for(ll j=0;j<fst_team.size();++j){
			ll cur_fst_num=fst_team[j];
			if(con[cur_fst_num][i]){
				f=1;
				break;
			}
		}
		if(!f) continue;
		visited[i]=1;
		fst_team.push_back(i);
		fst_dfs(i);
		fst_team.pop_back();
		visited[i]=0;
	}
}

void solve(){
	// 나눌 수 없는 경우는 언제일까?
	// 독립된 구역이 3개 이상이라면 불가능? 나머지는 모두 가능한듯?
	ll cnt=0;
	for(ll i=1;i<=N;++i){
		if(!visited[i]){
			++cnt;
			visited[i]=1;
			dfs(i);
		}
	}
	if(cnt>=3){
		cout<<-1;
		return;
	}
	// 독립된 구역이 1개거나 2개임
	if(cnt==2){
		// 2개일 경우
		// cout<<"he";
		for(ll i=1;i<=N;++i){
			visited[i]=0;
		}	
		ll fst_sum=0;
		ll sed_sum=0;
		for(ll i=1;i<=N;++i){
			if(!visited[i]){
				visited[i]=1;
				dfs(i);
				break;
			}
		}	
		for(ll i=1;i<=N;++i){
			if(visited[i]){
				fst_sum+=v[i];
			}else{
				sed_sum+=v[i];
			}
		}
		cout<<(ll)abs(fst_sum-sed_sum);
	}else{
		// 1개일 경우
		fst_team.push_back(1);
		for(ll i=1;i<=N;++i){
			visited[i]=0;
		}	
		visited[1]=1;
		fst_dfs(1);
		cout<<ans;
	}
}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll o=1;o<=1;++o){
		Input();
		solve();
	}
	return 0;
}