#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int r1,c1,r2,c2;
void Input(){
	cin>>r1>>c1>>r2>>c2;
}
vector<pair<pair<int,int>,int>> v;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	if(a.first.first==b.first.first){
		return a.first.second<b.first.second;
	}
	return a.first.first<b.first.first;
}
bool isRange(int y, int x){
	return (y>=r1 && x>=c1 && y<=r2 && x<=c2);
}
void solve(){
	int num=1;
	int dir=0;
	int cnt=0;
	int step=1;
	int y=0, x=0;
	if(isRange(y,x)){
		v.push_back({{y,x},num});
	}
	while(1){
		if(v.size()==(r2-r1+1)*(c2-c1+1)){
			break;
		}
		int cur_step=step;
		while(cur_step--){
			y+=dy[dir];
			x+=dx[dir];
			num+=1;
			if(isRange(y,x)){
				v.push_back({{y,x},num});
			}
		}
		dir=(dir+1)%4;
		++cnt;
		if(cnt%2==0){
			++step;
		}
	}
	sort(v.begin(),v.end(),comp);
	int maxNum=-1;
	int slice_num=(c2-c1+1);
	for(int i=0;i<v.size();++i){
		// cout<<v[i].second<<" ";
		maxNum=max(maxNum,v[i].second);
	}
	string max_num_string=to_string(maxNum);
	// cout<<max_num_string;
	int max_len=max_num_string.size();
	// cout<<max_len;
	for(int i=0;i<v.size();++i){
		if(i%slice_num==0 && i!=0){
			cout<<"\n";
		}
		string cur_string=to_string(v[i].second);
		int diff=max_len-cur_string.size();
		string new_string="";
		for(int i=0;i<diff;++i){
			new_string+=" ";
		}
		new_string+=cur_string;
		cout<<new_string<<" ";
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}