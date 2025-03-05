#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,x;
vector<pair<ll,ll>> v;
vector<ll> origin_grf[100000+1], reversed_grf[100000+1];
ll child_cnt=0, parent_cnt=0;
bool visited[100000+1];
void down_dfs(ll cur_num){
	for(ll i=0;i<origin_grf[cur_num].size();++i){
		ll next_num=origin_grf[cur_num][i];
		if(!visited[next_num]){
			visited[next_num]=1;
			++child_cnt;
			down_dfs(next_num);
		}
	}
}
void up_dfs(ll cur_num){
	for(ll i=0;i<reversed_grf[cur_num].size();++i){
		ll next_num=reversed_grf[cur_num][i];
		if(!visited[next_num]){
			visited[next_num]=1;
			++parent_cnt;
			up_dfs(next_num);
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// n명의 학생들
		// 총 M번 질문
		// X의 등수를 알고싶음
		cin>>n>>m>>x;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			origin_grf[a].push_back(b);
			reversed_grf[b].push_back(a);
		}
		// 2->3->4->5
		// 1->3, 2->3->4->5, 3->5
		for(ll i=0;i<=n;++i){
			visited[i]=0;
		}
		visited[x]=1;
		down_dfs(x);
		for(ll i=0;i<=n;++i){
			visited[i]=0;
		}
		visited[x]=1;
		up_dfs(x);
		ll rest_num=n-child_cnt-parent_cnt-1;
		cout<<parent_cnt+1<<" "<<parent_cnt+rest_num+1;
	}
	return 0;
}