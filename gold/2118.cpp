#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
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
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		for(ll i=0;i<n-1;++i){
			v.push_back(v[i]);
		}
		n=v.size();
		ll ans=0;
		ll L=0, R=0;
		ll cur_sum=v[0];
		while(R<n){
			ll fst_sum=cur_sum;
			ll sed_sum=sum-fst_sum;
			if(fst_sum<=sed_sum){
				ans=max(ans,fst_sum);
				++R;
				cur_sum+=v[R];
			}else{
				cur_sum-=v[R];
				--R;
				cur_sum-=v[L];
				++L;
			}
		}
		cout<<ans;
	}
	return 0;
}