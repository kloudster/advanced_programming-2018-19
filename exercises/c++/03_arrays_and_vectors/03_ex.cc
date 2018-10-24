#include <iostream>
#include <iomanip>
#include <vector>

int main() {
  std::vector<std::string> list;
  std::vector<int> repeat(1,1);
  std::string word;
  int n{1}, check{0};
  
  std::cin >> word;
  list.push_back(word);
  while (std::cin >> word){
    for (auto i=0;i<n; i++){
      check=0;
      if (word==list[i]){
	repeat[i]++;
	check=1;
	break;
      }
    }
    if (check==0){
      list.push_back(word);
      repeat.push_back(1);
      n++;
    }
  }

  for (auto i=0; i<n; i++){
    std::cout << list[i] << " repeated " << repeat[i] << " times" <<std::endl; 
  }

}
