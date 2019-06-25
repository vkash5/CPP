#include<bits/stdc++.h>
using namespace std;
const int n = 3;
int arr[n][n];
int valid[n][n];
bool visited[n][n];
vector<pair<int,int>> pos;
vector<int> dir;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void print(int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check(){
    int matched = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(valid[i][j] == arr[i][j]){
                continue;
            }
            else{
                matched = false;
                break;
            }
        }
    }
    
    if(matched){
        return true;
    }
    else{
        return false;
    }
}

bool getsoln(pair<int,int> current, pair<int,int> parent, vector<pair<int,int>> &pos, vector<int> &dir){
    if(check()){
        return true;
    }
    for(int i=0;i<4;i++){
//        visited[x][y] = true;
        int x = current.first;
        int y = current.second;
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx<0 || yy<0 || xx>=n || yy>=n){
            continue;
        }
        
        if(xx!=parent.first || yy!=parent.second){
            swap(valid[x][y],valid[xx][yy]);
//            visited[x][y] = true;
            pos.push_back(make_pair(xx, yy));
            dir.push_back(i);
//            print(valid);
//            cout<<endl;
            bool res = getsoln(make_pair(xx,yy),make_pair(x,y),pos,dir);
            if(res){
                return true;
            }
            
            swap(valid[x][y],valid[xx][yy]);
//            visited[x][y] = false;
            pos.pop_back();
            dir.pop_back();
        }
    }
    return false;
}

int main(){
    freopen("input.txt", "r+", stdin);
    int t;
    cin>>t;
    while (t--) {
        int c = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                valid[i][j] = c++;
            }
        }
        valid[2][2] = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = false;
            }
        }
        pos.clear();
        dir.clear();
        pair<int,int> currnet,parent;
        currnet = make_pair(2, 2);
        parent = make_pair(2, 2);
        getsoln(currnet,parent,pos,dir);
        
        for(int i=0;i<pos.size();i++){
            cout<<"( "<<pos[i].first<<" "<<pos[i].second<<" ) -> "<<dir[i]<<endl;
        }
    }
    
    return 0;
}





