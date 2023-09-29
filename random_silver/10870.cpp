#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


int fib(int num){
	if(num<=1){
		if(num==0){
			return 0;
		}else{
			return 1;
		}
	}
	return fib(num-1)+fib(num-2);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n=0;
	cin>>n;
	cout<<fib(n);
	return 0;
}