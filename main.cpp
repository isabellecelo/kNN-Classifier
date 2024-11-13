#include <iostream>
using namespace std;

int main() {

  int features;
  int algo;
  cout << "Welcome to Isabelle's Feature Selection Algorithm\n" << endl;

  cout << "Please enter the total number of features: ";
  cin >> features;

  cout << endl;
  cout << "Type the number of the algorithm you want to run.\n" << endl;
  cout << "\tForward Selection\n\tBackward Elimination\n\tIsabelle's Special Algorithm\n" << endl;
  cin.ignore();
  cin >> algo;

  if (algo == 1) {
    cout << "1" << endl;
  } else if (algo == 2) {
    cout << "2" << endl;
  } else if (algo == 3) {
    cout << "3" << endl;
  }


  return 0; 
}