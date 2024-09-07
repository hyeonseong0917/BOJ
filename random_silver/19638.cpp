#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,h,t;
		cin>>n>>h>>t;
		priority_queue<ll> pq;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			pq.push(a);
		}
		ll ans=0;
		while(1){
			ll cur_num=pq.top();
			if(cur_num==1 || cur_num<h) break;
			pq.pop();
			++ans;
			pq.push(cur_num/2);
			if(ans==t) break;
		}
		ll max_h=pq.top();
		if(max_h<h){
			cout<<"YES"<<"\n";
			cout<<ans;
		}else{
			cout<<"NO"<<"\n";
			cout<<max_h;
		}
	}
	return 0;
}