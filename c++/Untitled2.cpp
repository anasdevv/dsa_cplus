#include <iostream>
#include <exception>
using namespace std;


int main () {
  try
  {
  	int c = 3 / 0;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }
  return 0;
}
