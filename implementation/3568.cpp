#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;

void Input(){
	getline(cin,s);
}
string def_str="";
int idx=0;
vector<string> v;
void solve(){
	for(int i=0;i<s.size();++i){
		++idx;
		if(s[i]==' '){
			break;
		}
		def_str+=s[i];
	}
	// cout<<def_str;
	string tmp_str="";
	for(int i=idx;i<s.size();++i){
		if(s[i]==',' || s[i]==';'){
			v.push_back(tmp_str);
			tmp_str="";
			continue;
		}
		if(s[i]==' ') continue;
		tmp_str+=s[i];
	}
	// for(int i=0;i<v.size();++i){
	// 	cout<<v[i]<<" ";
	// }
	for(int i=0;i<v.size();++i){
		string cur_str=v[i];
		// cout<<cur_str<<endl;
		int ref_num=0;
		int list_num=0;
		int pointer_num=0;
		string str_name="";
		bool flag=0;
		for(int j=0;j<cur_str.size();++j){
			if(cur_str[j]=='&'){
				++ref_num;
			}else if(cur_str[j]=='['){
				++list_num;
			}else if(cur_str[j]=='*'){
				++pointer_num;
			}else if(cur_str[j]!=']' && flag==0){
				flag=1;
				for(int k=j;k<cur_str.size();++k){
					if(cur_str[k]=='&' || cur_str[k]=='[' || cur_str[k]==']' || cur_str[k]=='*') break;
					str_name+=cur_str[k];
				}
			}
		}
		string to_add=def_str;
		for(int j=cur_str.size()-1;j>=0;--j){
			if(cur_str[j]=='*'){
				to_add+='*';
			}else if(cur_str[j]==']'){
				to_add+="[]";
			}else if(cur_str[j]=='['){
				continue;
			}else if(cur_str[j]=='&'){
				to_add+='&';
			}else{
				break;
			}
		}
		
		
		to_add+=" ";
		to_add+=str_name;
		to_add+=';';
		cout<<to_add<<endl;
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}