#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string first_str,res;
		vector<char> v;
		for(int i=s.size()-1;i>=0;--i){
			if(s[i]<s[i+1]){
				first_str=s.substr(0,i);
				string ns=s.substr(i);
				int c=ns[0]-'0';
				sort(ns.begin(),ns.end());
				// string res;
				for(int j=0;j<ns.size();++j){
					if(ns[j]-'0'>c){
						v.push_back(ns[j]);
						// res+=ns[j];
						
						break;
					}
				}
				bool flag=0;
				for(int j=0;j<ns.size();++j){
					if(ns[j]==v[0]){
						if(flag==0){
							flag=1;
						}else{
							v.push_back(ns[j]);
							// res+=ns[j];
						}
					}else{
						// res+=ns[j];
						v.push_back(ns[j]);
					}
				}
				// cout<<res<<"\n";
				break;
			}
		}
		if(v.size()){
			// cout<<first_str<<"\n";
			for(int i=0;i<v.size();++i){
				first_str+=v[i];
			}
			cout<<first_str<<"\n";
		}else{
			cout<<s<<"\n";
		}
	}
	return 0;
}