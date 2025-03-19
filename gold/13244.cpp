#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,m;
vector<ll> parent(1000000+1,0);
ll FIND(ll a){
	if(parent[a]==a) return a;
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
	cin>>o;
	while(o--){
		cin>>n>>m;
		if(m!=n-1){
			for(ll i=0;i<m;++i){
				ll a,b;
				cin>>a>>b;
			}
			cout<<"graph"<<"\n";
		}else{
			for(ll i=1;i<=n;++i){
				parent[i]=i;
			}
			bool flag=0;
			for(ll i=0;i<m;++i){
				ll a,b;
				cin>>a>>b;
				if(FIND(a)==FIND(b)){
					flag=1;
				}
				UNION(a,b);
			}
			if(flag){
				cout<<"graph"<<"\n";
			}else{
				cout<<"tree"<<"\n";
			}
		}
		
	}	
	return 0;
}