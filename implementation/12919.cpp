#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string S,T;
map<string,int> m;
void Input(){
	cin>>S;
	cin>>T;
}
bool flag=0;
void dfs(string cur_str){
	if(cur_str.size()==S.size()){
		if(cur_str.compare(S)==0){
			flag=1;
		}
		return;
	}
	
	if(cur_str[cur_str.size()-1]=='A'){
		dfs(cur_str.substr(0,cur_str.size()-1));
	}
	string new_str=cur_str;
	reverse(new_str.begin(),new_str.end());
	if(new_str[new_str.size()-1]=='B'){
		new_str=new_str.substr(0,new_str.size()-1);
		dfs(new_str);
	}
	
	
}
void solve(){
	dfs(T);
	if(flag==1){
		cout<<1;
	}else{
		cout<<0;
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}