#include "FeatureTree.h"

FeatureTree::FeatureTree(int features) {
  numFeatures = features;
  bestNode = nullptr;
  maxAccuracy = 0;
}


void FeatureTree::forwardSelection() {
  Node* curr = new Node();
  curr->evaluate();
  curr->printFeatureandAccuracy();
  int featuresReached = 0;

    if (numFeatures > 0) {
      cout << "Beginning search" << endl;

      while (featuresReached < numFeatures) {
        int localMaxAcc = 0;
        Node* localBestNode = nullptr; 
        for (int i = 1; i <= numFeatures; i++) {
          
          if (!duplicatesExist(curr->featureSet, i)) {
            // make a child
            Node* nextChild = new Node();
            // set the child's featureSet to the current feature set
            nextChild->featureSet = curr->featureSet;
            // add the next feature to the child
            nextChild->featureSet.push_back(i);
            // add the child as a child of curr
            curr->children.push_back(nextChild);
            nextChild->evaluate();
            if (nextChild->accuracy > maxAccuracy) {
              maxAccuracy = nextChild->accuracy;
              bestNode = nextChild;
            }
            if (nextChild->accuracy > localMaxAcc) {
              localMaxAcc = nextChild->accuracy;
              localBestNode = nextChild;
            }
            nextChild->printFeatureandAccuracy();
          }
        }
        curr = localBestNode;
        cout << "\nFeature set ";
        curr->printSet();
        cout << " was best, accuracy is " << curr->accuracy << "%" << endl;
        if (localMaxAcc < maxAccuracy) {
          cout << "(Warning, accuracy has decreased !!)" << endl;
        }
        
        featuresReached++;
      }
    }

    cout << "Finished search!! The best feature subset is: ";
    bestNode->printSet();
    cout << ", which has an accuracy of " << bestNode->accuracy;

  
}

bool FeatureTree::duplicatesExist(vector<int> set, int firstNum) {
  
  for (int i = 0; i < set.size(); i++) {
    if (firstNum == set.at(i)) 
      return true;
  }

  return false;

}