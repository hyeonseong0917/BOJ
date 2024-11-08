#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
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
		string s;
		cin>>s;
		ll cnt=0;
		while(s.compare("")!=0){
			ll idx=-1;
			for(ll i=0;i<s.size();++i){
				if(s[i]=='1'){
					idx=i;
					break;
				}
			}
			if(idx!=-1){
				string tmp="";
				for(ll i=0;i<s.size();++i){
					if(s[i]=='1'){
						++cnt;
					}else{
						tmp+=s[i];
					}
				}
				s=tmp;
			}else{
				ll cur_num=stoll(s);
				if(cur_num==0){
					break;
				}
				--cur_num;
				s=to_string(cur_num);
				++cnt;
			}
		}
		cout<<cnt;
	}
	return 0;
}