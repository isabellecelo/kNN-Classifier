#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


struct Node {
  Node* parent;
  vector<Node*> children;
  double accuracy;
  vector<int> featureSet;
  

  void evaluate() {
    accuracy = rand() % 100;
  }

  void printFeature() {
    if (featureSet.size() > 0 ) {
        cout << "Using feature(s) ";
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
      cout << "Using no features and \"random\" evaluation, I get an accuracy of " << accuracy << "%" << endl;
    }
  }
  
};


class FeatureTree {

  private:
    Node* initialState;
    int numFeatures;
    double maxAccuracy;
    Node* bestFeatureSet;
  

  public:
    FeatureTree(int);
    void forwardSelection();



};