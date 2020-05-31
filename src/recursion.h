#include "types.h"

int factorial(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n*factorial(n-1);
  }
}

int factorial_vizualization(int n) {
  cout<<"Computing "<<n<<endl;
  if (n == 1) {
    cout<<"Result for "<<n<<" is "<<n<<endl;
    return 1;
  } else {
    int result = factorial_vizualization(n-1);
    cout<<"Result for "<<n<<" is "<<n*result<<endl;
    return n*result;
  }
}
