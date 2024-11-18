#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

vector<string> v;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		ll n=s.size();
		string ans="";
		for(ll i=0;i<n;++i){
			ans+='z';
		}
		for(ll i=0;i<n;++i){
			// 첫번째부분 [0,i]
			for(ll j=i+1;j<n-1;++j){
				// 두번째 부분[i+1,j]
				// 세번째 부분[j+1,n-1]
				string fst_str=s.substr(0,i+1);
				string sed_str=s.substr(i+1,j-i);
				string trd_str=s.substr(j+1);
				reverse(fst_str.begin(),fst_str.end());
				reverse(sed_str.begin(),sed_str.end());
				reverse(trd_str.begin(),trd_str.end());
				string cur_str=fst_str+sed_str+trd_str;
				if(ans>cur_str){
					ans=cur_str;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}