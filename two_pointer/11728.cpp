#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
const int MAX=1000000+1;
int A[MAX];
int B[MAX];
int C[MAX*2];
int N,M;
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
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	for(int i=0;i<M;++i){
		cin>>B[i];
	}
	int ap=0, bp=0;
	int cp=0;
	while(1){
		if(ap>=N && bp>=M){
			break;
		}
		if(ap==N && bp!=M){
			C[cp++]=B[bp++];
			continue;
		}
		if(ap!=N && bp==M){
			C[cp++]=A[ap++];
			continue;
		}
		if(A[ap]<B[bp]){
			C[cp++]=A[ap++];
		}else if(A[ap]>B[bp]){
			C[cp++]=B[bp++];
		}else{
			C[cp++]=A[ap++];
			C[cp++]=B[bp++];
		}
	}
	for(int i=0;i<cp;++i){
		cout<<C[i]<<" ";
	}
	return 0;
}