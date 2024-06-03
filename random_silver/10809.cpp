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
	int t=1;
	while(t--){
		string s;
		cin>>s;
		vector<ll> v(26,-1);
		for(ll i=0;i<s.size();++i){
			if(v[s[i]-'a']==-1){
				v[s[i]-'a']=i;
			}
		}
		for(ll i=0;i<26;++i){
			cout<<v[i]<<" ";
		}
	}
	
	return 0;
}