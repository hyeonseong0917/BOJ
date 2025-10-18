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
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans=0;
		ll cur_time=0;
		for(ll i=0;i<n;++i){
			// v[i]+k번째 초에 박수침
			if(v[i]<=cur_time) continue;
			++ans;
			cur_time=v[i]+k;
		}
		cout<<ans;
	}
	return 0;
}