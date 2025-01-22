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
	ll t=1;	
	while(t--){	
		vector<string> v;
		ll max_len=0;
		for(ll i=0;i<5;++i){
			string s;
			cin>>s;
			v.push_back(s);
			ll ss=s.size();
			max_len=max(max_len,ss);
		}
		for(ll i=0;i<5;++i){
			string s=v[i];
			ll ss=s.size();
			ll diff=max_len-ss;
			for(ll j=0;j<diff;++j){
				s+=' ';
			}
			v[i]=s;
		}
		string ans="";
		for(ll i=0;i<max_len;++i){
			for(ll j=0;j<5;++j){
				if(v[j][i]==' ') continue;
				ans+=v[j][i];
			}
		}
		cout<<ans;
	}
	return 0;
}