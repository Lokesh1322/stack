#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={4,5,2,10,8};
    stack<int> st;
    vector<int> v;
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            v.push_back(-1);
        }
        else if(!st.empty() && st.top()<arr[i]){
            v.push_back(st.top());
        }
        else if(!st.empty() && st.top()>=arr[i]){
            while(!st.empty() && st.top()>=arr[i]){
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
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

