#include "Classifier.h"
#include <sstream>
#include <limits>
#include <cmath>
using namespace std;


Classifier::Classifier(int features, string file) {
  numFeatures = features;
  fileName = file;
  for (int i = 0; i <= features; i++) {
    mins.push_back(numeric_limits<double>::max());
    maxes.push_back(numeric_limits<double>::min());
  }

}

void Classifier::Train() {
  findNormVals();
  string stringVal;
  double num;
  int currVec = 0;
  int class1 = 0;
  int class2 = 0;
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "Error opening: " << fileName << endl;
    return;
  }

    while (file >> stringVal) {
    num = asciiConversion(stringVal);
    if (num == 1) {
      vector<double> set1;
      set1.push_back(num);
      for (int i = 1; i <= numFeatures; i++) {
        file >> stringVal;
        num = asciiConversion(stringVal);
        num = normalize(num,i);
        set1.push_back(num);
      }

      training.push_back(set1);
     } else if (num == 2) {
      vector<double> set2;
      set2.push_back(num);
      for (int i = 1; i <= numFeatures; i++) {
        file >> stringVal;
        num = asciiConversion(stringVal);
        num = normalize(num,i);
        set2.push_back(num);

      }
            
      training.push_back(set2);
    }
   
  }


}

void Classifier::findNormVals() {

  string stringVal;
  int currVec;
  int currFeature;
  double num;
  
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "Error opening: " << fileName << endl;
    return;
  }

  
  while (file >> stringVal) {
    num = asciiConversion(stringVal);
    if (num == 1.0000000) {
      currFeature = 1;
      continue;
    } else if (num == 2.00000) {
      currFeature = 1;
      continue;
    }
    if (num > maxes.at(currFeature)) 
      maxes.at(currFeature) = num;
    if (num < mins.at(currFeature)) 
      mins.at(currFeature) = num;

    currFeature++;
  }

}

double Classifier::normalize(double num, int feature) {
  return (num-mins.at(feature)) / (maxes.at(feature)-mins.at(feature));
}

int Classifier::Test(vector<double> test) {

  for (int i = 1; i < test.size(); i++) {
    test.at(i) = normalize(test.at(i),i);
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


