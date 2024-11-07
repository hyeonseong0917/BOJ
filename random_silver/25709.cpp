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
		while(s!=""){
			// 다 0인지
			// cout<<cnt<<" "<<s<<endl;
			bool is_all_zero=1;
			for(ll i=0;i<s.size();++i){
				if(s[i]!='0'){
					is_all_zero=0;
					break;
				}
			}
			if(is_all_zero) break;

			// 1제거
			string new_str="";
			for(ll i=0;i<s.size();++i){
				if(s[i]!='1'){
					new_str+=s[i];
				}else{
					++cnt;
				}
			}
			s=new_str;

			// 앞에서 1인지?
			if(s[0]=='1'){
				++cnt;
				ll last_idx=-1;
				for(ll i=1;i<s.size();++i){
					if(s[i]!='0'){
						last_idx=i;
						break;
					}
				}
				if(last_idx==-1){
					break;
				}else{
					s=s.substr(last_idx);
				}
			}else{
				if(s[s.size()-1]=='1'){
					++cnt;
					s=s.substr(0,s.size()-1);
				}else{
					++cnt;
					ll cur_num=stoll(s);
					cur_num-=1;
					s=to_string(cur_num);
				}
			}
		}
		cout<<cnt;	
	}
	return 0;
}