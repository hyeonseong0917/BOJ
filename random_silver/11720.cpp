#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	// 1 9 
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int a=0;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		char b;
		cin>>b;
		a+=(int)(b-'0');
	}
	cout<<a;
	

	return 0;
}