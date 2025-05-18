#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<string> v;
		for(int i=0;i<n;++i){
			string a;
			cin>>a;
			v.push_back(a);
		}
		ll m=v[0].size();
		string ans="";
		for(int i=0;i<m;++i){
			bool flag=0;
			for(int j=0;j<n;++j){
				if(v[j][i]!=v[0][i]){
					flag=1;
				}
			}
			if(flag){
				ans+='?';
			}else{
				ans+=v[0][i];
			}
		}
		cout<<ans;
	} 
	return 0;
}