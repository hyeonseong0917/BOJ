#include <iostream>
using namespace std;

int N=0;

int main() {
	// your code goes here
	cin>>N;
	int k=0;
	while(1){
		if(N-(4*k)<=0){
			--k;
			break;
		}
		++k;
	}
	
	int cur_num=N-(4*k);
	if(cur_num==1){
		cout<<"SK";
	}else if(cur_num==2){
		cout<<"CY";
	}else if(cur_num==3){
		cout<<"SK";
	}else if(cur_num==4){
		cout<<"CY";
	}
	return 0;
}