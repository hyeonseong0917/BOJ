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
	int t=1;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(m,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll cur_price=-1;
		ll cur_profit=-1;
		for(ll i=0;i<m;++i){
			ll cur_num=v[i]*min(n,m-i);
			if(cur_num>cur_profit){
				cur_profit=cur_num;
				cur_price=v[i];
			}
		}
		cout<<cur_price<<" "<<cur_profit;
	}
	return 0;
}