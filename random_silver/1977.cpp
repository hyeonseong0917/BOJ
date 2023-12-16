#include <iostream>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int M,N;
	cin>>M>>N;
	long long sum=0;
	ll min_num=1222232421;
	for(ll i=M;i<=N;++i){
		for(ll j=1;j*j<=i;++j){
			if(j*j==i){
				sum+=i;
				min_num=min(min_num,i);
			}
		}
	}
	if(sum==0){
		cout<<-1;
	}else{
		cout<<sum<<"\n";
		cout<<min_num;
	}
	return 0;
}