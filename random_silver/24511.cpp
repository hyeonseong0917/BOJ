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
		vector<ll> v(n,0);
		deque<ll> dq;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(!v[i]) dq.push_front(a);
		}
		ll m;
		cin>>m;
		for(ll i=0;i<m;++i){
			ll a;
			cin>>a;
			if(!dq.empty()){
				cout<<dq.front()<<" ";
				dq.pop_front();
				dq.push_back(a);
			}else{
				cout<<a<<" ";
			}
			
		}

	}
	return 0;
}