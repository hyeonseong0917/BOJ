#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

map<char,int> m;
vector<char> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();++i){
		if(!m[s[i]]){
			v.push_back(s[i]);
		}
		++m[s[i]];
	}
	for(int i=0;i<v.size();++i){
		if(m[v[i]]%2==1){
			++cnt;
		}
		// cout<<v[i]<<" "<<m[v[i]]<<endl;
	}
	sort(v.begin(),v.end());
	if(cnt>=2){
		cout<<"I'm Sorry Hansoo";
	}else{
		if(cnt){
			char c;
			for(int i=0;i<v.size();++i){
				// cout<<v[i]<<" "<<m[v[i]]<<endl;
				if(m[v[i]]%2==1){
					c=v[i];
					--m[v[i]];
					break;
				}
			}
			string fst_str="";
			for(int i=0;i<v.size();++i){
				char t=v[i];
				if(!m[t]) continue;
				for(int j=0;j<m[t]/2;++j){
					fst_str+=t;
				}
			}
			string sed_str=fst_str;
			reverse(sed_str.begin(),sed_str.end());
			cout<<fst_str+c+sed_str;
		}else{
			string fst_str="";
			for(int i=0;i<v.size();++i){
				char t=v[i];
				if(!m[t]) continue;
				for(int j=0;j<m[t]/2;++j){
					fst_str+=t;
				}
			}
			string sed_str=fst_str;
			reverse(sed_str.begin(),sed_str.end());
			cout<<fst_str+sed_str;
		}
	}
	return 0;
}