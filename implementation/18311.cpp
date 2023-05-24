#include <iostream>
using namespace std;

//1321
long long N,K;
const int MAX=100000+1;
int arr[MAX];
long long distSum=0;
void Input(){
	cin>>N>>K;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		arr[i]=a;
		distSum+=a;
	}
}
void solve(){
	long long dist=0;
	if(K==0){
		cout<<1;
		return;
	}

	for(int i=0;i<N;++i){
		dist+=arr[i];
		if(dist>=K){
			if(dist==K){
				if(i+2==N+1){
					cout<<N;
				}else{
					cout<<i+2;	
				}
				
			}else{
				cout<<i+1;	
			}
			
			break;
		}
		
	}
	// cout<<dist<<endl;
	if(dist<K){
		for(int i=N-1;i>=0;--i){
			// cout<<i<<" "<<dist<<endl;
			dist+=arr[i];
			if(dist>=K){
				if(dist==K){
					cout<<i;
				}else{
					cout<<i+1;	
				}
				
				break;
			}
			
		}
	}
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}