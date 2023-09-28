#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	string a,b;
	
	cin>>a;
	cin>>b;
	
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a<b){
		cout<<b;
	}else{
		cout<<a;
	}
	return 0;
}