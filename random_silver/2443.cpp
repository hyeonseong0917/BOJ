#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<=(2*N-1)-(i+1);++j){
			if(j<i){
				cout<<" ";
			}else{
				cout<<"*";
			}
		}cout<<endl;
	}
	return 0;
}