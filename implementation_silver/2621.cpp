#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<pair<char,int>> v;

void Input(){
	for(int i=0;i<5;++i){
		char c;
		int a;
		cin>>c;
		cin>>a;
		v.push_back({c,a});
	}
}
bool comp(pair<char,int> a, pair<char,int> b){
	return a.second<b.second;
}
int first_rule(){
	sort(v.begin(),v.end(),comp);
	//모두 같은 색인지
	bool is_same_color=1;
	for(int i=0;i<v.size()-1;++i){
		if(v[i].first!=v[i+1].first){
			is_same_color=0;
			break;
		}
	}
	bool is_seq=1;
	for(int i=0;i<v.size()-1;++i){
		if((v[i].second+1)!=v[i+1].second){
			is_seq=0;
			break;
		}
	}
	if(is_same_color && is_seq){
		return v[4].second+900;
	}else{
		return -1;
	}
	
}
int second_rule(){
	//4장의 색이 같은지
	sort(v.begin(),v.end(),comp);
	bool is_same_four=1;
	for(int i=0;i<v.size()-2;++i){
		if(v[i].second!=v[i+1].second){
			is_same_four=0;
			break;
		}
	}
	if(!is_same_four){
		is_same_four=1;
		for(int i=1;i<v.size()-1;++i){
			if(v[i].second!=v[i+1].second){
				is_same_four=0;
				break;
			}
		}
		if(is_same_four){
			return v[1].second+800;
		}else{
			return -1;
		}
	}else{
		return v[0].second+800;	
	}
}
int third_rule(){
	//3장의 숫자가 같고 2장의 숫자도 같은지
	//(1) 22233
	sort(v.begin(),v.end(),comp);
	if((v[0].second==v[1].second && v[1].second==v[2].second) && v[3].second==v[4].second){
		return (v[0].second*10) + (v[3].second) + 700;
	}else if(v[0].second==v[1].second && (v[2].second==v[3].second && v[3].second==v[4].second)){
		return (v[0].second) + v[2].second*10 + 700;
	}else{
		return -1;
	}
}
int fourth_rule(){
	sort(v.begin(),v.end(),comp);
	bool is_same_color=1;
	for(int i=0;i<v.size()-1;++i){
		if(v[i].first!=v[i+1].first){
			is_same_color=0;
			break;
		}
	}
	if(is_same_color){
		return v[4].second+600;
	}else{
		return -1;
	}
}
int fifth_rule(){
	sort(v.begin(),v.end(),comp);
	bool is_seq=1;
	for(int i=0;i<v.size()-1;++i){
		if((v[i].second+1)!=v[i+1].second){
			is_seq=0;
			break;
		}
	}
	if(is_seq){
		return v[4].second+500;
	}else{
		return -1;
	}
}
int sixth_rule(){
	sort(v.begin(),v.end(),comp);
	bool is_seq=0;
	int num=0;
	for(int i=0;i<v.size()-2;++i){
		if(v[i].second==v[i+1].second && v[i+1].second==v[i+2].second){
			is_seq=1;
			num=v[i].second;
			break;
		}
	}
	if(is_seq){
		return num+400;
	}else{
		return -1;
	}
	
}
int seventh_rule(){
	sort(v.begin(),v.end(),comp);
	vector<pair<int,int>> seq;
	for(int i=0;i<v.size();++i){
		for(int j=i+1;j<v.size();++j){
			if(v[i].second==v[j].second){
				seq.push_back({i,j});
				break;
			}
		}
	}
	sort(seq.begin(),seq.end(),comp);
	if(seq.size()==2){
		return v[seq[0].first].second + (v[seq[1].first].second*10) + 300;
	}else{
		return -1;
	}
}
int eighth_rule(){
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<v.size();++i){
		for(int j=i+1;j<v.size();++j){
			if(v[i].second==v[j].second){
				return v[i].second+200;
			}
		}
	}
	return -1;
}
int ninth_rule(){
	sort(v.begin(),v.end(),comp);
	return v[4].second+100;
}
void solve(){
	int sum=0;
	// cout<<seventh_rule()<<endl;
	sum=max(sum,first_rule());
	sum=max(sum,second_rule());
	sum=max(sum,third_rule());
	sum=max(sum,fourth_rule());
	sum=max(sum,fifth_rule());
	sum=max(sum,sixth_rule());
	sum=max(sum,seventh_rule());
	sum=max(sum,eighth_rule());
	sum=max(sum,ninth_rule());
	cout<<sum;	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}