#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		if(n==1 || n==3){
			cout<<"CY";
			continue;
		}
		if(n==2){
			cout<<"SK";
			continue;
		}
		// 짝수 개를 받는 사람이 이긴다 항상?
		// n>=4
		// n==4 -> sk가 이김
		// n==5 -> cy가 이김
		// n==6 -> sk가 이김
		// n==7 -> cy
		if(n%2==1){
			cout<<"CY";
		}else{
			cout<<"SK";
		}
	}
	
	
	
	
	return 0;
}