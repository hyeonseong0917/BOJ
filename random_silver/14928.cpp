#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		string a;
		cin>>a;
		ll ans=0;
		for(ll i=0;i<a.size();++i){
			ans=(ans*10+(a[i]-'0'))%20000303;
		}
		cout<<ans;
	} 
	return 0;
}