#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N,M=0;
vector<int> student;
void Input(){
	cin>>N;
	cin>>M;
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		student.push_back(a);
	}
}
bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	if(a.first.first==b.first.first){
		return a.first.second<b.first.second;
	}
	return a.first.first<b.first.first;
}
void solve(){
	map<int,int> m;
	vector<pair<pair<int,int>,int>> photo; // {{추천 수, 개시 순서},학생 번호}
	int cnt=0;
	for(int i=0;i<M;++i){
		int cur_student=student[i];
		if(m[cur_student]==1){
			for(int j=0;j<photo.size();++j){
				if(photo[j].second==cur_student){
					++photo[j].first.first;
					break;
				}
			}
		}else{
			m[cur_student]=1;
			if(photo.size()<N){
				photo.push_back({{1,cnt++},cur_student});
			}else{
				sort(photo.begin(),photo.end(),comp);
				photo[0].first.first=1;
				photo[0].first.second=cnt++;
				m[photo[0].second]=0;
				photo[0].second=cur_student;
			}
		}
	}
	vector<int> last_student;
	for(int i=0;i<photo.size();++i){
		// cout<<photo[i].first.first<<" "<<photo[i].first.second<<" "<<photo[i].second<<endl;
		last_student.push_back(photo[i].second);
	}
	sort(last_student.begin(),last_student.end());
	for(int i=0;i<last_student.size();++i){
		cout<<last_student[i]<<" ";
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}