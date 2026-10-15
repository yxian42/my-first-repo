#include <iostream>
#include <cstdint>

// For Question 10
#include <type_traits>
#include <concepts>

std::uint32_t lfsr(std::uint32_t value, const std::uint32_t mask = 0x8020'0003);

int main()
{
    unsigned times;
    std::cin >> times;

    std::uint32_t starting = 0xdead'beef;
    for (unsigned i = 0; i < times; i++) {
        starting = lfsr(starting);
        std::cout << starting << std::endl;
    }
}

/**
 * @brief Check for odd parity.
 *
 * @param n the value to be checked
 * @return true for odd parity
 * @return false for even parity
 */
bool parity(std::uint32_t n)
{
    // From Bit Twiddling Hacks by Sean Eron Anderson
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity;
}

/**
 * @brief Simulate a 32-bit Fibonacci LFSR
 *
 * @param value the value to be shifted
 * @param mask the mask for tap positions
 * @return std::uint32_t the result after doing one step
 */
std::uint32_t lfsr(std::uint32_t value, const std::uint32_t mask)
{
    return (value << 1) | (uint32_t) parity(value & mask);
}
