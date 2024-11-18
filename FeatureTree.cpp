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
    //   ""
    // }

    // for (int i = 1; i <= numFeatures; i++) {


  
}