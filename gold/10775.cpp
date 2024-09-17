#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll parent[100000+1];

ll Find(ll a){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=Find(parent[a]);
}
void Union(ll a){
	a=Find(a);
	parent[a]=a-1;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll g,p;
		cin>>g>>p;
		vector<ll> v(p,0);
		for(ll i=0;i<p;++i){
			cin>>v[i];
		}
		for(ll i=1;i<=g;++i){
			parent[i]=i;
		}
		ll ans=0;
		for(ll i=0;i<p;++i){
			if(Find(v[i])==0){
				break;
			}
			Union(Find(v[i]));
			++ans;
		}
		cout<<ans;
	}
	return 0;
}