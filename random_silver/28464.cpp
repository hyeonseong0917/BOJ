#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
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
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll a=0, b=0;
		ll L=0, R=n-1;
		ll cnt=0;
		while(L<=R){
			if(cnt%2==0){
				b+=v[R--];
			}else{
				a+=v[L++];
			}
			++cnt;
		}
		cout<<a<<" "<<b;
	}
	return 0;
}