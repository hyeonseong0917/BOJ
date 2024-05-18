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
	int cnt=1;
	while(1){
		string s;
		cin>>s;
		if(s=="0"){
			break;
		}
		if(s[0]!='1' || s[s.size()-1]!='2' || s.size()<2){
			cout<<cnt<<". "<<"NOT"<<"\n";
		}else{
			bool flag=0;
			for(int i=1;i<s.size()-1;++i){
				if(s[i]=='1' || s[i]=='0'){
					flag=1;
					break;
				}
			}
			if(flag){
				cout<<cnt<<". "<<"NOT"<<"\n";	
			}else{
				bool flag=0;
				for(int i=1;i<s.size();++i){
					char pre_num=s[i-1];
					if(s[i]=='3'){
						if(pre_num!='4' && pre_num!='6'){
							flag=1;
							break;
						}
					}else if(s[i]=='4'){
						if(pre_num!='1' && pre_num!='3'){
							// cout<<pre_num;
							flag=1;
							break;
						}
					}else if(s[i]=='5'){
						if(pre_num!='1' && pre_num!='3'){
							flag=1;
							break;
						}
					}else if(s[i]=='6'){
						if(pre_num!='8'){
							flag=1;
							break;
						}
					}else if(s[i]=='7'){
						if(pre_num!='8'){
							flag=1;
							break;
						}
					}else if(s[i]=='8'){
						if(pre_num!='5' && pre_num!='7'){
							flag=1;
							break;
						}
					}else if(s[i]=='2'){
						if(pre_num!='4' && pre_num!='6'){
							flag=1;
							break;
						}
					}
				}
				if(flag){
					cout<<cnt<<". "<<"NOT"<<"\n";		
				}else{
					cout<<cnt<<". "<<"VALID"<<"\n";
					
				}
			}
		}




		++cnt;
	}

	
	return 0;
}