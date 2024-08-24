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
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		ll ans=0;
		for(ll i=0;i<m;++i){
			string s;
			cin>>s;
			ll L=0, R=n-1;
			ll k=s.size();
			while(L<=R){
				ll mid=(L+R)/2;
				if(s<v[mid]){
					R=mid-1;
				}else{
					L=mid+1;
					
				}
				string cur_str=v[mid].substr(0,k);
				if(cur_str.compare(s)==0){
					++ans;
					break;
				}
			}
		}
		cout<<ans;
		
		
		

	}
	return 0;
}