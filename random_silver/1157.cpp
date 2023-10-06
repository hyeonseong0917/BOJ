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
	string s;
	cin>>s;
	map<char,int> m;
	int maxNum=-1;
	for(int i=0;i<s.size();++i){
		if('A'<=s[i] && s[i]<='Z'){
			char c='a'+(s[i]-'A');
			s[i]=c;
		}
		++m[s[i]];
	}
	// cout<<s<<endl;
	for(int i=0;i<s.size();++i){
		maxNum=max(m[s[i]],maxNum);
	}
	char c=' ';
	bool flag=0;
	for(int i=0;i<s.size();++i){
		if(m[s[i]]==maxNum){
			if(c==' '){
				c=s[i];
			}else{
				if(c!=s[i]){
					flag=1;
					break;
				}
			}
		}
	}
	if(flag){
		cout<<"?";
	}else{
		char ans='A'+(c-'a');
		cout<<ans;
	}
	return 0;
}