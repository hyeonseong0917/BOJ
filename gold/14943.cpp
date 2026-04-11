#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<pair<ll,ll>> A,B;
		for(ll i=0;i<n;++i){
			if(v[i]==0) continue;
			if(v[i]>0){
				A.push_back({v[i],i});
			}else{
				B.push_back({v[i]*-1,i});
			}
		}
		if(A.empty() && B.empty()){
			cout<<0;
			continue;
		}
		ll L=0, R=0;
		ll as=A.size();
		ll bs=B.size();
		ll ans=0;
		while(L<as && R<bs){
			if(A[L].first==0){
				++L;
				continue;
			}
			if(B[R].first==0){
				++R;
				continue;
			}
			// A[L]과 B[R]
			if(A[L].first<=B[R].first){
				ans+=(ll)(A[L].first*((ll)(abs)(B[R].second-A[L].second)));
				B[R].first-=A[L].first;
				++L;
			}else{
				ans+=(ll)(B[R].first*((ll)(abs)(B[R].second-A[L].second)));
				A[L].first-=B[R].first;
				++R;
			}
		}
		cout<<ans;

	}
	return 0;
}