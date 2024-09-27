#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

string cpp2java(string s){
	vector<string> v;
	string tmp="";
	for(ll i=0;i<s.size();++i){
		if(s[i]=='_'){
			v.push_back(tmp);
			tmp="";
		}else{
			tmp+=s[i];
		}
	}
	v.push_back(tmp);
	string str=v[0];
	for(ll i=1;i<v.size();++i){
		string cur_str=v[i];
		int fst_num=cur_str[0]-'a';
		char c='A'+fst_num;
		cur_str[0]=c;
		str+=cur_str;
	}
	return str;
}
string java2cpp(string s){
	vector<string> v;
	string tmp="";
	for(ll i=0;i<s.size();++i){
		if('A'<=s[i] && s[i]<='Z'){
			v.push_back(tmp);
			tmp="";
			int fst_num=s[i]-'A';
			char c='a'+fst_num;
			tmp+=c;
		}else{
			tmp+=s[i];
		}
	}
	v.push_back(tmp);
	string str=v[0];
	for(ll i=1;i<v.size();++i){
		str+='_';
		str+=v[i];
	}
	return str;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		bool is_cpp=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='_'){
				is_cpp=1;
				break;
			}
		}
		if(is_cpp){
			bool is_capital=0;
			for(ll i=0;i<s.size();++i){
				if(s[i]=='_') continue;
				if('A'<=s[i] && s[i]<='Z'){
					is_capital=1;
					break;
				}
			}
			if(is_capital){
				// cpp인데 대문자 있음
				cout<<"Error!";
			}else{
				// cpp인데 _이 가장 처음, or 가장 마지막
				if(s[0]=='_' || s[s.size()-1]=='_'){
					cout<<"Error!";
				}else{
					// _이 붙어서 있는 경우
					bool flag=0;
					for(ll i=0;i<s.size()-1;++i){
						if(s[i]=='_' && s[i+1]=='_'){
							flag=1;
							break;
						}
					}
					if(flag){
						cout<<"Error!";
					}else{
						cout<<cpp2java(s);
					}
					
				}
				
			}
		}else{
			// java인지?
			if('A'<=s[0] && s[0]<='Z'){
				cout<<"Error!";
			}else{
				cout<<java2cpp(s);
			}
		}
		
	}
	return 0;
}