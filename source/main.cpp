/*************************************************************
* @author   Triston Ruiseco
* @file     main.cpp
* @date     02/08/2021
* @brief    Program to randomly generate and plot a set of numbers.
*************************************************************/

#include <fstream>
#include "random.h"
#include "matplotlibcpp.h"


namespace plt = matplotlibcpp;

int main(int argc, char* argv[]){
  bool help = 0;
  long seed = 133742069;

  // parse user's command line args
  for(int i = 0; i < argc; i++){
    if(strncmp(argv[i],"--help", 6) == 0){
      printhelp = true;
    }
    if(strncmp(argv[i],"-h", 2) == 0){
      printhelp = true;
    }
    if(strncmp(argv[i],"-seed", 5) == 0){
      i++;
      seed = std::stol(argv[i]);
    }
  }

  // print flags if requested
  if(printhelp){
    cout << "Usage: " << argv[0] << " [options]" << endl;
    cout << "  options:" << endl;
    cout << "   --help(-h)          print options" << endl;
    cout << "   -seed [number]      random seed to use" << endl;

    return 0;
  }

  // declare an instance of our Random class
  Random  random(seed);
  // declare an instance of our Random class, with a pointer to the instance
  Random* random_ptr = new Random(seed);

  int N = 5000; // 5000 random data points

  // output space-delimited numbers to data file named data.txt
  std::ofstream outFile;
  std::string fileName = "data.txt";
  outFile.open(fileName);
  for(int i = 0; i < N; ++i){
    outFile << random.rand() << " ";
  }
  outFile.close();

  // copy random numbers from data.txt to a vector x
  std::ifstream inFile;
  double temp = 0.0;
  vector<double> x;
  inFile.open(fileName);
  for(int i = 0; i < N; ++i){
    inFile >> temp;
    x.push_back(temp);
  }
  inFile.close();

  plt::figure(); // declare a new figure (optional if only one is used)

  // formating options for our figure
  plt::hist(x, 50, "b", 0.75);
  plt::title("Uniform random number");
  plt::xlabel("x");
  plt::ylabel("Counts");

  plt::show();
  plt::savefig("random.pdf"); // save the figure

  // clean up memory we allocated in program
  delete random_ptr;

  return 0;
}
