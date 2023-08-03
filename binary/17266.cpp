#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;



int main() {
	// your code goes here
	int N=0;
	int M=0;
	cin>>N;
	cin>>M;
	vector<int> v;
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	int L=1;
	int R=100000;
	int maxNum=122232421;
	if(v.size()==1){
		cout<<max(max(abs(0-v[0]),abs(v[0]-0)),max(abs(v[0]-N),abs(N-v[0])));
		return 0;
	}
	vector<int> is_valid;
	while(L<=R){
		is_valid.clear();
		
		int mid=(L+R)/2;
		bool flag=0;
		for(int i=0;i<v.size();++i){
			is_valid.push_back(v[i]-mid);
			is_valid.push_back(v[i]+mid);
		}
		for(int i=0;i<is_valid.size();++i){
			if(i==0){
				if(is_valid[i]>0){
					flag=1;
					break;
				}
			}else if(i==is_valid.size()-1){
				if(is_valid[i]<N){
					flag=1;
					break;
				}
			}else{
				if(i%2==0){
					if(is_valid[i]>is_valid[i-1]){
						flag=1;
						break;
					}
				}
			}
		}
		
		if(flag==0){
			maxNum=min(maxNum,mid);
			R=mid-1;
		}else{
			L=mid+1;
		}
		
	}
	cout<<maxNum;
	return 0;
}