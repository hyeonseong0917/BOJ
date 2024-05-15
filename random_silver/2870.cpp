#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

bool comp(string a, string b){
	if(a.size()==b.size()){
		for(int i=0;i<a.size();++i){
			if(a[i]==b[i]) continue;
			return a[i]<b[i];
		}
	}
	return a.size()<b.size();
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		vector<string> v;
		int N;
		cin>>N;
		while(N--){
			string s;
			cin>>s;
			string tmp_str="";
			for(int i=0;i<s.size();++i){
				if(s[i]>='0' && s[i]<='9'){
					tmp_str+=s[i];
				}else{
					if(!tmp_str.empty()){
						int idx=0;
						for(int j=0;j<tmp_str.size()-1;++j){
							if(tmp_str[j]=='0'){
								++idx;
							}else{
								break;
							}
						}
						tmp_str=tmp_str.substr(idx,tmp_str.size()-idx+1);
						v.push_back(tmp_str);
						tmp_str="";
					}
				}
			}
			if(!tmp_str.empty()){
				int idx=0;
				for(int j=0;j<tmp_str.size()-1;++j){
					if(tmp_str[j]=='0'){
						++idx;
					}else{
						break;
					}
				}
				tmp_str=tmp_str.substr(idx,tmp_str.size()-idx+1);
				v.push_back(tmp_str);
				tmp_str="";
			}

		}
		sort(v.begin(),v.end(),comp);
		for(int i=0;i<v.size();++i){
			cout<<v[i]<<"\n";
		}
	}
	return 0;
}