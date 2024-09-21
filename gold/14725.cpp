#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<string> v[n+1];
		for(ll i=0;i<n;++i){
			ll k;
			cin>>k;
			for(ll j=0;j<k;++j){
				string t;
				cin>>t;
				v[i].push_back(t);
			}
		}
		map<string,ll> m;
		for(ll i=0;i<n;++i){
			string tmp="";
			for(ll j=0;j<v[i].size();++j){
				tmp+=" ";
				tmp+=v[i][j];
				m[tmp]=1;
			}
		}
		for(auto it=m.begin();it!=m.end();++it){
			// cout<<it->first<<endl;
			string s=it->first;
			s=s.substr(1);
			ll cnt=0;
			ll idx=-1;
			for(ll j=0;j<s.size();++j){
				if(s[j]==' '){
					++cnt;
					idx=j;
				}
			}
			string last_str=s.substr(idx+1);
			for(ll i=0;i<cnt*2;++i){
				cout<<"-";
			}
			cout<<last_str<<"\n";

		}
		
	}
	return 0;
}