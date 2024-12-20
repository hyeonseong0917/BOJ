#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

bool visited[1000+1];
ll cnt=0;
ll n;
vector<ll> g[1000+1];

void dfs(ll cur_num){
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(visited[next_num]) continue;
		visited[next_num]=1;
		dfs(next_num);
		++cnt;
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;	
	while(o--){	
		cin>>n;
		for(ll i=1;i<=n;++i){
			ll a;
			cin>>a;
			g[i].push_back(a);
		}
		ll max_num=-1;
		ll max_student=-1;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=n;++j){
				visited[j]=0;
			}
			visited[i]=1;
			cnt=0;
			dfs(i);
			if(max_num<cnt){
				max_num=cnt;
				max_student=i;
			}
		}
		cout<<max_student;
	}
	return 0;
}