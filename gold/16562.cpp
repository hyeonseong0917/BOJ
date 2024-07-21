#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,k;
vector<ll> parent;
ll find(ll a){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=find(parent[a]);
}
void Union(ll a, ll b){
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
		cin>>n>>m>>k;
		vector<ll> v(n+1,0);
		parent=vector<ll>(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
			parent[i]=i;
		}
		vector<ll> check(n+1,0);
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			if(find(a)==find(b)) continue;
			Union(a,b);
		}
		vector<ll> ans(n+1,20000);
		for(ll i=1;i<=n;++i){
			ll cur_num=find(i);
			ans[cur_num]=min(ans[cur_num],v[i]);
			// cout<<i<<" "<<find(i)<<endl;
		}
		ll total_sum=0;
		for(ll i=1;i<=n;++i){
			if(ans[find(i)]==20000){
				total_sum+=v[i];
			}else{
				if(!check[find(i)]){
					check[find(i)]=1;
					total_sum+=ans[find(i)];
				}
			}
		}
		
		// cout<<total_sum<<endl;
		if(total_sum>k){
			cout<<"Oh no";
		}else{
			cout<<total_sum;
		}

	}
	return 0;
}