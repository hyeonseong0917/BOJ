#include <iostream>
#include <cmath>
using namespace std;
//a>b
int gcd(int a, int b){
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int l=min(a,b);
		int r=max(a,b);
		cout<<(l*r)/gcd(r,l)<<"\n";
	}
	return 0;
}