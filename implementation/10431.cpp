#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int P=0;
	cin>>P;
	for(int i=1;i<=P;++i){
		int num=0;
		cin>>num;
		int cnt=0;
		vector<int> line;
		for(int j=0;j<20;++j){
			int cur_h=0;
			cin>>cur_h;
			if(line.empty()){
				line.push_back(cur_h);
				continue;
			}
			int idx=-1;
			for(int k=0;k<line.size();++k){
				if(line[k]>cur_h){
					idx=k;
					break;
				}
			}
			if(idx==-1){	
				line.push_back(cur_h);
			}else{
				line.push_back(0);
				for(int k=line.size()-1;k>=idx+1;--k){
					line[k]=line[k-1];
					++cnt;
				}
				line[idx]=cur_h;
			}
		}
		cout<<i<<" "<<cnt<<endl;
	}
	return 0;
}