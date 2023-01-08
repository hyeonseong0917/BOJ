#include <iostream>
using namespace std;


int N=0;
void Input(){
	cin>>N;
}
void solve(){
	long long ans=1;
	if(N<3){
		cout<<N;
		return;
	}
	int a,b=0;
	if(N%3==0){
		a=N/3;
		for(int i=0;i<a;++i){
			ans*=3;
			ans%=10007;
		}
		cout<<ans;

	}else{
		if(N%3==1){
			a=(N/3)-1;
		
		}else if(N%3==2){
			a=(N/3);
		}
		b=N-a*3;
		for(int i=0;i<a;++i){
			ans*=3;
			ans%=10007;
		}
		ans*=b;
		ans%=10007;
		cout<<ans;	
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}