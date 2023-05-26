#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//1623
string S="";
int N=0;
const int MAX=10+1;
bool visited[MAX];
vector<int> v;
vector<string> cur_sum;
int maxCnt=-1, minCnt=122232421;
void Input(){
	cin>>S;
	N=S.size();
}
void dfs(string origin_str, int idx, int cnt){
	if(cnt==3){
		vector<string> cur_str;
		int preIdx=0;
		for(int i=0;i<3;++i){
			if(i==2){
				cur_str.push_back(origin_str.substr(v[i]));
			}else{
				int nextIdx=v[i+1];
				cur_str.push_back(origin_str.substr(preIdx,nextIdx-preIdx));
				preIdx=nextIdx;
			}
		}
		int cur_str_sum=0;
		for(int i=0;i<3;++i){
			cur_str_sum+=stoi(cur_str[i]);
		}
		// for(int i=0;i<3;++i){
		// 		cout<<cur_str[i]<<" ";
		// 	}cout<<endl;
		// 	for(int i=0;i<3;++i){
		// 		cout<<v[i]<<" ";
		// 	}cout<<endl;
		cur_sum.push_back(to_string(cur_str_sum));
		return;
	}
	if(idx==origin_str.size()){
		return;
	}
	for(int i=idx;i<origin_str.size();++i){
		if(!visited[i]){
			v.push_back(i);
			visited[i]=1;
			dfs(origin_str,i+1,cnt+1);
			visited[i]=0;
			v.pop_back();
		}
	}
}
void BFS(){
	queue<pair<string,int>> q;
	int cur_cnt=0;
	for(int i=0;i<S.size();++i){
		if((S[i]-'0')%2==1){
			++cur_cnt;
		}
	}
	q.push({S,cur_cnt});
	// cout<<cur_cnt;
	while(!q.empty()){
		string cur_string=q.front().first;
		int res=q.front().second;
		q.pop();
		if(cur_string.size()>=3){
			v.clear();
			cur_sum.clear();
			for(int i=0;i<MAX;++i){
				visited[i]=0;
			}
			dfs(cur_string,0,0);
			// cout<<cur_sum.size()<<endl;
			for(int i=0;i<cur_sum.size();++i){
				int cnt=0;
				for(int j=0;j<cur_sum[i].size();++j){
					if((cur_sum[i][j]-'0')%2==1){
						++cnt;
					}
				}
				// cout<<cur_sum[i]<<" "<<res+cnt<<endl;
				q.push({cur_sum[i],res+cnt});
			}
			
			
		}else if(cur_string.size()==2){
			int c=res;
			// cout<<cur_string<<" "<<c<<endl;
			string c_string=cur_string;
			while(1){
				if(cur_string.size()==1){
					// if((cur_string[0]-'0')%2==1){
					// 	++c;
					// }
					// maxCnt=c;
					// minCnt=c;
					break;
				}
				
				int a=cur_string[0]-'0';
				int b=cur_string[1]-'0';
				
				cur_string=to_string(a+b);
				for(int i=0;i<cur_string.size();++i){
					if((cur_string[i]-'0')%2==1){
						++c;
						// if(c==6){
						// 	cout<<c_string<<endl;
						// }
					}
				}	
				
			}
			
			// cout<<c<<" "<<cur_string<<endl;
			minCnt=min(minCnt,c);
		
			maxCnt=max(maxCnt,c);
			
			// cout<<c<<endl;
		}else{
			maxCnt=max(res,maxCnt);
			minCnt=min(res,minCnt);
			
		
		}	
	}
	cout<<minCnt<<" "<<maxCnt;
	
}
void solve(){
	BFS();
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}