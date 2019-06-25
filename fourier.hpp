#ifndef FOURIER_HPP
#define FOURIER_HPP

#include <vector>

struct Fourier {
  struct Node {
    double coefficient;
    double frequency;
    double phase;
  };

  std::vector<Node> cos_values;
  std::vector<Node> sin_values;
};

#endif // FOURIER_HPP
