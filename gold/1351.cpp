#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

map<ll,ll> m;
ll n,p,q;
ll dp(ll cur_num){
	if(cur_num==0) return 1;
	if(m[cur_num]) return m[cur_num];
	return m[cur_num]=dp(cur_num/p)+dp(cur_num/q);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>p>>q;
		m[0]=1;
		cout<<dp(n);
	}
	return 0;
}