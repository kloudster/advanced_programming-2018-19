#include <iostream>
#include <algorithm>
#include <vector>


int main() {
  using namespace std;
  double Tread, Tave{0};
  std::vector<double> T;
  int n{0};
    
  while (cin >> Tread){
    T.push_back(Tread);
    n++;
    Tave+=Tread;
  }
  Tave=Tave/n;
  cout << "The average temperature is "<< Tave  << endl;
  sort( T.begin(), T.end() );
  cout << "The median temperature is "<< T[n/2]  << endl;
}
