#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int main(){
    freopen("input.txt", "r+", stdin);
    int t,n;
    cin>>t;
    cout<<t<<endl;
    while (t--) {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

