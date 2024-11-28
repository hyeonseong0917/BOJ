#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		vector<string> v;
		string tmp;
		while(1){
			string s;
			getline(cin,s);
			tmp+=s;
			if(tmp.compare(".")==0) break;
			if(s[s.size()-1]=='.'){
				v.push_back(tmp);
				// cout<<tmp<<endl;
				tmp="";
			}
		}
		
		for(ll i=0;i<v.size();++i){
			string s=v[i];
			stack<char> st;
			bool flag=0;
			for(ll j=0;j<s.size();++j){
				if(s[j]=='(' || s[j]=='['){
					st.push(s[j]);
				}
				if(s[j]==')' || s[j]==']'){
					if(st.empty()){
						flag=1;
						break;
					}else{
						char c=st.top();
						st.pop();
						if(c=='(' && s[j]==']'){
							flag=1;
							break;
						}
						if(c=='[' && s[j]==')'){
							flag=1;
							break;
						}
					}
				}
			}
			if(!st.empty()) flag=1;
			if(flag){
				cout<<"no"<<"\n";
			}else{
				cout<<"yes"<<"\n";
			}
		}
	}
	return 0;
}