#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int main(){
    freopen("input.txt", "r+", stdin);
    int t,n;
    cin>>t;
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

//input
//2
//4
//1 2 3 4
//6
//1 2 3 4 5 6


