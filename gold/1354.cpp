#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

map<ll,ll> m;
ll n,p,q,x,y;
ll dp(ll a){
	if(a<=0) return 1;
	if(m[a]) return m[a];
	else return m[a]=dp(a/p-x)+dp(a/q-y);
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>p>>q>>x>>y;
		cout<<dp(n);
	}
	return 0;
}