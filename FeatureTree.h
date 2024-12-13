#include <iostream>
#include <vector>
#include <cstdlib>
#include "Validator.h"
#include "Classifier.h"
using namespace std;

#ifndef FEATURETREE_H
#define FEATURETREE_H


struct Node {
  Node* parent;
  vector<Node*> children;
  double accuracy;
  vector<int> featureSet;
  
  

  void evaluate(int numFeatures, string fileName, vector<int> classes) {
    Validator newValidator(numFeatures, featureSet, fileName, classes);
    newValidator.Train();
    accuracy =  newValidator.accuracy()*100;
  }

  void printFeatureandAccuracy() {
    if (featureSet.size() > 0 ) {
        cout << "\tUsing feature(s) ";
      for (int i = 0; i < featureSet.size(); i++) {
        if (i == 0)
          cout << "{";
        cout << featureSet.at(i);
        if (i == featureSet.size()-1) 
          cout << "}";
        else 
          cout << ",";
      }

      cout << " accuracy is " << accuracy << "%" << endl;

    } else {
      cout << "\tUsing no features and \"random\" evaluation, I get an accuracy of " << accuracy << "%\n" << endl;
    }
  }

  void printSet() {
     if (featureSet.size() > 0 ) {
      for (int i = 0; i < featureSet.size(); i++) {
        if (i == 0)
          cout << "{";
        cout << featureSet.at(i);
        if (i == featureSet.size()-1) 
          cout << "}";
        else 
          cout << ",";
      }
    } else {
      cout << "{}";
    }
  }
};



class FeatureTree {

  private:
    int numFeatures;
    double maxAccuracy;
    Node* bestNode;
    string fileName;
    vector<int> classes;
  

  public:
    FeatureTree(int, string, vector<int>&);
    void forwardSelection();
    void backwardElimation();
    bool duplicatesExist(vector<int>&, int);



};

#endif