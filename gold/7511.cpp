#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


ll parent[1000000+1];
ll Find(ll a){
	if(a!=parent[a]){
		return parent[a]=Find(parent[a]);
	}
	return a;
}

void Union(ll a, ll b){
	a=Find(a);
	b=Find(b);
	if(a!=b){
		parent[a]=b;
	}
	
	// if(a<b){
	// 	parent[b]=a;
	// }else{
	// 	parent[a]=b;
	// }
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	ll num=1;
	while(o--){
		ll n,k;
		cin>>n;
		for(ll i=0;i<n;++i){
			parent[i]=i;
		}
		cin>>k;
		for(ll i=0;i<k;++i){
			ll a,b;
			cin>>a>>b;
			Union(a,b);
		}
		ll m;
		cin>>m;
		vector<pair<ll,ll>> p;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			p.push_back({a,b});
		}
		vector<ll> ans;
		for(ll i=0;i<m;++i){
			ll a=p[i].first;
			ll b=p[i].second;
			if(Find(a)==Find(b)){
				ans.push_back(1);
			}else{
				ans.push_back(0);
			}
		}
		// cout<<"Sceranio "<<num<<":\n";
		cout << "Scenario " << num << ":" << endl;
		++num;
		for(ll i=0;i<m;++i){
			cout<<ans[i]<<"\n";
		}
		cout<<"\n";
	} 
	return 0;
}