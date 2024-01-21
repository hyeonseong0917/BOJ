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
	int N;
	int M;
	string s;
	cin>>N;
	cin>>M;
	cin>>s;
	string t=""; //2N+1
	for(int i=0;i<N*2+1;++i){
		if(i%2==0){
			t+='I';
		}else{
			t+='O';
		}
	}
	int idx=0;
	int tidx=0;
	int cnt=0;
	int fst_idx=0;
	while(1){
		if(idx>=M){
			break;
		}

		if(s[idx]==t[tidx]){
			++tidx;
			// cout<<idx<<endl;
			if(tidx==N*2+1){
				++cnt;
				tidx=0;
				while(1){
					if(idx+2>=M){
						break;
					}
					if(s.substr(idx+1,2)=="OI"){
						++cnt;
						idx+=2;
					}else{
						break;
					}
				}
			}else{
				++idx;
			}
		}else{
			if(tidx==0){
				++idx;
			}else{
				tidx=0;	
			}
		}
	}
	cout<<cnt;
	return 0;
}