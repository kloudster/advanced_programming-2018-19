#include <iostream>
#include <iomanip>

int main() {
  double inn=0, conv=0.0254, outt;
  std::string unit;


  std::cin >> inn >> unit;
  if (unit=="inch") {
    std::cout<< inn*conv << " m"<< std::endl;
  }
  else {
    std::cout<< "Well done fuck the brits!"<< std::endl;
  }
  
}
