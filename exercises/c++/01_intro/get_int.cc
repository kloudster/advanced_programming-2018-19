#include <iostream>
#include <iomanip>

int main() {
  int a=0;
  double d;
  std::cout << "Write an integer\n";
  while (!(std::cin >> a)) {
    std::cout << "\n Write an integer asshole \n ";
    std::cin.clear();
    std::cin.ignore();
  }
  std::cout << a<< std::endl;
  
}
