#include <iostream>
#include "FeatureTree.h"
#include "Classifier.h"
#include "Validator.h"
#include <ctime>
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
  cout << endl;
  vector<int> smallSubset;
  smallSubset.push_back(3);
  smallSubset.push_back(5);
  smallSubset.push_back(7);

  Validator small(10, smallSubset, "small-test-dataset.txt");
  clock_t start_time1 = clock();
  small.Train();
  clock_t end_time1 = clock();
  double elapsed_time1 = double(end_time1 - start_time1) / CLOCKS_PER_SEC;
  cout << "Time spent on training small-test-dataset: " << elapsed_time1 << " seconds" << endl;

  clock_t start_time2 = clock();
  cout << "Using feature subset {3,5,7}, small-test-dataset has an accuracy of: " << small.accuracy() << endl;
  clock_t end_time2 = clock();
  double elapsed_time2 = double(end_time2 - start_time2) / CLOCKS_PER_SEC;
  cout << "Time spent on small-test-dataset's accuracy: " << elapsed_time2 << " seconds" << endl;

  cout << endl;

  vector<int> largeSubset;
  largeSubset.push_back(1);
  largeSubset.push_back(15);
  largeSubset.push_back(27);

  Validator large(40, largeSubset, "large-test-dataset.txt");
  clock_t start_time3 = clock();
  large.Train();
  clock_t end_time3 = clock();
  double elapsed_time3 = double(end_time3 - start_time3) / CLOCKS_PER_SEC;
  cout << "Time spent training large-test-dataset: " << elapsed_time3 << " seconds" << endl;


  clock_t start_time4 = clock();
  cout << "Using feature subset {1,15,27}, large-test-dataset has an accuracy of: " << large.accuracy() << endl;
  clock_t end_time4 = clock();
  double elapsed_time4 = double(end_time4 - start_time4) / CLOCKS_PER_SEC;
  cout << "Time spent on large-test-dataset's accuracy: " << elapsed_time4 << " seconds" << endl;
  
  cout << endl;



  return 0; 
}