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
	string N;
	cin>>N;
	int check[10];
	memset(check,0,sizeof(check));
	for(int i=0;i<N.size();++i){
		++check[N[i]-'0'];
	}
	int ans=0;
	ans=(check[6]+check[9]+1)/2;
	
	for(int i=0;i<10;++i){
		if(i==6 || i==9) continue;
		ans=max(ans,check[i]);
	}
	cout<<ans;
	return 0;
}