#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
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

map<char, string> wd;

bool check(vector<string> v, vector<string> w, map<char, int> mp){
  wd.clear();
  REP(i, v.size()){
    REP(j, v[i].size()){
      if(mp[v[i][j]] > w[i].size()) return false;

      if(wd.find((v[i][j])) != wd.end() && wd[v[i][j]] != w[i].substr(0, mp[v[i][j]])) return false;
      wd[v[i][j]] = w[i].substr(0, mp[v[i][j]]);
      w[i].erase(w[i].begin(), w[i].begin() + mp[v[i][j]]);
      if(j == v[i].size()-1 && w[i].size() >0) return false;
    }
  }
  return true;
}

int main(){
  int k, n;
  cin >> k >> n;
  vector<string> v, w;
  REP(i,n){
    string tv, tw;
    cin >> tv >> tw;
    v.push_back(tv);
    w.push_back(tw);
  }

  REP(a1,3){
    REP(a2, 3){
      REP(a3, 3){
        REP(a4, 3){
          REP(a5, 3){
            REP(a6, 3){
              REP(a7, 3){
                REP(a8, 3){
                  REP(a9, 3){
                    map<char, int> mp;
                    mp['1'] = a1+1;
                    mp['2'] = a2+1;
                    mp['3'] = a3+1;
                    mp['4'] = a4+1;
                    mp['5'] = a5+1;
                    mp['6'] = a6+1;
                    mp['7'] = a7+1;
                    mp['8'] = a8+1;
                    mp['9'] = a9+1;
                    if(check(v, w, mp)){
                      REP(i,9){
                        if(wd.find('1'+i) != wd.end()) cout << wd['1' + i] << endl;
                      }
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }


  return 0;
}
