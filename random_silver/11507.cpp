#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		string s;
		cin>>s;
		map<string,ll> m;
		vector<string> v;
		string tmp="";
		for(ll i=0;i<s.size();++i){
			if(i%3==0 && i!=0){
				v.push_back(tmp);
				tmp="";
				tmp+=s[i];
				continue;
			}
			tmp+=s[i];
		}
		v.push_back(tmp);
		ll p=0,k=0,h=0,t=0;
		bool flag=0;
		for(ll i=0;i<v.size();++i){
			string cur_str=v[i];
			if(m[cur_str]){
				flag=1;
				break;
			}
			char c=cur_str[0];
			if(c=='P'){
				++p;
			}else if(c=='K'){
				++k;
			}else if(c=='H'){
				++h;
			}else{
				// cout<<"Fds"<<c<<endl;
				++t;
			}
			++m[cur_str];
		}
		if(flag){
			cout<<"GRESKA";
		}else{
			cout<<13-p<<" "<<13-k<<" "<<13-h<<" "<<13-t<<"\n";
		}
	}
	return 0;
}