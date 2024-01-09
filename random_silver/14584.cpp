#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s;
	int N;
	cin>>s;
	cin>>N;
	int diff=-1;
	string ans="";
	for(int i=0;i<N;++i){
		string t;
		cin>>t;
		for(int j=0;j<26;++j){
			string tmp=s;
			// j칸 뒤로 이동
			for(int k=0;k<tmp.size();++k){
				int a=tmp[k]-'a'-j+26;
				tmp[k]='a'+a%26;
			}
			map<string,int> MAP;
			for(int k=0;k<tmp.size();++k){
				string cur_str="";
				for(int m=1;m+k<=tmp.size();++m){
					cur_str=tmp.substr(k,m);
					if(cur_str==t){
						ans=tmp;
					}
					
				}
			}
		}

	}
	cout<<ans;
	// cout<<diff<<endl;

	return 0;
}