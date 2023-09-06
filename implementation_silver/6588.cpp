#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N,M;
vector<int> prime;
map<int,int> m;
int isPrime[1000000+1]={0,};
void setPrimeNum(){
	int m=sqrt(1000000);
	for(int i=2;i<=m;++i){
		if(!isPrime[i]){
			for(int j=i*i;j<1000000;j+=i){
				isPrime[j]=1;
			}
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	setPrimeNum();

	// for(int i=3;i<=500000;i+=2){
	// 	if(isPrimeNum(i)){
	// 		m[i]=1;
	// 		prime.push_back(i);
	// 	}
	// }
	
	while(1){
		int a=0;
		cin>>a;
		if(a==0){
			break;
		}
		bool flag=0;
		for(int i=3;i<=500000;i+=2){
			if(!isPrime[i] && !isPrime[a-i]){
				flag=1;
				cout<<a<<" = "<<i<<" + "<<a-i<<"\n";	
				break;
			}
		}
		if(!flag){
			cout<<"Goldbach's conjecture is wrong."<<"\n";
		}
		
	}
	return 0;
}