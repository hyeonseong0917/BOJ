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
		// 1 ~ 641
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll idx=n-1;
		ll ans=0;
		while(idx>=0){
			if(idx<=1){
				++ans;
				break;
			}
			string fst_str="";
			if(s[idx]!='0'){
				fst_str=s.substr(idx,1);
			}
			string sed_str="";
			string trd_str="";
			if(idx-1>=0){
				if(s[idx-1]!='0'){
					sed_str=s.substr(idx-1,2);
				}
			}
			if(idx-2>=0){
				if(s[idx-2]!='0'){
					trd_str=s.substr(idx-2,3);
				}
			}
			ll c=0;
			if(fst_str!=""){
				c=1;
			}
			if(sed_str!=""){
				c=2;
			}
			if(trd_str!="" && stoi(trd_str)<=641){
				c=3;
			}
			++ans;
			idx-=c;
		}
		cout<<ans;
	} 
	return 0;
}