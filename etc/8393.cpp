#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n=0;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		sum+=i;
	}
	cout<<sum;
	return 0;
}