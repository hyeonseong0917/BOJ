#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	int idx=1;
	while(t--){
		int first_sum=0;
		int p[6]={1,2,3,3,4,10};
		for(int i=0;i<6;++i){
			int a=0;
			cin>>a;
			first_sum+=a*p[i];
		}
		int second_sum=0;
		int q[7]={1,2,2,2,3,5,10};
		for(int i=0;i<7;++i){
			int a=0;
			cin>>a;
			second_sum+=a*q[i];
		}
		if(first_sum<second_sum){
			cout<<"Battle "<< idx<< ": Evil eradicates all trace of Good"<<"\n";
		}else if(first_sum>second_sum){
			cout<<"Battle "<< idx<< ": Good triumphs over Evil"<<"\n";
		}else{
			cout<<"Battle "<< idx<< ": No victor on this battle field"<<"\n";
		}
		++idx;
	}
	return 0;
}