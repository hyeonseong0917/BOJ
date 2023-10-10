#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	// 앞에서부터 1제거, 뒤에서부터 0 제거
	string s;
	cin>>s;
	int one_cnt=0, zero_cnt=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='1'){
			++one_cnt;
		}else{
			++zero_cnt;
		}
	}
	int del_one=0, del_zero=0;
	for(int i=0;i<s.size();++i){
		if(del_one==(one_cnt/2)){
			break;
		}
		if(s[i]=='1'){
			s[i]='.';
			++del_one;
		}
	}
	string tmp="";
	// for(int i=0;i<s.size();++i){
	// 	if(s[i]!='.'){
	// 		tmp+=s[i];
	// 	}
	// }
	// s=tmp;
	for(int i=s.size()-1;i>=0;--i){
		if(del_zero==(zero_cnt/2)){
			break;
		}
		if(s[i]=='0'){
			s[i]='.';
			++del_zero;
		}
	}
	for(int i=0;i<s.size();++i){
		if(s[i]!='.'){
			tmp+=s[i];
		}
	}
	cout<<tmp;
	return 0;
}