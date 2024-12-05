#include <iostream>
#include "FeatureTree.h"
#include "Classifier.h"
#include "Validator.h"
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

  // Classifier hi(10,"small-test-dataset.txt" );
  // hi.Train();
  // vector<double> wow;
  // wow.push_back(0);
  // wow.push_back(5.07);
  // wow.push_back(3.15);
  // wow.push_back(1.29);
  // wow.push_back(0.577);
  // wow.push_back(2.73);
  // wow.push_back(1.91);
  // wow.push_back(4.61);
  // wow.push_back(3.32);
  // wow.push_back(4.03);
  // wow.push_back(2.85);

  // cout << hi.Test(wow) << endl;

  vector<int> ew;
  ew.push_back(3);
  ew.push_back(5);
  ew.push_back(7);

  Validator yum(10, ew, "small-test-dataset.txt");
  cout << yum.accuracy() << endl;



  return 0; 
}