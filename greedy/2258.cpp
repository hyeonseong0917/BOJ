#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define forn(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX=100000+1;
const int MAX_COST=2147483647-1;

int N,M=0;
vector<pair<int,int>> v;
int MAX_WEIGHT[MAX]={0,};
int CAN_COVER[MAX]={0,};

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second<b.second;
}
bool fail=0;
void Input(){
    cin>>N>>M;
    int sum=0;
    forn(i,N){
        int a,b=0;
        cin>>a>>b;
        v.push_back({a,b}); 
        sum+=a;
    }
    sort(v.begin(),v.end(),comp);
    if(sum<M){
        fail=1;
    }
      
}

int solution(){
    if(fail==1){
        return -1;
    }
    int weight_sum=0;
    int min_cost=MAX_COST;
    int cost=MAX_COST;
    int pre_cost=-1;
    forn(i,N){
        int cur_cost=v[i].second;
        if(weight_sum<M){
            if(cur_cost==pre_cost){
                cost+=cur_cost;
            }else{
                cost=cur_cost;
                pre_cost=cur_cost;
                // cout<<cost<<endl;    
            }
            pre_cost=cur_cost;
        }else{
            if((pre_cost!=cur_cost) && cur_cost<cost){
                cost=cur_cost;
                pre_cost=cur_cost;
            }
        }
        weight_sum+=v[i].first;
        
        
    }
    return cost;
}

// int solve(){
//     if(MAX_WEIGHT[0]<M){
//         return -1;
//     }
//     int min_cost=MAX_COST;
//     for(int i=0;i<N;++i){
//         if(MAX_WEIGHT[i]>=M){
//             int curPrice=v[i].second;
//             int idx=i+1;
//             int other_same_objects_sum=0;
            
//             while(idx<N){
//                 if(curPrice==v[idx].second){
//                     other_same_objects_sum+=v[idx].first;
//                     ++idx;
//                 }else{
//                     break;
//                 }
//             }
//             CAN_COVER[i]=MAX_WEIGHT[i]-other_same_objects_sum;
//             if(CAN_COVER[i]>=M){
//                 min_cost=min(min_cost,v[i].second);
//             }else{
//                 int curSum=CAN_COVER[i];
//                 int cnt=0;
//                 for(int j=i+1;j<idx;++j){
//                     curSum+=v[j].first;
//                     ++cnt;
//                     if(curSum>=M){
//                         min_cost=min(min_cost,curPrice * (cnt+1));
//                         break;
//                     }
//                 }
//             }       
//         }
//     }
//     // cout<<"COVER"<<endl;
//     // for(int i=0;i<N;++i){
//     //     cout<<CAN_COVER[i]<<endl;
//     // }
//     // cout<<endl;
//     return min_cost;
// }    

int main(){
    Input();
    cout<<solution();
}