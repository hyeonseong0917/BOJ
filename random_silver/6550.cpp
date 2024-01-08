#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s,t;
	while(cin>>s && cin>> t){
		int s_idx=0, t_idx=0;
		bool flag=0;
		while(s_idx<s.size()){
			while(t_idx<t.size()){
				if(s[s_idx]==t[t_idx]){
					++s_idx;
					++t_idx;
				}else{
					++t_idx;
				}
				if(s_idx==s.size()){
					break;
				}

			}
			
			if(s_idx==s.size() && t_idx<=t.size()){
				flag=1;
				break;
			}
			if(t_idx==t.size()){
				break;
			}
		}
		if(flag){
			cout<<"Yes"<<"\n";
		}else{
			cout<<"No"<<"\n";
		}
	}
	return 0;
}