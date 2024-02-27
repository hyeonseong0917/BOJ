#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s;
	string dp[50+1];
	cin>>s;
	dp[0]=s[0];
	int N=s.size();
	for(int i=1;i<N;++i){
		string fst_str=dp[i-1]+s[i];
		string sed_str="";
		sed_str+=s[i];
		sed_str+=dp[i-1];
		if(fst_str<sed_str){
			dp[i]=fst_str;
		}else{
			dp[i]=sed_str;
		}
	}
	cout<<dp[N-1];
	return 0;
}