#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string fst_str, sed_str;
		ll idx=-1;
		for(ll i=0;i<s.size();++i){
			if(s[i]==','){
				idx=i;
				break;
			}
		}
		fst_str=s.substr(0,idx);
		sed_str=s.substr(idx+1);
		ll fst_num=stoll(fst_str);
		ll sed_num=stoll(sed_str);
		cout<<fst_num+sed_num<<"\n";
	}
	return 0;
}