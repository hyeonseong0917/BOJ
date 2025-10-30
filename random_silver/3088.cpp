#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		// 화분 n개. 3개의 정수가 쓰여있음
		ll n;
		cin>>n;
		vector<ll> check(1000000+1,0);
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			if(check[a] || check[b] || check[c]){
				++check[a];
				++check[b];
				++check[c];
				continue;
			}
			++ans;
			++check[a];
			++check[b];
			++check[c];
		}
		cout<<ans;
	} 
	return 0;
}