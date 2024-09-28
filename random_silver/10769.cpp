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
	ll happy=0, sad=0;
	while(cin>>s){
		if(s.size()<3) continue;
		// s.size()>=3
		for(ll i=0;i<=s.size()-3;++i){
			string tmp=s.substr(i,3);
			if(tmp.compare(":-)")==0){
				++happy;
			}
			if(tmp.compare(":-(")==0){
				++sad;
			}
		}
		
	}
	if(happy==0 && sad==0){
		cout<<"none";
	}else{
		if(happy<sad){
			cout<<"sad";
		}else if(happy>sad){
			cout<<"happy";
		}else{
			cout<<"unsure";
		}
	}

	return 0;
}