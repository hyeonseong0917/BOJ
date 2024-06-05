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
	int t;
	cin>>t;
	while(t--){
		int i;
		string s;
		cin>>i;
		cin>>s;
		string t="";
		t+=s.substr(0,i-1);
		if(i+1)
		t+=s.substr(i,s.size()-(i)+1);
		cout<<t<<"\n";
	}
	

	

	return 0;
}