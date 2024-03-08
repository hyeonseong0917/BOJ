#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,K;
	cin>>N>>K;
	string s;
	cin>>s;
	// 1조건 확인
	// int N=s.size();
	for(int i=0;i<K;++i){
		string tmp="";
		for(int j=0;j<N;++j){
			int pre_idx=(j+N-1)%N;
			int cur_idx=j;
			int next_idx=(j+N+1)%N;
			if((s[pre_idx]==s[cur_idx] && s[cur_idx]==s[next_idx]) || (s[pre_idx]!=s[cur_idx] && s[cur_idx]!=s[next_idx] && s[pre_idx]!=s[next_idx])){
				// s[j]='B';
				tmp+='B';
			}else{
				bool flag=0;
				if(s[pre_idx]==s[cur_idx]){
					if(s[pre_idx]=='R' && s[next_idx]=='G'){
						flag=1;
					}
					if(s[pre_idx]=='G' && s[next_idx]=='B'){
						flag=1;
					}
					if(s[pre_idx]=='B' && s[next_idx]=='R'){
						flag=1;
					}
				}else if(s[cur_idx]==s[next_idx]){
					if(s[cur_idx]=='R' && s[pre_idx]=='G'){
						flag=1;
					}
					if(s[cur_idx]=='G' && s[pre_idx]=='B'){
						flag=1;
					}
					if(s[cur_idx]=='B' && s[pre_idx]=='R'){
						flag=1;
					}
				}else if(s[pre_idx]==s[next_idx]){
					if(s[pre_idx]=='R' && s[cur_idx]=='G'){
						flag=1;
					}
					if(s[pre_idx]=='G' && s[cur_idx]=='B'){
						flag=1;
					}
					if(s[pre_idx]=='B' && s[cur_idx]=='R'){
						flag=1;
					}
				}
				if(!flag){
					tmp+='G';
				}else{
					tmp+='R';
				}
					
			}			
		}
		s=tmp;
		// cout<<s<<"\n";
	}
	int R=0,G=0,B=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='R'){
			++R;
		}else if(s[i]=='G'){
			++G;
		}else{
			++B;
		}
	}
	cout<<R<<" "<<G<<" "<<B;
	
	return 0;
}