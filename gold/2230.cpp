#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	ll N,M;
	cin>>N>>M;
	vector<ll> v;
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	ll L=0, R=0;
	ll ans=2000000000+1;
	while(L<=R && R<N){
		if(v[R]-v[L]>=M){
			ans=min(ans,v[R]-v[L]);
			++L;
		}else{
			++R;
		}
		// cout<<L<<" "<<R<<endl;
	}
	cout<<ans;
	return 0;
}