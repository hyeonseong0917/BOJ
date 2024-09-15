#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

vector<ll> parent(1000000+1,0);
vector<ll> dp(1000000+1,1);

ll find(ll a){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=find(parent[a]);
}
void Union(ll a, ll b){
	a=find(a);
	b=find(b);
	parent[a]=parent[b];
	dp[b]+=dp[a];
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		for(ll i=1;i<=1000000;++i){
			parent[i]=i;
		}
		ll n;
		cin>>n;
		// 부품 11과 부품 22가 A의 부품임
		// robot(11): A, robot(22): B
		for(ll i=0;i<n;++i){
			char c;
			cin>>c;
			ll a,b;
			if(c=='I'){
				cin>>a>>b;
				if(find(a)!=find(b)){
					Union(a,b);
				}
			}else{
				cin>>a;
				cout<<dp[find(a)]<<"\n";
			}
		}
	}
	return 0;
}