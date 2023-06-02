#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//1326
string s;
void Input(){
	cin>>s;
}
bool visited[100+1];
vector<pair<string,int>> v;
void dfs(string cur_string, int cnt, int idx){
	if(cnt==1){
		string a="";
		for(int i=0;i<s.size();++i){
			if(visited[i]){
				a+=s[i];
			}
		}
		v.push_back({a,idx});
		return;
	}
	for(int i=0;i<s.size();++i){
		if(!visited[i]){
			visited[i]=1;
			dfs(cur_string+s[i],cnt+1,i);
			visited[i]=0;
		}
	}
}
void solve(){
	string res="";
	char init;
	int minNum=50;
	int idx=-1;
	for(int i=0;i<s.size();++i){
		if(minNum>s[i]-'A'){
			minNum=s[i]-'A';
			init=s[i];
			idx=i;
		}
	}
	res+=init;
	visited[idx]=1;
	cout<<res<<"\n";
	for(int i=0;i<s.size()-1;++i){
		v.clear();
		dfs(res,0,idx);
		sort(v.begin(),v.end());
		// for(int j=0;j<v.size();++j){
		// 	cout<<v[j].first<<" ";
		// }cout<<endl;
		res=v[0].first;
		visited[v[0].second]=1;
		cout<<v[0].first<<"\n";
	}
	// cout<<visited[1];
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}