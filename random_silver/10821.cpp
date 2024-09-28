#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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
		ll cnt=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]==',') ++cnt;
		}
		cout<<cnt+1;
	}

	return 0;
}