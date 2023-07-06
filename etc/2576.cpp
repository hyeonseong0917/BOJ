#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int sum=0;
	int minNum=122232421;
	for(int i=0;i<7;++i){
		int a=0;
		cin>>a;
		if(a%2==1){
			sum+=a;
			minNum=min(minNum,a);
		}
	}
	if(minNum==122232421){
		cout<<-1;
	}else{
		cout<<sum<<endl;
		cout<<minNum;
	}
	
	return 0;
}