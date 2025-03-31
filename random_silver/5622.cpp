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
		string s;
		cin>>s;
		vector<string> v;
		v.push_back("");
		v.push_back("");
		v.push_back("ABC");
		v.push_back("DEF");
		v.push_back("GHI");
		v.push_back("JKL");
		v.push_back("MNO");
		v.push_back("PQRS");
		v.push_back("TUV");
		v.push_back("WXYZ");
		ll ans=0;
		for(ll i=0;i<s.size();++i){
			for(ll j=2;j<v.size();++j){
				for(ll k=0;k<v[j].size();++k){
					if(v[j][k]==s[i]){
						ans+=j+1;
					}
				}
			}
		}
		cout<<ans;

	} 
	return 0;
}