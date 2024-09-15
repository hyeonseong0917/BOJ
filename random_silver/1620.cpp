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
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		map<ll,string> check;
		map<string,ll> reverse_check;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			// for(ll j=0;j<s.size();++j){
			// 	if(s[j]>='A' && s[j]<='Z'){
			// 		ll num=s[j]-'A';
			// 		char c='a'+num;
			// 		s[j]=c;
			// 	}
			// }
			check[i+1]=s;
			reverse_check[s]=i+1;
		}
		for(ll i=0;i<m;++i){
			string s;
			cin>>s;
			if(s[0]>='0' && s[0]<='9'){
				ll num=stoll(s);
				cout<<check[num]<<"\n";
			}else{
				cout<<reverse_check[s]<<"\n";
			}
		}
	}
	return 0;
}