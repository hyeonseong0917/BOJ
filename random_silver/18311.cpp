#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
vector<ll> v;
int main() {
	// your code goes here
	ll N,K;
	cin>>N>>K;
	ll sum=0;
	v.push_back(0);
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		sum+=a;
		v.push_back(sum);
	}
	ll ans=-1;
	if(K<=sum){
		for(ll i=0;i<N;++i){
			ans=i+1;
			if(K<(v[i+1]-v[i])){
				break;
			}else{
				K-=(v[i+1]-v[i]);
				// cout<<K<<endl;
			}
		}
	}else{
		K-=sum;
		for(ll i=N;i>=1;--i){
			ans=i;
			if(K<(v[i]-v[i-1])){
				break;
			}else{
				K-=(v[i]-v[i-1]);
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}