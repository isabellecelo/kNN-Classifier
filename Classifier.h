#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

class Classifier {

  private:
  int numFeatures;

  protected:
  vector< vector<double> > training;
  vector<double> mins;
  vector<double> maxes;
  string fileName;
  
  public:
  Classifier(int, string);
  void Train();
  int Test(vector<double>);
  double normalize(double,int);
  void findNormVals();
  double asciiConversion(string);

  



};

#endif