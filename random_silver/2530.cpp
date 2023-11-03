#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int A,B,C;
	cin>>A>>B>>C;
	int a,b,c;
	int cur_time=0;
	cin>>cur_time;
	C+=cur_time;
	c=C%60;
	b=(C/60 + B);
	int carry=0;
	if(b>=60){
		carry=b/60;
		b%=60;
	}
	A+=carry;
	A%=24;
	cout<<A<<" "<<b<<" "<<c;
	return 0;
}