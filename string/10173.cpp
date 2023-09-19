#include <iostream>
#include <vector>
using namespace std;


vector<string> v;
int main() {
	// your code goes here
	while(1){
		string s="";
		getline(cin,s);
		if(s=="EOI") break;
		v.clear();
		for(int i=0;i<s.size();++i){
			if(s[i]>='A' && s[i]<='Z'){
				s[i]+=32;
			}
		}
		string tmp="";
		for(int i=0;i<s.size();++i){
			if(s[i]==' '){
				v.push_back(tmp);
				tmp="";
			}else{
				if('a'<=s[i] && s[i]<='z'){
					tmp+=s[i];	
				}
			}
		}
		if(tmp!=""){
			v.push_back(tmp);
		}
		bool flag=0;
		for(int i=0;i<v.size();++i){
			if(v[i]=="nemo"){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"Found"<<"\n";
		}else{
			cout<<"Missing"<<"\n";
		}
		
	}
	
	return 0;
}