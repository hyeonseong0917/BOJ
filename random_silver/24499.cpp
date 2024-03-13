#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int N,K;
	cin>>N>>K;
	vector<int> v;
	int psum[100000+1];
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
		psum[i]=0;
	}
	psum[0]=v[0];
	for(int i=1;i<N;++i){
		psum[i]=psum[i-1]+v[i];
	}
	int ans=psum[K-1];
	for(int i=1;i<N;++i){
		if(i+K-1>=N){
			ans=max(ans,psum[N-1]-psum[i-1]+psum[(i+K-1)%N]);
		}else{
			ans=max(ans,psum[i+K-1]-psum[i-1]);
		}
	}
	cout<<ans;
	
	
	return 0;
}