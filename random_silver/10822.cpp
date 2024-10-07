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
	ll o=1;
	while(o--){
		string tmp="";
		int sum=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]==','){
				sum+=stoi(tmp);
				tmp="";
			}else{
				tmp+=s[i];
			}
		}
		sum+=stoi(tmp);
		cout<<sum;
	}
	return 0;
}