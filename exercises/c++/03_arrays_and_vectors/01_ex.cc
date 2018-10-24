#include <iostream>

template <typename T>
void transpose (const int r, const int c, T * mat);

template <typename T>
void printmat (const int r, const int c, const T * mat);

int main() {
  using namespace std;
  int c, r;
  int * mat;
  cout << "Type the number of rows and columns"<< endl;
  cin >> r >> c;
  //It is in any case safe to allocate a vector num/2+1 elements
  if ((r==0)||(c==0)){
    cout << "Meaningless number of rows or columns"<< endl;
    return 1;
  }
  mat=new int [r*c];
  for(auto i=0; i<r*c; i++) mat[i]=rand();
  cout << "Before"<< endl;
  printmat(r,c,mat);
  transpose(r,c,mat);
  cout << "After"<< endl;
  printmat(c,r,mat);
  delete [] mat;
}

template <typename T>
void transpose (const int r, const int c, T * mat){

  //Ask for suggestions
  T* old{new T[r*c]};
  for (auto i=0;i<r*c; i++) old[i]=mat[i];
  for (auto j=0; j<c; j++){
    for (auto i=0; i<r; i++){
      mat[i+j*r]=old[j+i*c];
    }
  }
  delete [] old;
}

template <typename T>
void printmat (const int r, const int c, const T * mat){
  for (auto j=0; j<r; j++){
    for (auto i=0; i<c; i++){
      std::cout << mat[i+j*c]<< " ";
    }
    std::cout << std::endl;;
  }
}
