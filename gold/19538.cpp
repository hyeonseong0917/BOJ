#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll n,m;
ll rumor[200000+1];
ll total_cnt[200000+1];
vector<ll> g[200000+1];
vector<ll> v;
ll INF=2023101800;
void Input(){
	cin>>n;
	for(ll i=1;i<=n;++i){
		rumor[i]=INF;
		total_cnt[i]=0;
		while(1){
			ll a;
			cin>>a;
			if(a==0) break;
			g[i].push_back(a);
		}
	}
	cin>>m;
	for(ll i=0;i<m;++i){
		ll a;
		cin>>a;
		rumor[a]=0;
		v.push_back(a);
	}
}
void solve(){
	queue<ll> q;
	for(ll i=0;i<m;++i){
		q.push(v[i]);
	}
	ll cnt=1;
	while(!q.empty()){
		ll qs=q.size();
		// q에 cur_num은 무조건 한 번만 들어간다
		queue<ll> tmp;
		map<ll,ll> check;
		for(ll i=0;i<qs;++i){
			ll cur_num=q.front();
			q.pop();
			for(ll j=0;j<g[cur_num].size();++j){
				ll next_num=g[cur_num][j];
				// cout<<"fds"<<cur_num<<"next_num: "<<next_num<<endl;
				if(!check[next_num]){
					++check[next_num];
					tmp.push(next_num);
				}
				++total_cnt[next_num];
			}
		}
		while(!tmp.empty()){
			ll cur_num=tmp.front();
			// cout<<"fds"<<cur_num<<endl;
			tmp.pop();
			ll cs=(g[cur_num].size()+1)/2;
			if(total_cnt[cur_num]<cs) continue;
			if(rumor[cur_num]!=INF) continue;
			rumor[cur_num]=cnt;
			q.push(cur_num);
		}
		++cnt;
	}
	
	
	for(ll i=1;i<=n;++i){
		if(rumor[i]>=INF){
			rumor[i]=-1;
		}
	}
	for(ll i=1;i<=n;++i){
		cout<<rumor[i];
		if(i!=n){
			cout<<" ";
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		Input();
		solve();
	}

	return 0;
}