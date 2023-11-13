#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string S,P;
	cin>>S;
	cin>>P;
	int idx=0;
	int cnt=0;
	while(idx<P.size()){
		// P에서 S와 가장 많이 겹치는 부분을 찾는다
		// S의 부분 문자열을 탐색하면서 P의 현재 idx부터 가장 많이 겹친 문자열의 길이를 찾는다
		int most_overlap_num=0;
		for(int i=0;i<S.size();++i){
			// S[i]부터
			string tmp="";
			int tmp_cnt=0;
			for(int j=i;j<S.size();++j){
				tmp+=S[i];
				if(S[j]==P[idx+j-i]){
					++tmp_cnt;
				}else{
					break;
				}
			}
			most_overlap_num=max(most_overlap_num, tmp_cnt);
		}
		idx+=most_overlap_num;
		++cnt;
	}
	cout<<cnt;
	return 0;
}