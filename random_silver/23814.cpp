#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

ll D,N,M,K;
ll DD,NN,MM,KK;
ll ans=0;
ll cur_num=0;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>D;
	cin>>N>>M>>K;
	ll cur_num=(N+M+K)/D;
	DD=D;
	NN=N;
	MM=M;
	KK=K;
	ll ans=0;
	if(cur_num==N/D+M/D+K/D){
		ans=K;
	}
	// N만
	if(K>=D-N%D){
		K-=D-N%D;
		N+=D-N%D;
		if(cur_num==N/D+M/D+K/D){
			ans=max(ans,K);
		}
		
	}
	D=DD;
	N=NN;
	M=MM;
	K=KK;
	// M만
	if(K>=D-M%D){
		K-=D-M%D;
		M+=D-M%D;
		if(cur_num==N/D+M/D+K/D){
			ans=max(ans,K);
		}
	}
	D=DD;
	N=NN;
	M=MM;
	K=KK;
	// N M 둘다
	if(K>=(D-M%D)+(D-N%D)){
		K-=(D-M%D)+(D-N%D);
		N+=D-N%D;
		M+=D-M%D;
		if(cur_num==N/D+M/D+K/D){
			ans=max(ans,K);
		}
	}
	cout<<ans;
	
	
	
	return 0;
}