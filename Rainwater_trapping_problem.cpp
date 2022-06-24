#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);


    vector<int> v;
    v.push_back(arr[0]);
    for(int i=0; i<n-1; i++){
        v.push_back(max(v[i],arr[i+1]));
    }
    cout<<"Maximum greater to right array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;


    vector<int> v2;
    v2.push_back(arr[n-1]);
    for(int i=n-1; i>=0; i--){

        v2.push_back(max(v2[n-1-i],arr[n-1-i]));

    }
    reverse(v2.begin(), v2.end());
    cout<<"Maximum greater to left: "<<endl;
    for(int i=0; i<n; i++){
        cout<<v2[i]<<" ";
    }cout<<endl;


    vector<int> mini;
    for(int i=0; i<n; i++){
        mini.push_back(min(v2[i],v[i]));
    }
    cout<<"Minimum height from left and right: "<<endl;
    for(int i=0; i<mini.size(); i++){
        cout<<mini[i]<<" ";
    }cout<<endl;


    vector<int> water_height;
    for(int i=0; i<n; i++){
        water_height.push_back(mini[i]-arr[i]);
    }
    cout<<"Height of water above bolcks: "<<endl;
    for(int i=0; i<water_height.size(); i++){
        cout<<water_height[i]<<" ";
    }cout<<endl;

    int ans=0;
    for(int i=0; i<water_height.size(); i++){
        ans+=water_height[i];
    }
    cout<<"The maximum amount of water trapped inside blocks is: "<<endl;
    cout<<ans<<endl;
    return 0;
}
