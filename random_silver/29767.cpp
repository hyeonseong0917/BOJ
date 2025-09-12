#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		priority_queue<ll> pq;
		ll c=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			c+=v[i];
			pq.push(c);
		}
		ll ans=0;
		while(k--){
			ll cur_num=pq.top();
			pq.pop();
			ans+=cur_num;
		}
		cout<<ans;
		

	}
	return 0;
}