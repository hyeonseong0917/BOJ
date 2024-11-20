#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s;
		cin>>s;
		int cnt=0;
		while(1){
			if(s.size()==1){
				cout<<cnt<<"\n";
				if(s=="3" || s=="6" || s=="9"){
					cout<<"YES";
				}else{
					cout<<"NO";
				}
				break;
			}
			int a=0;
			for(int i=0;i<s.size();++i){
				a+=(s[i]-'0');
			}
			s=to_string(a);
			++cnt;
		}
	}
	return 0;
}