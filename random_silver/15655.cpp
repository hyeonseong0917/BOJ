#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

ll n,m;
vector<ll> v;
vector<ll> tmp;
bool visited[8+1];
void pick(ll idx){
	if(tmp.size()==m){
		for(ll i=0;i<m;++i){
			cout<<tmp[i]<<" ";
		}cout<<"\n";
		return;
	}
	for(ll i=idx;i<n;++i){
		if(!visited[i]){
			visited[i]=1;
			tmp.push_back(v[i]);
			pick(i+1);
			visited[i]=0;
			tmp.pop_back();
		}
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
			ll a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		pick(0);
	}

	return 0;
}