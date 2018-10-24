#include <iostream>


template <typename T>
T* fill(const std::size_t dim, const T first);

template <typename T>
void invprint(const std::size_t dim, const T* vec);

int main() {
  std::cout << "Please insert array lenght: ";
  std::size_t dim; 
  std::cin >> dim;
  if (dim!=0){
    double first;
    std::cout << "\n Please insert your elements"<< std::endl;;  
    std::cin >>  first;
    auto vec=fill(dim, first);
    invprint(dim,vec);
    delete[] vec;
  }
  return 0;
}


template <typename T>
T* fill(std::size_t dim, const T first){
  T * vec{new T[dim]};
  vec[0]=first;
  for (auto i=1; i<dim; i++)
    std::cin >> vec[i];
  return vec;
}

template <typename T>
void invprint(const std::size_t dim, const T* vec){
   
  for (auto i=(int)dim-1; i>-1; i--){
    std::cout << "Element n " << i << " is " << vec[i] << std::endl;;  
  }
}

