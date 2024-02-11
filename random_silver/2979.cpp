#include <iostream>
using namespace std;

const int MAX=100+1;
int arr[MAX];
int main() {
	// your code goes here
	for(int i=0;i<MAX;++i){
		arr[i]=0;
	}
	int A,B,C;
	cin>>A>>B>>C;
	int sum=0;
	for(int i=0;i<3;++i){
		int a,b;
		cin>>a>>b;
		for(int j=a;j<b;++j){
			++arr[j];
		}
	}
	for(int i=1;i<MAX;++i){
		if(arr[i]==1){
			sum+=A;
		}else if(arr[i]==2){
			sum+=B*2;
		}else if(arr[i]==3){
			sum+=C*3;
		}
	}
	cout<<sum;
	return 0;
}