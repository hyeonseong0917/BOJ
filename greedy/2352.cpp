#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool comp(pair<int,int> a, pair<int,int> b){
	
	return a.second<b.second;
}
int main() {
	// your code goes here
	int N=0;
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	// sort(v.begin(),v.end(),comp);
	// vector<int> arr;
	// for(int i=0;i<N;++i){
	// 	arr.push_back(v[i].first);
	// }
	vector<int> lis;
	lis.push_back(v[0]);
	for(int i=1;i<N;++i){
		if(lis[lis.size()-1]<v[i]){
			lis.push_back(v[i]);
		}else{
			int left=0;
			int right=lis.size()-1;
			int curNum=v[i];
			while(left<right){
				int mid=(left+right)/2;
				if(lis[mid]<curNum){
					left=mid+1;
				}else{
					right=mid;
				}
			}
			lis[right]=curNum;
		}
	}
	cout<<lis.size();
	return 0;
}