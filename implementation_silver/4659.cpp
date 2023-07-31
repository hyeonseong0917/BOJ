#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	vector<int> M(27,0);
	char moem[5+1]={'a','e','i','o','u'};
	while(1){
		string s="";
		cin>>s;
		if(s=="end"){
			break;
		}
		int N=s.size();
		bool flag=0;
		for(int i=0;i<s.size();++i){
			for(int j=0;j<5;++j){
				if(s[i]==moem[j]){
					flag=1;
					break;
				}
			}
		}
		if(flag==0){
			cout<<"<"<<s<<"> is not acceptable."<<"\n";
			continue;
		}
		for(int i=0;i<5;++i){
			M[moem[i]-'a']=1;
		}
		for(int i=0;i<N-2;++i){
			if((M[s[i]-'a']==1 && M[s[i+1]-'a']==1 && M[s[i+2]-'a']==1) || (M[s[i]-'a']==0 && M[s[i+1]-'a']==0 && M[s[i+2]-'a']==0)){
				flag=0;
				break;
			}
		}
		
		if(flag==0){
			cout<<"<"<<s<<"> is not acceptable."<<"\n";
			continue;
		}
		flag=1;
		for(int i=0;i<N-1;++i){
			string cur_str=s.substr(i,2);
			if(cur_str[0]==cur_str[1]){
				if(cur_str!="ee" && cur_str!="oo"){
					flag=0;
					break;
				}
			}
		}
		if(flag==0){
			cout<<"<"<<s<<"> is not acceptable."<<"\n";
			continue;
		}
		cout<<"<"<<s<<"> is acceptable."<<"\n";
	}
	return 0;
}