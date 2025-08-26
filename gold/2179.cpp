#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<string> v;
		map<string,ll> check;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			if(check[s]) continue;
			++check[s];
			v.push_back(s);
		}
		map<string,ll> m;
		ll ans=0;
		ll L=0,R=0;
		for(ll i=0;i<v.size();++i){
			string s=v[i];
			for(ll j=0;j<s.size();++j){
				string c=s.substr(0,j+1);
				if(!m[c]){
					m[c]=i+1;
					continue;
				}
				ll cs=c.size();
				if(ans<cs){
					L=m[c];
					R=i+1;
					ans=cs;
				}else{
					if(ans==cs){
						if(L>m[c]){
							L=m[c];
							R=i+1;
						}
					}
				}
			}
		}
		// cout<<ans;
		cout<<v[L-1]<<"\n";
		cout<<v[R-1];
	}
	
	return 0;
}