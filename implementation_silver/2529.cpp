#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int k=0;
const int MAX=10+1;
bool visited[MAX];
string str="";
long long minNum=12222324211;
long long maxNum=-12222324211;
vector<int> v;

void Input(){
	cin>>k;
	for(int i=0;i<k;++i){
		char c;
		cin>>c;
		str+=c;
	}
}
int cnt=0;
void pick(int num){
	if(v.size()==k+1){
		bool flag=1;
		for(int i=0;i<str.size();++i){
			char c=str[i];
			if(c=='<'){
				if(v[i]>v[i+1]){
					flag=0;
					break;
				}
			}else{
				if(v[i]<v[i+1]){
					flag=0;
					break;
				}
			}
		}
		if(flag==1){
			// for(int i=0;i<v.size();++i){
			// 	cout<<v[i]<<" ";
			// }cout<<endl;
			long long sum=0;
			for(int i=0;i<v.size();++i){
				sum+=pow(10,v.size()-1-i)*v[i];
			}
			// cout<<sum<<endl;
			minNum=min(minNum,sum);
			maxNum=max(maxNum,sum);
		}
		return;
	}
	if(num>=10){
		return;
	}
	for(int i=0;i<10;++i){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i);
			pick(i);
			v.pop_back();
			visited[i]=0;
		}
	}

}

void solve(){
	
	pick(0);
	string minNumStr=to_string(minNum);
	string maxNumStr=to_string(maxNum);
	string minNumAns="";
	string maxNumAns="";
	if(minNumStr.size()!=k+1){
		minNumAns+='0';
		minNumAns+=minNumStr;
	}else{
		minNumAns=minNumStr;
	}
	if(maxNumStr.size()!=k+1){
		maxNumAns+='0';
		maxNumAns+=maxNumStr;
	}else{
		maxNumAns=maxNumStr;
	}
	cout<<maxNumAns<<"\n";
	cout<<minNumAns;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();		
	
	return 0;
}