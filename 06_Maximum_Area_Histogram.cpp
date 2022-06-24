#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={6,2,5,4,5,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack<pair<int,int>> st;
    stack<pair<int,int>> st2;
    vector<int> v;
    vector<int> v2;
    for(int i=0; i<n; i++){
        if(st.empty()){
            v.push_back(-1);
        }

        else if(!st.empty() && arr[i]>st.top().first){
            v.push_back(st.top().second);
        }

        else if(!st.empty() && arr[i]<st.top().first){
            while(!st.empty() && arr[i]<st.top().first){
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
    cout<<"The nearest smaller to left array:"<<endl;
    for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<endl;


    for(int i=n-1; i>=0; i--){
        if(st2.empty()){
            v2.push_back(n);
        }

        else if(!st2.empty() && arr[i]>st2.top().first){
            v2.push_back(st2.top().second);
        }

        else if(!st2.empty() && arr[i]<=st2.top().first){
            while(!st2.empty() && arr[i]<=st2.top().first){
                st2.pop();
            }
            if(st2.empty()){
                v2.push_back(n);
            }
            else{
                v2.push_back(st2.top().second);
            }
        }
        st2.push({arr[i],i});
    }
    reverse(v2.begin(), v2.end());
    cout<<"The nearest smaller to right array:"<<endl;
     for(int i=0; i<v2.size(); i++){
            cout<<v2[i]<<" ";
        }cout<<endl;

    vector<int> width;
    for(int i=0; i<n; i++){
        width.push_back(abs(v2[i]-v[i]-1));
    }
    cout<<"The width array of histogram is:"<<endl;
    for(int i=0; i<width.size(); i++){
        cout<<width[i]<<" ";
    }cout<<endl;

    vector<int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(arr[i]*width[i]);
    }
    cout<<"The array containing areas of histogram is given as:"<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    int mx=0;
    for(int i=0; i<ans.size()-1; i++){
        if(ans[i+1]>mx){
            mx=ans[i+1];
        }
    }
    cout<<"The maximum area of rectangle in the given histogram is:"<<endl;
    cout<<mx;
    return 0;
}
