#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int sum=0;
	int idx=0;
	for(int i=1;i<=5;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(sum<a+b+c+d){
			sum=a+b+c+d;
			idx=i;
		}
	}
	cout<<idx<<" "<<sum;
	return 0;
}