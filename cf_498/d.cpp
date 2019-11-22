#include <bits/stdc++.h>

using namespace std;

int t = 0;

void compare2( char a , char b ){
  if ( a != b) t++;  
}
void compare4( char a1, char a2, char b1 , char b2 ){

  if ( b1==b2 && a1!= a2 ){
    if (a1!=b1)
      t++;  
    if (a2!= b1)
      t++;  
  }
  else if ( b1 != b2){
    if (a1!= a2){
      if (a1!= b1 && a1!= b2){
        t++;  
      }
      if (a2!= b1 && a2!= b2){
        t++;  
      }
    }else{
      t+=2;  
    }   
  }

}

int main(){
 
  int n;
  string a, b;
  cin>>n; 
  cin >> a;
  cin >> b;

  for (int i=0 ; i < (n/2) - 1 ; i++){
    compare4( a[i], a[n-i], b[i],b[n-i]);  
  }

  int teste;
  if (n % 2 == 0 ){
    teste = n;  
  }
  else{
    teste = n+1;  
  }

  compare2(a[teste/2], b[teste/2]);

  cout << t<<endl;
  return 0; 
}
