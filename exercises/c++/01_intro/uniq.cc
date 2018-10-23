#include <iostream>
#include <iomanip>

int main() {
  std::string prev;
  int check=0, a=0;
  
  
  for(std::string line; std::getline(std::cin,line);){
    if (check>0){
      if (prev==line){
	a++;
	check=2;
      }
      else {
	std::cout << a <<" " << prev<< "\n";
	prev=line;
	a=1;
	check=3;
      }
    }
    else {
      prev = line;
      check++;
      a=1;
    }
  }
  if (check == 2)   std::cout << a <<" " << prev<< "\n";
  return 0;
}
