#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int N;
		cin>>N;
		vector<int> stud[N+1];
		int E;
		cin>>E;
		int cnt=0;
		for(int i=0;i<E;++i){
			vector<int> cur_stud;
			int K=0;
			cin>>K;
			bool is_sun=0;
			for(int j=0;j<K;++j){
				int a=0;
				cin>>a;
				cur_stud.push_back(a);
				if(a==1){
					is_sun=1;
				}
			}
			if(is_sun){
				//신곡발매
				++cnt;
				for(int j=0;j<K;++j){
					stud[cur_stud[j]].push_back(cnt);
				}
			}else{
				map<int,int> m;
				for(int j=0;j<K;++j){
					int cur_stud_num=cur_stud[j];
					for(int k=0;k<stud[cur_stud_num].size();++k){
						++m[stud[cur_stud_num][k]];
					}
				}
				vector<int> v;
				for(int j=1;j<=cnt;++j){
					if(m[j]){
						v.push_back(j);
					}
				}
				for(int j=0;j<K;++j){
					stud[cur_stud[j]]=v;
				}
			}
		}
		vector<int> ans;
		for(int i=1;i<=N;++i){
			// i번째 학생에 대해 모든 곡을 갖고 있는지?
			if(stud[i].size()==cnt){
				ans.push_back(i);
			}
		}
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}
		
	}
	return 0;
}