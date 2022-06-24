#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int arr[]={100,80,60,70,60,75,85};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack<pair<int,int>> st;
    vector<int> v;
    for(int i=0; i<n; i++){
        if(st.empty()){
            v.push_back(-1);
        }
        else if(!st.empty() && arr[i]<st.top().first){
            v.push_back(st.top().second);
        }
        else if(!st.empty() && arr[i]>st.top().first){
            while(!st.empty() && arr[i]>st.top().first){
                st.pop();
            }
            if(st.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;


    for(int i=0; i<v.size(); i++){
       v[i]=i-v[i];
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
