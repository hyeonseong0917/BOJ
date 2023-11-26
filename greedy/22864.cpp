#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A,B,C,M;
int main() {
	// your code goes here
	cin>>A>>B>>C>>M;
	int cur_time=0;
	int work=0;
	int tired=0;
	while(1){
		if(cur_time==24){
			break;
		}
		if(tired+A<=M){
			tired+=A;
			work+=B;
		}else{
			tired=max(0,tired-C);
		}
		++cur_time;
	}
	cout<<work;
	
	return 0;
}