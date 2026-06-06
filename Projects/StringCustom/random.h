#ifndef RANDOM_H
#define RANDOM_H

class RandomNumberGenerator {
private:
    const int A, B, C;
    unsigned long long seed;
public:
    RandomNumberGenerator(int = 0, int = 0, int = 1, long long = 0ull);
    double rand();
    int rand_int(int = 1);
};

#endif
