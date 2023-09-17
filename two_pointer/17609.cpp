#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int isPal(int L, int R, int D, string cur_str){
	while(L<=R){
		if(cur_str[L]!=cur_str[R]){
			if(D==0){
				return 2;
			}else{
				if(isPal(L+1,R,D-1,cur_str)==0 || isPal(L,R-1,D-1,cur_str)==0){
					return 1;
				}else{
					return 2;
				}
			}
		}else{
			++L;
			--R;
		}
	}
	return 0;
}

int main() {
	// your code goes here
	int t=0;
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<isPal(0,s.size()-1,1,s)<<"\n";
		
	}
	
	// cout<<bfs(v);
	return 0;
}