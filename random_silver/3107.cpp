#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>t;
	while(o--){
		// 1256
		string s;
		cin>>s;
		vector<string> v;
		string tmp="";
		for(ll i=0;i<s.size();++i){
			if(s[i]==':'){
				v.push_back(tmp);
				tmp="";
			}else{
				tmp+=s[i];
			}
		}
		
		v.push_back(tmp);
		if(v.size()!=8){
			vector<string> c;
			bool flag=0;
			for(ll i=0;i<v.size();++i){
				if(!flag && v[i]==""){
					flag=1;
					for(ll j=0;j<9-v.size();++j){
						c.push_back("0000");
					}
				}else{
					c.push_back(v[i]);
				}
			}
			v=c;
		}
		for(ll i=0;i<v.size();++i){
			string cur_str=v[i];
			string next_str="";
			for(ll j=0;j<4-cur_str.size();++j){
				next_str+='0';
			}
			next_str+=cur_str;
			v[i]=next_str;
		}
		for(ll i=0;i<v.size();++i){
			string cur_str=v[i];
			if(i!=v.size()-1){
				cur_str+=':';
			}
			cout<<cur_str;
		}
		
		
	} 
	return 0;
}