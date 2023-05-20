#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
const int MAX=100000+1;
int num[MAX];
int parent[MAX];

void Input(){
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		int a=0;
		cin>>a;
		num[i]=a;
		parent[i]=i;
	}
}
int Find(int a){
	if(parent[a]==a){
		return a;
	}
	int b=Find(parent[a]);
	return b;
}
void Union(int a, int b){
	int A=Find(a);
	int B=Find(b);
	parent[A]=B;
	num[B]+=num[A];
}
void solve(){
	for(int i=0;i<M;++i){
		int a,b=0;
		cin>>a>>b;
		
		if(Find(a)!=Find(b)){
			// cout<<a<<" "<<b<<endl;
			Union(a,b);
			// cout<<num[a]<<" "<<num[b];
			// break
		}
		cout<<num[Find(b)]<<"\n";
	}
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	Input();
	solve();
	return 0;
}