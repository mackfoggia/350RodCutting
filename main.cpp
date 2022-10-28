#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


#define n 25
int p[n+1];
int T[n+1];
int T2[n+1];


int f(int x);
int fM(int x);
int fT();


int main(){
  srand(time(NULL));

  cout << "p: [";
  p[0] = 0;
  T2[0] = 0;
  for(int i = 1; i <= n; ++i){
    p[i] = rand() % 10 + 1;
    T[i] = -1;
    T2[i] = 0;
    cout << p[i];
    if(i < n) cout << ", ";
  }
  cout << "]" << endl;

//  cout << "Max price: " << f(n) << endl;
//  cout << "Max price - M: " << fM(n) << endl;
  cout << "Max price: " << fT() << endl;

  return 0;
}



int f(int x){
  if(x == 0) return 0;

  int max = 0;

  for(int i = x; i > 0; --i){
    int temp = p[i] + f(x-i);
    if(temp > max) max = temp;
  }

  return max;
}

int fM(int x){
  if(x == 0) return 0;
  if(T[x] != -1) return T[x];

  int max = 0;

  for(int i = x; i > 0; --i){
    int temp = p[i] + fM(x-i);
    if(temp > max) max = temp;
  }

  T[x] = max;

  return max;
}

int fT(){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= i; ++j){
      if((p[j] + T2[i-j]) > T2[i]) T2[i] = p[j] + T2[i-j];
    }
  }

  return T2[n];
}






