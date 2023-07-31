#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long d[100+1];
	int t=0;
	cin>>t;
	d[1]=1;
	d[2]=1;
	d[3]=1;
	d[4]=2;
	d[5]=2;
	for(int i=6;i<=100;++i){
		d[i]=d[i-1]+d[i-5];
	}
	while(t--){
		long long a=0;
		cin>>a;
		cout<<d[a]<<"\n";
	}
	return 0;
}