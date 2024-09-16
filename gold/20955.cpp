#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

vector<ll> parent(100000+1,0);

ll Find(ll a){
	if(a==parent[a]) return a;
	return parent[a]=Find(parent[a]);
}
void Union(ll a, ll b){
	a=parent[a];
	b=parent[b];
	parent[a]=b;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		ll ans=0;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			if(Find(a)==Find(b)){
				++ans;
			}else{
				Union(a,b);
			}
		}
		vector<ll> check(n+1,0);
		ll root_num=0;
		for(ll i=1;i<=n;++i){
			if(!check[Find(i)]){
				check[Find(i)]=1;
				++root_num;
			}
		}
		ans+=(root_num-1);
		cout<<ans;
	}
	return 0;
}