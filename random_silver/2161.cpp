#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;	
	while(o--){
		ll n;
		cin>>n;
		deque<ll> dq;
		for(ll i=1;i<=n;++i){
			dq.push_back(i);
		}
		vector<ll> ans;
		while(dq.size()>1){
			ans.push_back(dq.front());
			dq.pop_front();
			ll cur_front=dq.front();
			dq.pop_front();
			dq.push_back(cur_front);
		}
		ll as=ans.size();
		for(ll i=0;i<as;++i){
			cout<<ans[i]<<" ";
		}
		cout<<dq.back();
	}
	return 0;
}