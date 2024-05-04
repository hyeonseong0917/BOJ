#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

vector<int> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,K;
	cin>>N>>K;
	string s;
	cin>>s;
	string tmp="";
	for(int i=0;i<s.size();++i){
		if(s[i]==','){
			v.push_back(stoi(tmp));
			tmp="";
		}else{
			tmp+=s[i];	
		}
	}
	v.push_back(stoi(tmp));
	vector<int> ans;
	for(int i=0;i<v.size();++i){
		ans.push_back(v[i]);
	}
	while(K--){
		ans.clear();
		for(int i=0;i<v.size()-1;++i){
			ans.push_back(v[i+1]-v[i]);
		}
		v=ans;
	}
	for(int i=0;i<ans.size();++i){
		cout<<ans[i];
		if(i!=ans.size()-1){
			cout<<",";
		}
	}
	return 0;
}