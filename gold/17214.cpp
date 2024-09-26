#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define ll long long


string a_integ(string s){
	string str="";
	bool is_minus=0;
	if(s[0]=='-'){
		s=s.substr(1);
		is_minus=1;
	}
	if(stoi(s)==2){
		if(is_minus){
			str+='-';
			str+="xx";
		}else{
			str+="xx";
		}
		return str;
	}
	string a_num=s.substr(0,s.size()-1);
	int a=stoi(a_num);
	a/=2;
	if(is_minus){
		str+='-';
	}
	str+=to_string(a);
	str+="xx";
	return str;

}
string b_integ(string s){
	if(s=="0"){
		return "";
	}
	string str="";
	bool is_minus=0;
	if(s[0]=='-'){
		is_minus=1;
		s=s.substr(1);
	}
	int b=stoi(s);
	if(is_minus){
		str+='-';
	}
	if(b==1 || b==-1){
		str+='x';
		return str;
	}
	str+=to_string(b);
	str+='x';
	return str;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		// 단일항인지?
		bool is_plus_exist=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='+'){
				is_plus_exist=1;
				break;
			}
		}
		bool is_minus_exist=0;
		for(int i=1;i<s.size();++i){
			if(s[i]=='-'){
				is_minus_exist=1;
				break;
			}
		}
		if(is_plus_exist || is_minus_exist){
			string tmp=s.substr(s.size()-2,2);
			if(tmp=="+0" || tmp=="-0"){
				s=s.substr(0,s.size()-2);
				bool is_x_exist=0;
				for(int i=0;i<s.size();++i){
					if(s[i]=='x'){
						is_x_exist=1;
						break;
					}
				}
				if(is_x_exist){
					cout<<a_integ(s)<<"+W";
				}else{
					cout<<b_integ(s)<<"+W";
				}
			}else{
				char c;
				string a_str="";
				string b_str="";
				for(int i=1;i<s.size();++i){
					if(s[i]=='+' || s[i]=='-'){
						c=s[i];
						a_str=s.substr(0,i);
						b_str=s.substr(i+1);
						break;
					}
				}
				cout<<a_integ(a_str)<<c<<b_integ(b_str)<<"+W";
			}
		}else{
			// 단일항
			
			// x가 있는지?
			bool is_x_exist=0;
			for(int i=0;i<s.size();++i){
				if(s[i]=='x'){
					is_x_exist=1;
					break;
				}
			}
			if(is_x_exist){
				cout<<a_integ(s)<<"+W";
			}else{
				if(s=="0"){
					cout<<"W";
				}else{
					cout<<b_integ(s)<<"+W";
				}
			}

		}

	}
	return 0;
}
