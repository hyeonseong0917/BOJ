#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll parent[100000+1];
ll FIND(ll a){
	if(a==parent[a]) return a;
	return parent[a]=FIND(parent[a]);
}

void UNION(ll a, ll b){
	a=FIND(a);
	b=FIND(b);
	if(a!=b){
		parent[a]=b;
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			UNION(a,b);
		}
		ll ans=0;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=1;i<n;++i){
			ll pre_num=FIND(v[i-1]);
			ll cur_num=FIND(v[i]);
			if(pre_num!=cur_num) ++ans;
		}
		cout<<ans;

	}
	return 0;
}