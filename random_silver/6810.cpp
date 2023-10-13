#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int origin_num=120-29;
	int a,b,c;
	cin>>a>>b>>c;
	origin_num+=a+b*3+c;
	cout<<"The 1-3-sum is "<<origin_num;
	return 0;
}