#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int idx(int n, int arr[], int s){
    for(int i=0; i<s; i++){
        if(arr[i]==n){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={100,80,60,70,60,75,85};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack<int> st;
    vector<int> v;
    for(int i=0; i<n; i++){
        if(st.empty()){
            v.push_back(-1);
        }
        else if(!st.empty() && arr[i]<st.top()){
            v.push_back(idx(st.top(),arr,n));
        }
        else if(!st.empty() && arr[i]>st.top()){
            while(!st.empty() && arr[i]>st.top()){
                st.pop();
            }
            if(st.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(idx(st.top(),arr,n));
            }
        }
        st.push(arr[i]);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    vector<int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(i-v[i]);
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
