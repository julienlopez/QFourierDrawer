#ifndef FOURIER_HPP
#define FOURIER_HPP

#include <vector>

struct Fourier
{
    struct Node
    {
        double frequency;
        double phase;
    };

    std::vector<Node> values;
};

#endif // FOURIER_HPP
