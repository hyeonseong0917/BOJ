#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	
	while(t--){
		int N=0;	
		
		cin>>N;
		vector<int> v;
		vector<char> c;
		char s[2+1][100+1];
		int res=0;
		
		// cout<<N<<"\n";
		
		for(int i=0;i<2;++i){
			for(int j=0;j<N;++j){
				cin>>s[i][j];
			}
		}
		if(N==1){
			if(s[0][0]=='0'){
				cout<<0<<"\n";
			}else{
				cout<<1<<"\n";
			}
		}else{
			for(int i=0;i<N;++i){
				int curNum=s[0][i]-'0';
				if(i==0){
					if(s[0][i]-'0'>0 && s[0][i+1]-'0'>0){
						--s[0][i];
						--s[0][i+1];
						++res;
					}
				}else if(i==N-1){
					if(s[0][i]-'0'>0 && s[0][i-1]-'0'>0){
						--s[0][i];
						--s[0][i-1];
						++res;
					}
				}else{
					if(s[0][i-1]-'0'>0 && s[0][i]-'0'>0 && s[0][i+1]-'0'>0){
						--s[0][i-1];
						--s[0][i];
						--s[0][i+1];
						++res;
					}
				}
			}
		}
		
		cout<<res<<"\n";
	}
	return 0;
}