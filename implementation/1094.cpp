#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int X=0;
	cin>>X;
	int cnt=0;
	while(1){
		if(X==0){
			break;
		}
		if(X%2==1){
			++cnt;
		}
		X/=2;
		
	}
	cout<<cnt;
	return 0;
}