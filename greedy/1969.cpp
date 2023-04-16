#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

//0118
int main() {
	// your code goes here
	int N,M=0;
	cin>>N>>M;
	string board[1000+1];
	for(int i=0;i<N;++i){
		cin>>board[i];
	}
	string ans="";
	for(int i=0;i<M;++i){
		map<char,int> m;
		int maxNum=-1;
		for(int j=0;j<N;++j){
			char cur_c=board[j][i];
			++m[cur_c];
			maxNum=max(maxNum,m[cur_c]);
		}
		for(int j=0;j<26;++j){
			char cur_c='A'+j;
			if(m[cur_c]==maxNum){
				ans+=cur_c;
				break;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]!=ans[j]){
				++cnt;	
			}
		}
	}
	cout<<ans<<endl;
	cout<<cnt;
	return 0;
}