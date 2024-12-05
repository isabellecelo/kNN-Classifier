#include <iostream>
#include <vector>
#include "Classifier.h"
using namespace std;

#ifndef VALIDATOR_H
#define VALIDATOR_H



class Validator : Classifier {

  private: 
  vector<int> featureSubset;


  public:
  Validator(int, vector<int>, string);
  double accuracy();
  bool test(int ID);


};


#endif