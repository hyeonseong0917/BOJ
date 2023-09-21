#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a,b,v;
	cin>>a>>b>>v;
	int cnt=0;
	// v-a보다 크거나 같은 최소의 지점에서 a만큼 jump
	// v-a ~ v-1
	if((v-a)%(a-b)==0){
		cnt+=(v-a)/(a-b);
		cnt+=1;
	}else{
		int mod=(v-a)/(a-b);
		cnt+=(mod+1);
		cnt+=1;
	}
	cout<<cnt;
	
	return 0;
}