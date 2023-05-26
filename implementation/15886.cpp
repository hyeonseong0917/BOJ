#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N=0;
	cin>>N;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size()-1;++i){
		if(s[i]=='E'){
			if(s[i+1]=='W'){
				++cnt;
			}
		}
	}
	cout<<cnt;
	return 0;
}