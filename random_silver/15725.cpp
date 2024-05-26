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
	int pos=-1;
	for(int i=0;i<s.size();++i){
		if(s[i]=='x'){
			pos=i;
			break;
		}
	}
	if(pos==0){
		cout<<1;
	}else if(pos==-1){
		cout<<0;
	}else{
		string t=s.substr(0,pos);
		if(t=="-"){
			cout<<-1;
		}else{
			cout<<s.substr(0,pos);	
		}
	}
	return 0;
}