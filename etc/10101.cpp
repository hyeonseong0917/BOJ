#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a=0,b=0,c=0;
	cin>>a>>b>>c;
	// cout<<a+b+c<<endl;
	if(a==60 && b==60 && c==60){
		cout<<"Equilateral";
		return 0;
	}
	if((a+b+c)==180){
		bool same_flag=0;
		if(a==b || a==c || b==c){
			same_flag=1;
		}
		if(same_flag==1){
			cout<<"Isosceles";
		}else{
			cout<<"Scalene";
		}
	}else{
		// cout<<a<<" "<<b<<" "<<c<<endl;
		// cout<<a+b+c;
		cout<<"Error";	
	}
	return 0;
}