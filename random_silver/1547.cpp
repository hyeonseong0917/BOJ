#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


vector<int> v; //v[i]=k, 
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int M;
	cin>>M;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for(int i=0;i<M;++i){
		int x,y=0;
		cin>>x>>y;
		--x;
		--y;
		int tmp=v[x];
		v[x]=v[y];
		v[y]=tmp;
	}
	cout<<v[0]+1;
	return 0;
}