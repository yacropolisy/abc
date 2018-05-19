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

int main(){
  string s;
  cin >> s;
  int len = s.size();
  int b_plus[len], b_minus[len];
  // int f_plus[len], f_minus[len];
  REP(i,len){
    b_plus[i] = 0;
    b_minus[i] = 0;
    // f_plus[i] = 0;
    // f_minus[i] = 0;
  }
  REP(i,len-1){
    // if(s[i] == '+'){
    //   f_plus[i+1] = f_plus[i] + 1;
    //   f_minus[i+1] = f_minus[i];
    // }else if (s[i] == '-'){
    //   f_plus[i+1] = f_plus[i];
    //   f_minus[i+1] = f_minus[i] + 1;
    // }else{
    //   f_plus[i+1] = f_plus[i];
    //   f_minus[i+1] = f_minus[i];
    // }
    //
    if(s[len-1-i] == '+'){
      b_plus[len-1-i-1] = b_plus[len-1-i] + 1;
      b_minus[len-1-i-1] = b_minus[len-1-i];
    }else if (s[len-1-i] == '-'){
      b_plus[len-1-i-1] = b_plus[len-1-i];
      b_minus[len-1-i-1] = b_minus[len-1-i] + 1;
    }else{
      b_plus[len-1-i-1] = b_plus[len-1-i];
      b_minus[len-1-i-1] = b_minus[len-1-i];
    }
  }

  // REP(i,len){
  //   cout << b_plus[i] << ",";
  // }
  // cout << endl;
  // REP(i,len){
  //   cout << b_minus[i] << ",";
  // }
  // cout << endl;

  vi points;
  REP(i,len){
    if(s[i] == 'M'){
      points.push_back(b_plus[i] - b_minus[i]);
    }
  }
  sort(ALL(points));

  ll ans = 0;
  REP(i,points.size()){
    if(i < points.size()/2){
      ans -= points[i];
    }else{
      ans += points[i];
    }
  }

  cout << ans << endl;


  return 0;
}
