#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n,m;
vector<ll> parent;

ll find(ll x){
	if(x==parent[x]){
		return x;
	}
	return parent[x]=find(parent[x]);
}

void Union(ll x, ll y){
	x=find(x);
	y=find(y);
	if(x!=y){
		parent[x]=y;
	}
}

int main() {
	// your code goes here
	ll o=1;
	while(1){
		cin>>n>>m;
		if(n==0 && m==0) break;
		parent=vector<ll>(n+1,0);
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		vector<bool> check(n+1,0);
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			if(find(a)==find(b)){
				check[find(a)]=1;
				continue;
			}
			
			if(check[find(a)]){
				check[find(b)]=1;
				Union(a,b);
				continue;
			}
			if(check[find(b)]){
				check[find(a)]=1;
				Union(a,b);
				continue;
			}
			Union(a,b);
		}
		vector<bool> visited(n+1,0);
		ll ans=0;
		for(ll i=1;i<=n;++i){
			if(!visited[find(i)] && !check[find(i)]){
				visited[find(i)]=1;
				++ans;
			}
		}
		if(ans==0){
			cout<<"Case "<<o<<": No trees."<<"\n";	
		}else if(ans==1){
			cout<<"Case "<<o<<": There is one tree."<<"\n";	
		}else{
			cout<<"Case "<<o<<": A forest of "<<ans<<" trees."<<"\n";	
		}
		++o;

	}

	return 0;
}