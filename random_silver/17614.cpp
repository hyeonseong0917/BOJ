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
		ll n;
		cin>>n;
		ll ans=0;
		for(ll i=1;i<=n;++i){
			string s=to_string(i);
			ll cnt=0;
			for(int j=0;j<s.size();++j){
				if(s[j]=='3' ||s[j]=='6' || s[j]=='9'){
					++cnt;
				}
			}
			ans+=cnt;
		}
		cout<<ans;
	} 
	return 0;
}