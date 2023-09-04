#include <iostream>
#include <vector>
using namespace std;

int N,M=0;

bool isPrime(int num){
	if(num==1){
		return 0;
	}
	for(int i=2;i<num;++i){
		if(num%i==0){
			return 0;
		}
	}
	return 1;
}

int main() {
	// your code goes here
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	int cnt=0;
	for(int i=0;i<N;++i){
		if(isPrime(v[i])){
			++cnt;
		}
	}
	cout<<cnt;
	
	
	return 0;
}