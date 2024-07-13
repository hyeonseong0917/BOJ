#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a=122232421;
	int b=122232421;
	for(int i=0;i<3;++i){
		int c;
		cin>>c;
		a=min(a,c);
	}
	for(int i=0;i<2;++i){
		int c;
		cin>>c;
		b=min(b,c);
	}
	cout<<a+b-50;
	return 0;
}