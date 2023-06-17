#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//1321
int N,K=0;
const int MAX=150+1;
vector<int> v[MAX];
bool visited[MAX]={0,};
void Input(){
	cin>>N>>K;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v[i].push_back(a);
	}
}
void solve(){
	int next_person=v[0][0];
	visited[0]=1;
	int M=1;
	while(1){
		if(next_person==K){
			cout<<M;
			break;
		}
		if(v[next_person].size()){
			int tmp_next_person=v[next_person][0];	
			if(!visited[tmp_next_person]){
				visited[tmp_next_person]=1;
				next_person=tmp_next_person;
				++M;
			}else{
				cout<<-1;
				break;
			}
		}else{
			cout<<-1;
		}
	}
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}