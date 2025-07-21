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
		vector<ll> a(26,0), b(26,0);
		string aa,bb;
		cin>>aa;
		cin>>bb;
		for(ll i=0;i<aa.size();++i){
			++a[aa[i]-'a'];
		}
		for(ll i=0;i<bb.size();++i){
			++b[bb[i]-'a'];
		}
		ll ans=0;
		for(ll i=0;i<26;++i){
			ans+=abs(a[i]-b[i]);
		}
		cout<<ans;
	} 
	return 0;
}