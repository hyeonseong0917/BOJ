#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long




int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int H,M;
	cin>>H>>M;
	M-=45;
	if(M<0){
		M=60+M;
		--H;
		if(H<0){
			H=23;
		}
	}
	cout<<H<<" "<<M;


	return 0;
}