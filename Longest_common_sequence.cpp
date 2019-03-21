//2017030191_LeeHyunji

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>

#define LEFT 1
#define MID 2
#define TOP 3

using namespace std;

int number[505][505];
int direct[505][505];

stack<char> ans;

int main(){
  string a,b;
  cin >> a >> b;

  string tmp;
  if(a.length() < b.length()){
    tmp = a;
    a = b;
    b = tmp;
  }
  //cout << a << endl << b << endl;
  //a가 더 긴 스트링

  size_t alen = a.length();
  size_t blen = b.length();

  for(int i = 0 ; i <= blen ; i++){
    number[i][0] = 0;
  }

  for(int i = 0 ; i <= alen ; i++){
    number[0][i] = 0;
  }

  for(int i = 1 ; i <= blen ; i++){
    for(int j = 1 ; j <= alen ; j++){
      if(a[j-1] == b[i-1]){
        number[i][j] = number[i-1][j-1] + 1;
        direct[i][j] = MID;
      }
      else{
        if(number[i-1][j] >= number[i][j-1]){
          number[i][j] = number[i-1][j];
          direct[i][j] = TOP;
        }
        else{
          number[i][j] = number[i][j-1];
          direct[i][j] = LEFT;
        }
      }
    }
  }

  int i = blen;
  int j = alen;

  while(number[i][j] != 0){
    if(direct[i][j] == LEFT){
      j--;
    }
    else if(direct[i][j] == TOP){
      i--;
    }
    else if(direct[i][j] == MID){
      ans.push(a[j-1]);
      i--;
      j--;
    }
  }

  while(!ans.empty()){
      cout << ans.top();
      ans.pop();
  }
  cout << endl;

  return 0;
}

