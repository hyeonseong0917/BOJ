#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll a,b;
		cin>>a>>b;
		ll cur_kcal=0;
		cin>>cur_kcal;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		ll cur_num=cur_kcal/a;
		ll cur_price=a;
		// for(ll i=0;i<n;++i){
		// 	cout<<v[i]<<" ";
		// }cout<<endl;
		for(ll i=0;i<n;++i){
			if((cur_kcal+v[i])/(cur_price+b)<cur_num) break;
			cur_num=(cur_kcal+v[i])/(cur_price+b);
			cur_kcal+=v[i];
			cur_price+=b;
			
			// cout<<cur_kcal<<" "<<cur_price<<endl;
		}
		cout<<cur_kcal/cur_price;

	}
	
	return 0;
}