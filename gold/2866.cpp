#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll r,c;
		cin>>r>>c;
		vector<string> v;
		for(ll i=0;i<r;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		vector<string> p;
		for(ll i=0;i<c;++i){
			string tmp="";
			for(ll j=0;j<r;++j){
				tmp+=v[j][i];
			}
			p.push_back(tmp);
		}
		ll max_len=r-1;
		bool flag=0;
		// r*c
		for(ll i=0;i<r;++i){
			map<string,ll> check;
			for(ll j=0;j<c;++j){
				string k=p[j].substr(i+1);
				++check[k];
				if(check[k]==2){
					flag=1;
					max_len=i;
					break;
				}
			}
			if(flag) break;
		}
		cout<<max_len;
	}
	return 0;
}