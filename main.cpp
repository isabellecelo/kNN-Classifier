#include <iostream>
#include "FeatureTree.h"
#include "Classifier.h"
using namespace std;

int main() {

  // int features;
  // int algo;
  // cout << "Welcome to Isabelle's Feature Selection Algorithm\n" << endl;
  // cout << "Please enter the total number of features: ";
  // cin >> features;

  // cout << endl;
  // cout << "Type the number of the algorithm you want to run.\n" << endl;
  // cout << "\tForward Selection\n\tBackward Elimination\n\tIsabelle's Special Algorithm\n" << endl;
  // cin.ignore();
  // cin >> algo;


  // FeatureTree newTree(features);
  // if (algo == 1) {
  //   newTree.forwardSelection();
  // } else if (algo == 2) {
  //   newTree.backwardElimation();
  // } else if (algo == 3) {
  //   cout << "3" << endl;
  // }

  Classifier hi;
  hi.Train("small-test-dataset.txt");



  return 0; 
}