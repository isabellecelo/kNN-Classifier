#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

class Classifier {

  private:
  double min;
  double max;
  int numFeatures;

  protected:
  vector< vector<double> > training;
  string fileName;
  
  public:
  Classifier(int, string);
  void Train();
  int Test(vector<double>);
  double normalize(double);
  void findNormVals();
  double asciiConversion(string);

  



};

#endif