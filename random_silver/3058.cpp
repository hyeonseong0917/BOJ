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
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int sum=0;
		int min_num=101;
		for(int i=0;i<7;++i){
			int a=0;
			cin>>a;
			if(a%2==1) continue;
			min_num=min(min_num,a);
			sum+=a;
		}
		cout<<sum<<" "<<min_num<<"\n";
	}
	return 0;
}