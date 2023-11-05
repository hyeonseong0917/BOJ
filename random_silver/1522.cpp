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
	int a_num=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='a'){
			++a_num;
		}
	}
	int ans=122232421;
	for(int i=0;i<s.size();++i){
		string cur_str="";
		int cur_cnt=0;
		for(int j=0;j<a_num;++j){
			cur_str+=s[(i+j)%s.size()];
		}
		for(int j=0;j<a_num;++j){
			if(cur_str[j]=='b'){
				++cur_cnt;
			}
		}
		ans=min(ans,cur_cnt);
	}
	cout<<ans;
	return 0;
}