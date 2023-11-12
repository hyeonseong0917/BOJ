#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int s=0;
	cin>>s;
	if(90<=s && s<=100){
		cout<<"A";
	}else if(80<=s && s<=89){
		cout<<"B";
	}else if(70<=s && s<=79){
		cout<<"C";
	}else if(60<=s && s<=69){
		cout<<"D";
	}else{
		cout<<"F";
	}
	return 0;
}