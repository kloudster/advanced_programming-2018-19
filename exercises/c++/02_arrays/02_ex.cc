#include <iostream>
#include <cmath>

int prime (const int x, const int n, const int * vec);

int main() {
  using namespace std;
  size_t dim; 
  int num, n;
  int * vec;
  cout << "Until which number do you want me to check for primes: "<< endl;
  cin >> num;
  //It is in any case safe to allocate a vector num/2+1 elements
  dim=(size_t)num/2+1;
  vec=new int [dim]{};
  if (num<2){
    cout << "Sorry, no number found"<< std::endl;;  
  }
  else{
    cout << "Your prime numbers are: "<< endl;
    vec[0]=2;
    cout << "2"<< endl;
    n=1;
    for(auto i=2; i<num+1; i++){
      if (prime(i, n, vec)==1){
	vec[n]=i;
	n++;
	cout << i <<endl;
      }
    }
  }
}


int prime (const int x, const int n, const int * vec){
  int checkuntil{}, last;  
  checkuntil=(int)sqrt(x)+1;
  
  for (auto i=0; i<n; i++){
    last=x%vec[i];
    if ((last==0)||(vec[i]>checkuntil)) break;
  }
  //  if (x%vec[i]!=0) return 0;
  if (last!=0) {
    return 1;
  } else return 0;
}
