#include <iostream>
#include <algorithm>
#include <vector>
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
		for(ll i=n;i>=1;--i){
			for(ll j=0;j<i;++j){
				cout<<"*";
			}cout<<"\n";

		}

	}
	return 0;
}