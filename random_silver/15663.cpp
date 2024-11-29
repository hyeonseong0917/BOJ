#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

#define ll long long

ll n,m;
vector<ll> v;
vector<vector<ll>> ans;
vector<ll> tmp;
bool visited[8+1];
map<vector<ll>,ll> check;
// 9 7 9 1
void pick(){
	if(tmp.size()==m){
		if(!check[tmp]){
			check[tmp]=1;
			ans.push_back(tmp);
		}
		return;
	}
	for(ll i=0;i<n;++i){
		if(visited[i]) continue;
		// tmp에 v[i]가 없다면
		tmp.push_back(v[i]);
		visited[i]=1;
		pick();
		visited[i]=0;
		tmp.pop_back();
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		pick();
		sort(ans.begin(),ans.end());
		for(ll i=0;i<ans.size();++i){
			for(ll j=0;j<m;++j){
				cout<<ans[i][j]<<" ";
			}cout<<"\n";
		}
	}
	return 0;
}