#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0),tmp(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			tmp[i]=v[i];
		}
		sort(v.begin(),v.end());
		ll cnt=0;
		for(ll i=0;i<n;++i){
			v[i]+=n-i;
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<n;++i){
			if(tmp[i]+n<v[n-1]) continue;
			++cnt;
		}
		cout<<cnt;
	}
	return 0;
}