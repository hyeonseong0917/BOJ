#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long N;
	cin>>N;
	int cnt=1;
	long long ans=1;
	long long to_add=0;
	while(1){
		if(ans>=N){
			cout<<cnt;
			break;
		}
		++cnt;
		to_add+=6;
		ans+=to_add;
	}
	return 0;
}