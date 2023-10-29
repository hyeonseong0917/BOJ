#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long


// a<b
int gcd(int a, int b){
	if(b%a==0){
		return a;
	}

	return gcd(b%a, a);
}

int lcm(int a, int b){
	int cur_gcd=gcd(min(a,b),max(a,b));
	int a_lcm=a/cur_gcd;
	int b_lcm=b/cur_gcd;
	return cur_gcd*a_lcm*b_lcm;
}

int main() {
	// your code goes here
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<"\n";
	cout<<lcm(a,b);
	return 0;
}