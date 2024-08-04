#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		bool flag=0;
		map<string,ll> m;
		m[v[0]]=1;
		for(ll i=1;i<n;++i){
			ll cur_size=v[i].size();
			string tmp="";
			for(ll j=0;j<cur_size;++j){
				tmp+=v[i][j];
				if(m[tmp]){
					flag=1;
					break;
				}
			}
			if(flag){
				break;
			}
			m[v[i]]=1;
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}