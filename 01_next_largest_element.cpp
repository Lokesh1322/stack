#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,3,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            v.push_back(-1);
        }
        else if(!st.empty() && st.top()>arr[i]){
            v.push_back(st.top());
        }
        else if(!st.empty() && st.top()<=arr[i]){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                v.push_back(-1);
            }
            else if(st.top()>arr[i]){
                v.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
