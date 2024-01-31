#include <iostream>
#include <stack>
using namespace std;

int main() {
	// your code goes here
	int a=1;
	while(1){
		string s;
		cin>>s;
		if(s[0]=='-'){
			break;
		}
		stack<char> st;
		int cnt=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='{'){
				st.push(s[i]);
			}else{
				if(!st.empty()){
					st.pop();
				}else{
					++cnt;
					st.push('{');
				}
			}
		}
		if(st.empty()){
			cout<<a<<". "<<cnt<<"\n";	
		}else{
			cout<<a<<". "<<cnt+st.size()/2<<"\n";
		}
		++a;
		
	}
	return 0;
}