#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll l,n,k;
bool isRange(ll y){
	return (y>=0 && y<=l);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>l>>n>>k;
		map<ll,ll> visited;
		queue<pair<ll,ll>> q;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			q.push({a,a});
			visited[a]=1;
		}
		vector<ll> ans;
		while(!q.empty()){
			ll cur_num=q.front().first;
			ll fst_num=q.front().second;
			q.pop();
			// cout<<cur_num<<" "<<fst_num<<endl;
			ans.push_back(abs(cur_num-fst_num));
			ll as=ans.size();
			if(as==k){
				break;
			}
			if(isRange(cur_num-1) && !visited[cur_num-1]){
				visited[cur_num-1]=1;
				q.push({cur_num-1,fst_num});
			}
			if(isRange(cur_num+1) && !visited[cur_num+1]){
				visited[cur_num+1]=1;
				q.push({cur_num+1,fst_num});
			}
		}
		for(ll i=0;i<k;++i){
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}