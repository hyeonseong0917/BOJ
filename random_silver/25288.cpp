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
        string s;
        cin>>s;
        // ba 3
        // bbb aaa bba baa aba
        // aba bab
        // bababa
        string ans="";
        for(ll i=0;i<n;++i){
            ans+=s;
        }
        cout<<ans;

	} 
	return 0;
}