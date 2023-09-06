#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int N,M;
bool isPrimeNum(int num){
	if(num==1){
		return 0;
	}
	if(num==2){
		return 1;
	}
	int m=sqrt(num);
	for(int i=2;i<=m;++i){
		if(num%i==0){
			return 0;
		}
	}
	return 1;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=N;i<=M;++i){
		if(isPrimeNum(i)){
			cout<<i<<"\n";
		}
	}	
	return 0;
}