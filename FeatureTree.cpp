#include "FeatureTree.h"

FeatureTree::FeatureTree(int features) {
  numFeatures = features;
  initialState = nullptr;
  bestFeatureSet = nullptr;
  maxAccuracy = 0;
}


void FeatureTree::forwardSelection() {
  initialState = new Node();
  initialState->printFeature();


    // if (numFeatures > 0) {
    //   cout << "Beginning search" << endl;

    //   for (int i = 1; i <= numFeatures; i++) {
    //     for (int i = )
    //   }
    // }

  
}

bool FeatureTree::duplicatesExist(vector<int> set, int firstNum) {
  
  for (int i = 0; i < set.size(); i++) {
    if (firstNum == set.at(i)) 
      return true;
  }

  return false;

}