#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,K;
	cin>>N>>K;
	string s;
	cin>>s;
	bool visited[20000+1]={0,};
	int cnt=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='P'){
			for(int j=i-K;j<=i+K;++j){
				// cout<<i<<" "<<j<<endl;
				if(j>=s.size() || j<0){
					// cout<<i<<" "<<j<<endl;
					// break;
					continue;
				}
				// cout<<i<<" "<<j<<endl;
				if(!visited[j] && s[j]=='H'){
					visited[j]=1;
					++cnt;
					break;
				}
			}
		}
	}	
	cout<<cnt;
	return 0;
}