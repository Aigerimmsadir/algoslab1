#include <iostream>
#include <set>
#include <vector>
using namespace std;
  vector<pair<int, int> > visited;  //location (x,y) of visited
  int a[100][100];
  int n;

  bool contains(int a, int b) {
    for (int i = 0; i < visited.size(); i++) {
      if (visited[i].first == a && visited[i].second == b) return true;
    }
    return false;
  }

  bool isPoltos;
  string havePath(int f, int s) {


    for (int j = 1; j <= n; j++) {
      if (a[f][j] == 1) {
        if (j == s)
          isPoltos = 1;

        else {


          if (!contains(f, j)) {
            visited.push_back(make_pair(f, j));
            visited.push_back(make_pair(j, f));
            havePath(j, s);

          }
        }
      }
    }
    if (isPoltos == 1) return "POLTOS";
    return "DAUREN";
  }

  int main() {
   // freopen("input.txt", "r", stdin);

    int num1, num2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }

    cin >> num1 >> num2;
    if (a[num1][num2] == 1) cout << "POLTOS";
    else  cout << havePath(num1, num2);

    return 0;

  }
