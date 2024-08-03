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
		string s;
		cin>>s;	
		vector<ll> ans(26,0);
		for(ll i=0;i<s.size();++i){
			++ans[s[i]-'a'];
		}
		for(ll i=0;i<26;++i){
			cout<<ans[i]<<" ";
		}
	}
	

	return 0;
}