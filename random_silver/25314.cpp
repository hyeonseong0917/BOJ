#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		ll k=n/4-1;
		for(ll i=0;i<k;++i){
			cout<<"long ";
		}
		cout<<"long int";
	}
	return 0;
}