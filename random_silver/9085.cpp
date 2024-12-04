#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	cin>>o;
	while(o--){
		
		ll n;
		cin>>n;
		ll s=0;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			s+=a;
		}
		cout<<s<<"\n";
		
	}
	
	
	
	
	return 0;
}