#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

const int MAX=500000+1;
ll parent[MAX];
ll n,m;

ll find(ll a){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=find(parent[a]);
}
void union_find(ll a, ll b){
	a=find(a);
	b=find(b);
	parent[a]=b;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			parent[i]=i;
		}
		ll ans=0;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			if(ans!=0) continue;
			if(find(a)==find(b)){
				ans=i+1;
				continue;
			}
			union_find(a,b);
		}
		cout<<ans;
	}
	return 0;
}