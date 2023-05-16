#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1337
string s;
void Input(){
	getline(cin,s);
}
void solve(){
	string ans="";
	string cur_add="";
	int idx=0;
	bool isTag=0;
	int N=s.size();
	while(1){
		if(idx==N){
			break;
		}
		if(isTag==0){
			if(s[idx]!='<'){
				cur_add+=s[idx];
				
			}else{
				isTag=1;
				string seg_str="";
				for(int i=0;i<cur_add.size();++i){
					if(cur_add[i]==' '){
						for(int j=seg_str.size()-1;j>=0;--j){
							ans+=seg_str[j];
						}
						ans+=' ';
						seg_str="";
					}else{
						seg_str+=cur_add[i];
					}
				}
				if(seg_str!=""){
					for(int j=seg_str.size()-1;j>=0;--j){
						ans+=seg_str[j];
					}
					seg_str="";
				}
				cur_add="";
				cur_add+='<';
			}
		}else{
			if(s[idx]!='>'){
				cur_add+=s[idx];
			}else{
				isTag=0;
				for(int i=0;i<cur_add.size();++i){
					ans+=cur_add[i];
				}
				ans+='>';
				cur_add="";
			}
		}
		++idx;
		
	}
	if(cur_add!=""){
		string seg_str="";
		for(int i=0;i<cur_add.size();++i){
			if(cur_add[i]==' '){
				for(int j=seg_str.size()-1;j>=0;--j){
					ans+=seg_str[j];
				}
				ans+=' ';
				seg_str="";
			}else{
				seg_str+=cur_add[i];
			}
		}
		if(seg_str!=""){
			for(int i=seg_str.size()-1;i>=0;--i){
				ans+=seg_str[i];
			}
		}
		
	}
	cout<<ans;
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}