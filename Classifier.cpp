#include "Classifier.h"
#include <sstream>
using namespace std;

void Classifier::Train(string fileName) {
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
      currVec = 1;
      continue;
    } else if (num == 2.00000) {
      currVec = 2; 
      continue;
    }

    // add each value into the right vectors
    if (currVec == 1) {
      class1Train.push_back(num);
    } else if (currVec == 2) {
      class2Train.push_back(num);
    }
  }

  sort(class1Train.begin(), class1Train.end());
  sort(class2Train.begin(), class2Train.end());
  normalize();

  cout << "class1 min: " << class1Train.at(0) << endl;
  cout << "class2 min: " << class2Train.at(0) << endl;
  cout << "class1 size: " << class1Train.size() << endl;
  cout << "class2 size: " << class2Train.size() << endl;

}

void Classifier::normalize() {
  min1 = class1Train.at(0);
  max1 = class1Train.at(class1Train.size()-1);
  min2 = class2Train.at(0);
  max2 = class2Train.at(class2Train.size()-1);

  for (int i = 0; i < class1Train.size(); i++) {
    class1Train.at(i) = (class1Train.at(i)-min1) / (max1-min1);
  }

  for (int i = 0; i < class2Train.size(); i++) {
    class2Train.at(i) = (class2Train.at(i)-min2) / (max2-min2);
  }
  
}

// BORROWED CODE
double Classifier::asciiConversion(string num) {
  istringstream os(num);
  double d;
  os >> d;
  return d;
}


