#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;


const int MAX=5000+1;
#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	unordered_set<string> m;
	int cnt=N;
	vector<string> text;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		m.insert(s);
	}
	for(int i=0;i<M;++i){
		string s;
		cin>>s;
		string cur_string="";
		for(int j=0;j<s.size();++j){
			if(s[j]==','){
				if(m.find(cur_string)!=m.end()){
					m.erase(cur_string);
					--cnt;	
				}
				
				cur_string="";
			}else{
				cur_string+=s[j];
			}
		}
		if(m.find(cur_string)!=m.end()){
			m.erase(cur_string);
			--cnt;
		}
		cout<<cnt<<"\n";

	}
	
	return 0;
}