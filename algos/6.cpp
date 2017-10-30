#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;


vector<pair<int,int> > visited;  
  int a[100][100];  
  int n;


vector<pair<int,int> > path;


 bool contains( int a,int b){
  for(int i=0;i<visited.size();i++){
    if(visited[i].first==a && visited[i].second==b) return true;
  }
  return false;
 }

bool continuee=true;
bool isImportant = false;
int prev;

void reWrite(int a,int b){


  for(int i=0;i<path.size();i++){
    if(path[i].first==a) {
      path.erase(path.begin()+i);
      if(path.size()!=0)
      prev = path[path.size()-1].first;
  //    cout<<path[path.size()-1].first<<endl;
      reWrite(prev,0);
    }
  }
    path.push_back(make_pair(a,b));

}

void havePath(int f,int s){
  for (int j = 1; j <= n; j++) {

     if(continuee){
       if(a[f][j]==1){
         
           if(!contains(f,j)) reWrite(f,j);
            if(j==s) {
              continuee = false;
              
              break;
              }
            else{
             
              if(!contains(f,j)){
                 visited.push_back(make_pair (f,j));
                  visited.push_back(make_pair (j,f));
                 havePath(j,s);
              }
            }
          }
        }
    } 

  }



  int main(){
    freopen ("input.txt","r",stdin);

 int num1,num2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

     cin>>num1>>num2;
  
havePath(num1,num2);
  cout<<"path from "<<num1<<" to "<<num2<<":"<<endl;
for(int i=0;i<path.size();i++){
  if(path[path.size()-1].second!=num2){
    cout<<"no path between "<<num1<<" and "<<num2;
     break;
 }
  if(path[i].second!=0)
     cout<<path[i].first<<" -> "<<path[i].second<<endl;
}

return 0;

}
