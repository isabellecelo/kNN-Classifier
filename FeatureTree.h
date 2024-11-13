#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


struct Node {
  Node* parent;
  vector<Node*> children;
  double evaluate() {
    return rand() % 100;
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