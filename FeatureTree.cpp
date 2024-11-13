#include "FeatureTree.h"

FeatureTree::FeatureTree(int features) {
  numFeatures = features;
  initialState = nullptr;
  bestFeatureSet = nullptr;
  maxAccuracy = 0;
}


void FeatureTree::forwardSelection() {
  
  



  if (bestFeatureSet == nullptr) {
    cout << "The best feature subset is using no features with an accuracy of " << maxAccuracy << "%" << endl;
  }
}