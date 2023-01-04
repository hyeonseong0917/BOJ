#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N=0;
const int MAXVAL=100+1;
const int MAX=100000+1;
int A[MAX],B[MAX];
void solve(){
	for(int i=0;i<MAX;++i){
		A[i]=0;
		B[i]=0;
	}
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b=0;
		cin>>a>>b;
		++A[a];
		++B[b];
		vector<int> AV(MAXVAL),BV(MAXVAL);
		for(int j=0;j<MAXVAL;++j){
			AV[j]=A[j];
			BV[j]=B[j];
		}
		int Aidx=0, Bidx=100, result=0;
		
		while(Aidx<MAXVAL && Bidx>=1){
			while(Aidx<MAXVAL && AV[Aidx]==0){
				++Aidx;
			}
			while(Bidx>=1 && BV[Bidx]==0){
				--Bidx;
			}
			if(Bidx==0 || Aidx==MAXVAL){
				break;
			}
			result=max(result, Aidx+Bidx);
			if(AV[Aidx]>BV[Bidx]){
				AV[Aidx]-=BV[Bidx];
				BV[Bidx]=0;
			}else{
				BV[Bidx]-=AV[Aidx];
				AV[Aidx]=0;
			}
			
		}
		cout<<result<<"\n";
	}
	
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	solve();
	return 0;
}