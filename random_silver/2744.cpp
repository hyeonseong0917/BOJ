#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		
		string s;
		cin>>s;
		for(ll i=0;i<s.size();++i){
			if(s[i]>='a' && s[i]<='z'){
				s[i]='A'+(s[i]-'a');
			}else{
				s[i]='a'+(s[i]-'A');
			}
		}
		cout<<s;
		
	}
	
	
	
	
	return 0;
}