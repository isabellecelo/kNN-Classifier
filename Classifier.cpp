#include "Classifier.h"
#include <sstream>
#include <limits>
#include <cmath>
using namespace std;


Classifier::Classifier(int features, string file) {
  numFeatures = features;
  fileName = file;

}

void Classifier::Train() {
  findNormVals();
  string stringVal;
  double num;
  int currVec = 0;
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "Error opening: " << fileName << endl;
    return;
  }

    while (file >> stringVal) {
    num = asciiConversion(stringVal);
    if (num == 1.0000000) {
      vector<double> set1;
      set1.push_back(1);
      for (int i = 0; i < numFeatures; i++) {
        file >> stringVal;
        num = asciiConversion(stringVal);
        num = normalize(num);
        set1.push_back(num);
      }
      training.push_back(set1);
    } else if (num == 2.00000) {
      vector<double> set2;
      set2.push_back(2);
      for (int i = 0; i < numFeatures; i++) {
        file >> stringVal;
        num = asciiConversion(stringVal);
        num = normalize(num);
        set2.push_back(num);
      }
      training.push_back(set2);
    }
   
  }

}

void Classifier::findNormVals() {

  string stringVal;
  int currVec;
  double num;
  min = numeric_limits<double>::max();
  max = numeric_limits<double>::min();
  
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "Error opening: " << fileName << endl;
    return;
  }

  while (file >> stringVal) {
    num = asciiConversion(stringVal);
    if (num == 1.0000000) {
      continue;
    } else if (num == 2.00000) {
      continue;
    }
    if (num > max) 
      max = num;
    if (num < min) 
      min = num;

  }

}

double Classifier::normalize(double num) {
  return (num-min) / (max-min);
}

int Classifier::Test(vector<double> test) {

  for (int i = 1; i < test.size(); i++) {
    test.at(i) = normalize(test.at(i));
  }

  double minDistance = numeric_limits<double>::max();
  int currClass = 0;
  double currDistance = 0;
  double featureSubtract = 0;
  for (int i = 0; i < training.size(); i++) {
    for (int j = 1; j < numFeatures; j++) {
      featureSubtract += training.at(i).at(j)-test.at(j);
      featureSubtract = pow(featureSubtract, 2);
      currDistance += featureSubtract;
    }
    currDistance = sqrt(currDistance); 
    if (currDistance < minDistance) {
      minDistance = currDistance;
      currClass = training.at(i).at(0);
    }
  }

  return currClass;

}

// BORROWED CODE
double Classifier::asciiConversion(string num) {
  istringstream os(num);
  double d;
  os >> d;
  return d;
}


