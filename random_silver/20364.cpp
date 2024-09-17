#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,q;
		cin>>n>>q;
		map<ll,ll> m;
		for(ll i=0;i<q;++i){
			ll a;
			cin>>a;
			bool flag=0;
			ll last_num=-1;
			ll tmp=a;
			while(a>1){
				if(!m[a]){
					a/=2;
				}else{
					flag=1;
					last_num=a;
					a/=2;
				}
			}
			if(flag){
				cout<<last_num<<"\n";
			}else{
				m[tmp]=1;
				cout<<0<<"\n";
			}
		}
	}
	return 0;
}