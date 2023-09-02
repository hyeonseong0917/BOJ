	#include <iostream>
	#include <algorithm>
	#include <vector>
	#include <deque>
	using namespace std;
	
	
	
	int main() {
		// your code goes here
		ios_base :: sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		int t=0;
		cin>>t;
		while(t--){
			string p="";
			cin>>p;
			int idx=0;
			
			int N=0;
			cin>>N;
			string n="";
			cin>>n;
			
			deque<int> d;
			string tmp="";
			for(int i=1;i<n.size()-1;++i){
				if(n[i]!=','){
					tmp+=n[i];
				}else{
					d.push_back(stoi(tmp));
					tmp="";
				}
			}
			// cout<<tmp<<"\n";
			if(tmp!=""){
				d.push_back(stoi(tmp));	
			}
			// cout<<stoi(tmp);
			bool reverse=0;
			bool flag=0;
			deque<int> tmp_d;
			for(int i=0;i<p.size();++i){
				if(p[i]=='R'){
					if(!reverse){
						reverse=1;
					}else{
						reverse=0;
					}
					// while(!tmp_d.empty()){
					// 	d.push_back(tmp_d.back());
					// 	tmp_d.pop_back();
					// }
					
				}else{
					if(!d.size()){
						flag=1;
						break;
					}else{
						if(!reverse){
							d.pop_front();	
						}else{
							d.pop_back();
						}
						
					}
				}
			}
			if(flag==1){
				cout<<"error"<<"\n";
			}else{
				cout<<"[";
				if(!reverse){
					int ds=d.size();
					for(int i=0;i<ds;++i){
						if(i!=ds-1){
							cout<<d.front()<<",";	
							d.pop_front();
						}else{
							cout<<d.front();
							d.pop_front();
						}
					
					}
					cout<<"]"<<"\n";
				}else{
					int ds=d.size();
					for(int i=0;i<ds;++i){
						if(i!=ds-1){
							cout<<d.back()<<",";	
							d.pop_back();
						}else{
							cout<<d.back();
							d.pop_back();
						}
					
					}
					cout<<"]"<<"\n";
				}
				
			}
			
		}
		return 0;
	}