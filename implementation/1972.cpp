#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> input_str;

void Input(){
	while(1){
		string s="";
		cin>>s;
		if(s=="*"){
			break;
		}
		input_str.push_back(s);
		
	}
}
bool isSurprise(string cur_str){
	bool flag=0;
	int N=cur_str.size();
	for(int i=0;i<=N-2;++i){
		//i는 길이-1, i+1은 길이
		map<string,int> isExist;
		for(int j=0;j+i+1<N;++j){
			string tmp="";
			tmp+=cur_str[j];
			tmp+=cur_str[j+i+1];
			// cout<<i<<" "<<j<<" "<<tmp<<endl;
			if(isExist[tmp]==0){
				isExist[tmp]=1;
			}else{
				return 0;
			}
		}
	}
	return 1;
}
void solve(){
	
	for(int i=0;i<input_str.size();++i){
		string cur_str=input_str[i];
		if(isSurprise(cur_str)){
			cout<<cur_str<<" is surprising."<<"\n";
		}else{
			cout<<cur_str<<" is NOT surprising."<<"\n";
		}
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}