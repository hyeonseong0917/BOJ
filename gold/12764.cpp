#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

const ll MAX=100000+1;
ll visited[MAX];
vector<pair<ll,ll>> v;
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}
vector<ll> ans;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	ll N;
	cin>>N;
	for(ll i=0;i<N;++i){
		ll a,b;
		cin>>a>>b;
		v.push_back({a,b});
		visited[i+1]=0;
	}
	sort(v.begin(), v.end(), comp);
	priority_queue<pair<ll,ll>> pq;
	ll num=0;
	map<ll,ll> m;
	for(ll i=0;i<N;++i){
		while(!pq.empty()){
			if(pq.top().first*-1<=v[i].first){
				++m[pq.top().second];
				pq.pop();
			}else{
				break;
			}
		}
		if(!m.empty()){
			ll cur_num=m.begin()->first;
			pq.push({v[i].second*-1, cur_num});
			++visited[cur_num];
			m.erase(cur_num);
		}else{
			pq.push({v[i].second*-1, num});
			++visited[num++];
		}
	}
	for(ll i=0;i<N;++i){
		if(!visited[i]) break;
		else ans.push_back(visited[i]);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<" ";
	}

	return 0;
}