#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


ll parent[300000+1];

ll find(ll a){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=find(parent[a]);
}
void union_find(ll a, ll b){
	a=find(a);
	b=find(b);
	if(a!=b){
		parent[a]=b;
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		for(ll i=0;i<n-2;++i){
			ll a,b;
			cin>>a>>b;
			union_find(a,b);
		}
		ll fst_root=find(1);
		ll sed_root;
		for(ll i=2;i<=n;++i){
			if(find(i)!=fst_root){
				sed_root=find(i);
				break;
			}
		}
		cout<<fst_root<<" "<<sed_root;
	}
	return 0;
}