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
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			reverse(s.begin(),s.end());
			cout<<s<<"\n";
		}

	} 
	return 0;
}