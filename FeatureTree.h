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
      cout << "Using no features and \"random\" evaluation, I get an accuracy of " << accuracy << "%\n" << endl;
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
    }
  }
};



class FeatureTree {

  private:
    int numFeatures;
    double maxAccuracy;
    Node* bestNode;
  

  public:
    FeatureTree(int);
    void forwardSelection();
    bool duplicatesExist(vector<int>, int);



};