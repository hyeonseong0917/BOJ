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
	cin>>o;
	cin.ignore();
	while(o--){
		string s;
		getline(cin,s);
		char c=s[0];
		if(s[0]>='A' && s[0]<='Z'){
			cout<<s<<"\n";
			continue;
		}
		ll d=c-'a';
		c='A'+d;
		s[0]=c;
		cout<<s<<"\n";
	}
	
	
	
	
	return 0;
}