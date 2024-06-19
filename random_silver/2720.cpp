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
	int t;
	cin>>t;
	while(t--){
		int a;
		cin>>a;
		int b=a/25;
		a%=25;
		int c=a/10;
		a%=10;
		int d=a/5;
		a%=5;
		int e=a/1;
		a%=1;
		cout<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
	}
	return 0;
}