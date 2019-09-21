#include <thread>
#include "QueenBee.hpp"

int func(string name) {
  cout << name;
  return 1;
}
template <typename Type>
void MulMatrix(unsigned int size);

int main(void) {
  MulMatrix<int>(6000);

  return 0;
}
template <typename Type>
void MulMatrix(unsigned int size) {
  Type* A = new Type[size * size];
  Type* B = new Type[size * size];
  Type* C = new Type[size * size];

  for (int i = 0; i < size * size; i++) {
    A[i] = 1;
    B[i] = 2;
    C[i] = 0;
  }

  unsigned int* ptr_size = &size;

  ///////////////////////////////////////////////
  Keeper queen("kernel.txt");
  queen.Info();
  Function MulMatrix("mul", "MulMatrix");
  MulMatrix.SetArgument<Type>(A, {size, size}, false);
  MulMatrix.SetArgument<Type>(B, {size, size}, false);
  MulMatrix.SetArgument<Type>(C, {size, size}, true);
  MulMatrix.SetArgument<unsigned int>(ptr_size, {1}, false);

  queen.SetFunction(MulMatrix);

 queen.SetTasks("mul", "GPU", {500, 500}, {6000, 6000});

   //queen.SetTask("mul", "CPU", {0, 0}, {2, 2});
   //   queen.SetTask("mul", "GPU", {2, 2}, {4, 4});
 // queen.SetTask("mul", "GPU", {4, 4}, {6, 6});
 //  queen.SetTask("mul", "CPU", {6, 6}, {8, 8});

 // queen.SetTask("mul", "GPU", {8, 8}, {16, 16});
// queen.SetTask("mul", "CPU", {4, 0}, {4, 4});
  //queen.SetTask("mul", "CPU", {0, 4}, {4, 4});
  //queen.SetTask("mul", "CPU", {0, 4}, {4, 8});
 //queen.SetTask("mul", "CPU", {4, 4}, {4, 4});
  // queen.SetTask("mul", "CPU", {0, 0}, {4, 4});
  // queen.SetTask("mul", "ALL", {0, 2}, {2, 4});
  // queen.SetTask("mul", "ALL", {2, 0}, {4, 2});

  
   // queen.SetTask("mul", "CPU", {0, 0}, {2, 2});
   // queen.SetTask("mul", "CPU", {2, 2}, {4, 4});
   // queen.SetTask("mul", "CPU", {4, 4}, {8, 8});
   // queen.SetTask("mul", "CPU", {9, 9}, {16, 16});
   // queen.SetTask("mul", "CPU", {17, 17}, {32, 32});
    //queen.SetTask("mul", "GPU", {9, 9}, {16, 16});
  queen.Start();
  /////////////////////////////////////////////

  cout << endl << endl;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        //std::cout << C[i * size + j] << " ";
    }
    //   cout << endl;
  }

  for (int i = 0; i < size * size; i++) {
    if (C[i] != size * 2) {
      std::cout << "Error" << C[i];
      break;
    }
  }

  // delete[] A;
  // delete[] B;
  // delete[] C;
}