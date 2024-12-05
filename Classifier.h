#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

class Classifier {

  private:
  double min1;
  double min2;
  double max1;
  double max2;
  vector<double> class1Train;
  vector<double> class2Train;
  
  public:
  void Train(string fileName);
  int Test(double);
  void normalize();
  double asciiConversion(string);

  



};

#endif