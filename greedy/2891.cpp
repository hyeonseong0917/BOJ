#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,S,R;
bool visited[10+1];
void Input(){
	cin>>N>>S>>R;
	for(int i=1;i<=N;++i){
		visited[i]=1;
	}
	vector<int> a;
	vector<int> broken;
	for(int i=0;i<S;++i){
		int c=0;
		cin>>c;
		// a.push_back(c);
		broken.push_back(c);
		
	}
	for(int i=0;i<R;++i){
		int c=0;
		cin>>c;
		visited[c]=1;
		a.push_back(c);
	}
	for(int i=0;i<S;++i){
		visited[broken[i]]=0;
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();++i){
		int curNum=a[i];
		bool flag=visited[curNum];
		visited[curNum]=1;
		if(flag==1){
			if(!visited[curNum-1] && curNum-1>=1){
				visited[curNum-1]=1;
				continue;
			}
			if(!visited[curNum+1] && curNum+1<=N){
				visited[curNum+1]=1;
				continue;
			}	
		}
		
		
	}
	int cnt=0;
	for(int i=1;i<=N;++i){
		if(!visited[i]){
			++cnt;
		}
	}
	cout<<cnt;
	
}

int main() {
	// your code goes here
	Input();
	return 0;
}