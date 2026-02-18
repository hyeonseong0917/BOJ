#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


ll n,m;
vector<ll> g[100000+1];
map<ll,ll> check;

void Input(){
	cin>>n>>m;
	for(ll i=0;i<m;++i){
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	ll s;
	cin>>s;
	while(s--){
		ll a;
		cin>>a;
		++check[a];
	}
}
// cur_numㅇ
bool f=0;
void dfs(ll cur_num){
	if(f) return;
	// 언제 종료?
	// 갈 수 있는 길이 없고, check길이 남지 않았을 때
	bool flag=0;
	bool check_flag=0;
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(!check[next_num]){
			flag=1;
			dfs(next_num);
		}else{
			check_flag=1;
		}
	}
	if(!flag){
		if(!check_flag){
			f=1;
			return;
		}
	}
}

void solve(){
	// 1에서 출발해서 check를 만나지 않고 끝날 수 있는지?
	dfs(1);
	if(f && !check[1]){
		cout<<"yes";
	}else{
		cout<<"Yes";
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