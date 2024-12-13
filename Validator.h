#include <iostream>
#include <vector>
#include "Classifier.h"
using namespace std;

#ifndef VALIDATOR_H
#define VALIDATOR_H



class Validator : public Classifier {

  private: 
  vector<int> featureSubset;



  public:
  Validator(int, vector<int>&, string, vector<int>);
  double accuracy();
  bool Test(int ID);


};


#endif