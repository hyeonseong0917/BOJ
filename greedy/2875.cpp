#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N,M,K;
	cin>>N>>M>>K;
	// 6 3 2
	// 5 3 2
	// 6 10 3
	if(N-K>=M*2){
		cout<<M;
	}else if(N-K<M*2){
		while(K){
			--K;
			if(N<M*2){
				--M;
			}else if(N>=M*2){
				--N;
			}
		}
		cout<<min(N/2,M);
	}
	
	
	
	
	return 0;
}