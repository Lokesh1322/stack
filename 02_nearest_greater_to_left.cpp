#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,3,2,4};
    stack<int> st;
    vector<int> v;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
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
            else{
                v.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
