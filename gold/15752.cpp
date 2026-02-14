#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <set>
using namespace std;

#define ll long long

ll parent[100];
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
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(n,0);
		vector<ll> g[n];
		for(ll i=0;i<n;++i){
			cin>>v[i];
			parent[i]=i;
		}
		if(n==1){
			cout<<1;
			break;
		}
		if(n==2){
			cout<<1;
			break;
		}
		// n>=2
		sort(v.begin(),v.end());
		vector<pair<ll,ll>> p;
		p.push_back({0,1});
		for(ll i=1;i<n-1;++i){
			ll L=v[i]-v[i-1];
			ll R=v[i+1]-v[i];
			if(L<=R){
				p.push_back({i,i-1});
			}else{
				p.push_back({i,i+1});
			}
		}
		p.push_back({n-1,n-2});
		for(ll i=0;i<p.size();++i){
			UNION(p[i].first, p[i].second);
		}

		set<ll> roots;
		for(ll i=0;i<n;++i){
			roots.insert(FIND(i));
		}
		cout << roots.size();
		// cout<<ans;
		
	}
	return 0;
}