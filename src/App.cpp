#include <cmath>
#include <utility>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

std::pair<double, double> standard_normal_distributions (std::mt19937 , std::uniform_real_distribution<> );


int main() { 
  
  std::random_device rand;
  std::mt19937 eng (rand());
  std::uniform_real_distribution<> distrib(0, 1);
  
  std::unique_ptr<std::vector<double>> Thread1 = std::make_unique<std::vector<double>> ();

  for (unsigned i = 0; i < 10; i++) {
	Thread1 -> push_back(distrib(eng));
  }

  for (auto i : *Thread1) {
	std::cout<<"Our random vector contains "<<i<<std::endl;
  }
  
  std::cout<<Thread1<<std::endl<<&Thread1<<std::endl;

  std::cout<<M_PI<<std::endl;

  auto p1 = standard_normal_distributions(eng, distrib);
  
  std::printf("Our random values from two standard normal distributions are X = %F and Y = %F", p1.first, p1.second);
  
  return 0;

}

// returns polar coordinates of 
std::pair<double, double> standard_normal_distributions (std::mt19937 engine, std::uniform_real_distribution<> distribution) {
  double unif_1 = distribution(engine);
  double unif_2 = distribution(engine);
  std::printf("Uniform 1 is %F, and Uniform 2 is %F", unif_1, unif_2);

  std::cout<<std::endl;

  std::cout<<2 * M_PI * unif_2<<std::endl;
  
  double X = std::sqrt(-2 * std::log(unif_1)) * std::cos(2 * M_PI * unif_2);
  double Y = std::sqrt(-2 * std::log(unif_1)) * std::sin(2 * M_PI * unif_2);
  
  return std::pair<double, double> (X, Y);
}
