#include <iostream>
#include <chrono>

namespace co = std::chrono;

/**
 * @brief Return the successor of a natural number.
 * @param n The natural number
 * @return n + 1
 */
unsigned long  successor(unsigned long n)
{
    return n + 1;
}

int main()
{
    auto start = co::high_resolution_clock::now();

    unsigned long sum = 0;
    for (unsigned long i = 0; i < 10'000'000; i++) {
        sum = successor(sum);
    }

    auto end = co::high_resolution_clock::now();
    std::cout << co::duration_cast<co::microseconds>(end - start).count()
    << " microseconds" << '\n';
}
