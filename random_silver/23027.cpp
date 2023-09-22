#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s;
	cin>>s;
	bool isA=0, isB=0, isC=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='A'){
			isA=1;
		}
		if(s[i]=='B'){
			isB=1;
		}
		if(s[i]=='C'){
			isC=1;
		}
	}
	if(isA){
		for(int i=0;i<s.size();++i){
			if(s[i]=='B' || s[i]=='C' || s[i]=='D' || s[i]=='F'){
				s[i]='A';
			}
		}
	}else{
		if(isB){
			for(int i=0;i<s.size();++i){
				if(s[i]=='C' || s[i]=='D' || s[i]=='F'){
					s[i]='B';
				}
			}
		}else{
			if(isC){
				for(int i=0;i<s.size();++i){
					if(s[i]=='D' || s[i]=='F'){
						s[i]='C';
					}
				}	
			}else{
				for(int i=0;i<s.size();++i){
					s[i]='A';
				}
			}
		}
	}
	cout<<s;
	return 0;
}