#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long

int N,K;
const int MAX=8+1;
vector<int> v;
bool visited[MAX];
vector<int> kit;
void Input(){
	cin>>N>>K;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		kit.push_back(a);
	}
}
int cnt=0;
void pick(){
	if(v.size()==N){
		bool flag=1;
		int w=500;
		for(int i=0;i<v.size();++i){
			w+=kit[v[i]];
			w-=K;
			if(w<500){
				flag=0;
				break;
			}
		}
		if(flag){
			++cnt;
		}
		return;
	}
	for(int i=0;i<N;++i){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i);
			pick();
			v.pop_back();
			visited[i]=0;
		}
	}

}


int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	Input();
	pick();
	cout<<cnt;
	return 0;
}