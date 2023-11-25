#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N,K;
vector<int> v;
int ans=-1222232421;
const int MAX=100000+1;
int psum[MAX];
void Input(){
	cin>>N>>K;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}

}
void solve(){
	psum[0]=v[0];
	for(int i=1;i<N;++i){
		psum[i]=psum[i-1]+v[i];
	}
	int L=0,R=K-1;
	while(R<N){
		ans=max(ans,psum[R]-psum[L]+v[L]);
		++R;
		++L;
	}
	cout<<ans;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}