#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int N;
	cin>>N;
	int num=N;
	if(num==1){
		cout<<2;
		return 0;
	}
	while(1){
		bool flag=0;
		for(int i=2;i<=sqrt(num);++i){
			if(num%i==0){
				flag=1;
				break;
			}
		}
		if(flag){
			++num;	
		}else{
			bool ans=0;
			string s=to_string(num);
			string fst_str=s.substr(0,s.size()/2);
			string sed_str=s.substr(s.size()-(s.size()/2),s.size()/2);
			reverse(sed_str.begin(),sed_str.end());
			if(fst_str==sed_str){
				ans=1;
			}
			if(ans){
				cout<<num;
				break;
			}else{
				++num;
			}
			
		}
	}
	// cout<<N;
	return 0;
}