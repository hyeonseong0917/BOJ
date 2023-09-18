#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX=500+1;

int f[40+1];
int fib_cnt=1, fibo_cnt=0;
// 5 4 3 3 2 2 1
int fib(int n){
	if(n==1 || n==2){
		return 1;
	}
	++fib_cnt;
	return fib(n-1)+fib(n-2);
}

int fibo(int n){
	if(n<=2){
		
		return 1;
	}
	
	if(f[n]){
		return f[n];
	}else{
		++fibo_cnt;
		return f[n]=fibo(n-1)+fibo(n-2);
	}

}

int main() {
	// your code goes here
	int n=0;
	cin>>n;
	for(int i=0;i<40+1;++i){
		f[i]=0;
	}
	fib(n);
	fibo(n);
	cout<<fib_cnt<<" "<<fibo_cnt;
	return 0;
}