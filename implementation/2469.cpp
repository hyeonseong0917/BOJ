#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int k=0;
int n=0; //n은 가로
const int MAX=1001+1;
string board[MAX]; //n*(k-1)
string ans;
map<char,int> m;
int row=-1;
void Input(){
	cin>>k;
	cin>>n;
	for(int i=0;i<n+1;++i){
		cin>>board[i];
	}
	ans=board[0];
	for(int i=1;i<=n;++i){
		if(board[i][0]=='?'){
			row=i;
			break;
		}
	}
	for(int i=0;i<ans.size();++i){
		m[ans[i]]=i;
	}
}
bool comp(pair<char,int> a, pair<char,int> b){
	return a.second<b.second;
}
bool flag=0;
vector<pair<char,int>> v;
vector<int> p;
map<int,int> check;
void cur_ladder(int col){
	int start=col;
	int idx1=-1;
	for(int i=1;i<row;++i){
		if(start-1>=0){
			if(board[i][start-1]=='-'){
				--start;
				continue;
			}
		}
		if(start+1<k){
			if(board[i][start]=='-'){
				++start;
				continue;
			}
		}
	}
	idx1=start;
	start=m['A'+col];
	// cout<<m['C']<<endl;
	// cout<<start<<endl;
	for(int i=n;i>row;--i){
		if(start-1>=0){
			if(board[i][start-1]=='-'){
				--start;
				continue;
			}
		}
		if(start+1<k){
			if(board[i][start]=='-'){
				++start;
				continue;
			}
		}
	}
	int idx2=start;
	// cout<<idx1<<" "<<idx2<<endl;
	
	if(abs(idx1-idx2)>2){
		flag=1;
	}else if(idx1!=idx2){
		++check[min(idx1,idx2)];
		p.push_back(min(idx1,idx2));
	}
	
	// cout<<start;
}
string res="";
void solve(){
	for(int i=0;i<k;++i){
		cur_ladder(i);
	}
	for(int i=0;i<k-1;++i){
		res+="*";
	}
	if(flag==0){
		// cout<<p.size()<<endl;
		for(int i=0;i<p.size();++i){
			res[p[i]]='-';	
		}
		cout<<res;
	}else{
		for(int i=0;i<k-1;++i){
			cout<<"x";
		}
	}
	
	// cout<<res;
	
}
int main() {
	// your code goes here
	Input();
	solve();
	
	return 0;
}