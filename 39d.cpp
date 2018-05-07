#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

int main(){
  int h, w;
  cin >> h >> w;
  char s[h][w];
  REP(i,h)REP(j,w) cin >> s[i][j];

  bool used[h][w];
  REP(i,h)REP(j,w) used[i][j] = false;

  char ans[h][w];
  REP(i,h)REP(j,w) ans[i][j] = '.';


  REP(i,h){
    REP(j,w){
      bool flag = true;
      for(int x = -1; x <= 1; x++){
        for(int y = -1; y <= 1; y++){
          int a = i + x;
          int b = j + y;
          if(a >= 0 && a < h && b >= 0 && b < w){
            if(s[a][b] == '.') flag = false;
          }
        }
      }
      if(flag){
        ans[i][j] = '#';
        for(int x = -1; x <= 1; x++){
          for(int y = -1; y <= 1; y++){
            int a = i + x;
            int b = j + y;
            if(a >= 0 && a < h && b >= 0 && b < w){
              used[a][b] = true;
            }
          }
        }
      }
    }
  }

  REP(i,h)REP(j,w){
    if(s[i][j] == '#'){
      if(!used[i][j]){
        cout << "impossible" << endl;
        return 0;
      }
    }
  }

  cout << "possible" << endl;
  REP(i,h){
    REP(j,w){
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
