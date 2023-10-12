#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
int arr[1500+1][1500+1];
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	priority_queue<int> pq;
	int N=0;
	cin>>N;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
		}
	}
	for(int i=N-1;i>=0;--i){
		for(int j=0;j<N;++j){
			if(pq.size()<N){
				pq.push(arr[i][j]*-1);
			}else{
				if(pq.top()*-1<arr[i][j]){
					pq.pop();
					pq.push(arr[i][j]*-1);
				}
			}
		}
	}
	cout<<pq.top()*-1;


	return 0;
}