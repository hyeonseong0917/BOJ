#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

int main() {
	// your code goes here
	int N=0;
	cin>>N;
	deque<int> dq;
	for(int i=1;i<=N;++i){
		dq.push_back(i);
	}
	while(1){
		if(dq.size()==1){
			break;
		}
		dq.pop_front();
		int front_num=dq.front();
		dq.pop_front();
		dq.push_back(front_num);
		
	}
	cout<<dq.front();
	return 0;
}