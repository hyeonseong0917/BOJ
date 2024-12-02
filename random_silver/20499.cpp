#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		vector<ll> v;
		string tmp="";
		for(ll i=0;i<s.size();++i){
			if(s[i]=='/'){
				v.push_back(stoll(tmp));
				tmp="";
			}else{
				tmp+=s[i];
			}
		}
		v.push_back(stoll(tmp));
		if(v[0]+v[2]<v[1] || v[1]==0){
			cout<<"hasu";
		}else{
			cout<<"gosu";
		}
	}
	return 0;
}