#include "Validator.h"
#include <iostream>
using namespace std;

Validator::Validator(int numFeatures, vector<int> subset, string fileName) : Classifier(numFeatures, fileName) {
  featureSubset = subset; 
}

double Validator::accuracy() {
  Train();
  double accuracy = 0;
  for (int i = 0; i < training.size(); i++) {
    if (test(i))
      accuracy++;
  }

  cout << "training size:" << training.size() << endl;
  accuracy = accuracy/training.size();
  return accuracy;
}

bool Validator::test(int ID) {
  double minDistance = numeric_limits<double>::max();
  int currClass = 0;
  double currDistance = 0;
  double featureSubtract = 0;
  for (int i = 0; i < training.size(); i++) {
    if (i == ID) {
      continue;
    }

    for (int j = 0; j < featureSubset.size(); j++) {
      int featureNum = featureSubset.at(j);
      featureSubtract += training.at(i).at(featureNum)-training.at(ID).at(featureNum);
      featureSubtract = pow(featureSubtract, 2);
      currDistance += featureSubtract;
    }
    currDistance = sqrt(currDistance); 
    if (currDistance < minDistance) {
      minDistance = currDistance;
      currClass = training.at(i).at(0);
    }
  }
  if (currClass == training.at(ID).at(0)) {
    return true;
  }
  return false;
}