#include "FeatureTree.h"
#include "Validator.h"
#include "Classifier.h"
using namespace std;

FeatureTree::FeatureTree(int features, string fileName, vector<int> &classes) {
  numFeatures = features;
  bestNode = nullptr;
  maxAccuracy = 0;
  this->fileName = fileName;
  this->classes = classes;
}


void FeatureTree::forwardSelection() {
  Node* curr = new Node();
  curr->evaluate(numFeatures, fileName, classes);
  curr->printFeatureandAccuracy();
  int featuresReached = 0;
  bestNode = curr;
  cout << "2" << endl;

    if (numFeatures > 0) {
      cout << "Beginning search" << endl;

      while (featuresReached < numFeatures) {
        double localMaxAcc = 0;
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
            nextChild->evaluate(numFeatures, fileName, classes);
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
          break;
        }
        
        featuresReached++;

        
      }
    }

    cout << "Finished search!! The best feature subset is: ";
    bestNode->printSet();
    cout << ", which has an accuracy of " << bestNode->accuracy << "%";

  
}

void FeatureTree::backwardElimation() {
  Node* curr = new Node();
  for (int i = 0; i < numFeatures; i++) {
    curr->featureSet.push_back(i+1);
  }
  
  curr->evaluate(numFeatures, fileName, classes);
  curr->printFeatureandAccuracy();
  int featuresReached = numFeatures;
  bestNode = curr;

  if (numFeatures > 0) {

      while (featuresReached > 0) {
        int localMaxAcc = 0;
        Node* localBestNode = nullptr;

        for (int i = 0; i < curr->featureSet.size(); i++) {

           Node* nextChild = new Node();
            // set the child's featureSet to the current feature set
            nextChild->featureSet = curr->featureSet;
            // add the next feature to the child
            nextChild->featureSet.erase(nextChild->featureSet.begin()+i);
            // add the child as a child of curr
            curr->children.push_back(nextChild);
            nextChild->evaluate(numFeatures, fileName, classes);
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

        curr = localBestNode;
        cout << "\nFeature set ";
        curr->printSet();
        cout << " was best, accuracy is " << curr->accuracy << "%\n" << endl;
        if (localMaxAcc < maxAccuracy) {
          cout << "(Warning, accuracy has decreased !!)" << endl;
        }
        
        featuresReached--;
      }
    }

    cout << "Finished search!! The best feature subset is: ";
    bestNode->printSet();
    cout << ", which has an accuracy of " << bestNode->accuracy << "%";



}

bool FeatureTree::duplicatesExist(vector<int> &set, int firstNum) {
  
  for (int i = 0; i < set.size(); i++) {
    if (firstNum == set.at(i)) 
      return true;
  }

  return false;

}