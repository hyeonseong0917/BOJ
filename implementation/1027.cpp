#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAX=50+1;
int arr[MAX];
int N=0;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
}
int find_building(int idx){
	//이전 인덱스 탐색
	int cnt=1;
	double minIdx=1222324211*1.0;
	int num=0;
	//idx번째 값보다 작거나 같은 값들만을 대상으로
	for(int i=idx-1;i>=0;--i){
		double grad=(double)(arr[idx]-arr[i])/cnt;
		// cout<<grad<<endl;
		if(grad<minIdx){
			minIdx=grad;
			++num;
		}
		++cnt;	
	}
	
	cnt=1;
	minIdx=1222324211*1.0;
	for(int i=idx+1;i<N;++i){
		double grad=(double)(arr[idx]-arr[i])/cnt;
		// cout<<grad<<" "<<minIdx<<endl;
		if(grad<minIdx){
			minIdx=grad;
			++num;
		}
		++cnt;
	}
	// cout<<num;
	return num;	
}

int main() {
	// your code goes here
	Input();
	// cout<<find_building(0);
	int ans=0;
	for(int i=0;i<N;++i){
		ans=max(ans,find_building(i));
	}
	cout<<ans;
	
	return 0;
}