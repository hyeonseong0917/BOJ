#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int m=n/5;
	if(n%5==0){
		cout<<m;
	}else{
		int ans=-1;
		for(int i=m;i>=0;--i){
			if((n-5*i)%2==0){
				ans=i+(n-5*i)/2;
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}