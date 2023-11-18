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
	string s;
	cin>>s;
	string ans="";
	int idx=0;
	bool is_minus=0;
	while(idx<s.size()){
		// cout<<idx<<" "<<s<<endl;
		if(s[idx]=='.'){
			ans+=s[idx];
			++idx;
		}else{
			bool flag=1;
			// AAAA가능한지?
			if(idx+4<=s.size()){
				for(int i=idx;i<idx+4;++i){
					if(s[i]!='X'){
						flag=0;
						break;
					}
				}	
			}else{
				flag=0;
			}
			if(flag){
				ans+="AAAA";
				idx+=4;
				continue;
			}
			// BB가능한지?
			flag=1;
			if(idx+2<=s.size()){
				for(int i=idx;i<idx+2;++i){
					if(s[i]!='X'){
						flag=0;
						break;
					}
				}
			}else{
				flag=0;
			}
			if(flag){
				ans+="BB";
				idx+=2;
				continue;
			}
			is_minus=1;
			break;
		}
		
	}
	if(is_minus){
		cout<<-1;
	}else{
		cout<<ans;
	}
	
	return 0;
}