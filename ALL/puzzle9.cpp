#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int revDir[] = {2,3,0,1};
struct Moves {
    int x;
    int y;
    int dir;
};
Moves moves[1000000];
int movesCnt;
const int n = 3;
int arr[n][n];
int valid[n][n];
bool visited[n][n];

bool check(int x, int y){
    if(valid[x][y] != arr[x][y]) return false;
    
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

bool getsoln(int x, int y){
    if(check(x,y)){
        return true;
    }
    for(int i=0;i<4;i++){
        if(visited[x][y] == true){
            continue;
        }
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx<0 || yy<0 || xx>=n || yy>=n){
            continue;
        }
        
        if(!visited[x][y]){
            swap(valid[x][y],valid[xx][yy]);
            visited[x][y] = true;
            moves[movesCnt].x = xx;
            moves[movesCnt].y = yy;
            moves[movesCnt].dir = revDir[i];
            movesCnt++;
            
            bool res = getsoln(xx,yy);
            if(res){
                return true;
            }
            
            swap(valid[x][y],valid[xx][yy]);
            visited[x][y] = false;
            movesCnt--;
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
        movesCnt = 0;
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

        getsoln(2,2);
        
        for(int i=0;i<movesCnt;i++){
            cout<<"( "<<moves[i].x<<", "<<moves[i].y<<" ) -> "<<moves[i].dir<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}





