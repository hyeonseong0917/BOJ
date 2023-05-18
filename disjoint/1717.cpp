#include <iostream>
using namespace std;
// Union Find
const int MAX = 1000000;

int N, M;
int parent[MAX];
int n,m,l;

int Find(int num){
	if(parent[num]==num){
		return num;
	}
	int next=Find(parent[num]);
	parent[num]=next;
	return next;
}
void Union(int a, int b){
	parent[Find(a)]=Find(b);
}
int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i){
		parent[i] = i;
	} 
	for (int i = 0; i < M; ++i){
		cin >> n >> m >> l;
		if(n==0){
			Union(m,l);
		}else{
			if(Find(m)==Find(l)){
				cout<<"YES"<<'\n';
			}else{
				cout<<"NO"<<'\n';
			}
		}
	}

    return 0;
}