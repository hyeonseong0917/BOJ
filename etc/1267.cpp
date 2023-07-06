#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N=0;
	cin>>N;
	int first_sum=0, second_sum=0;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		first_sum+=((a/30)+1)*10;
		second_sum+=((a/60)+1)*15;
	}
	// cout<<first_sum<<" "<<second_sum;
	if(first_sum<second_sum){
		cout<<"Y"<<" "<<first_sum;
	}else if(first_sum>second_sum){
		cout<<"M"<<" "<<second_sum;
	}else{
		cout<<"Y"<<" "<<"M"<<" "<<first_sum;
	}
	return 0;
}