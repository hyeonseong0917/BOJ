#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
ll ans=0;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>ans;
		ll sum=0;
		for(ll i=0;i<9;++i){
			ll a;
			cin>>a;
			sum+=a;
		}
		cout<<ans-sum;

	}
	

	

	return 0;
}