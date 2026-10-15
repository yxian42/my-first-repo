// filename: ns.cpp
#include <iostream>
#include <vector>
#include <type_traits>
#include <initializer_list>

using namespace std;

/**
 * @brief Numeric vector.
 * @param L the dimension of the vector
 * @param T the underlying type of the number
 */
template <unsigned int L,
          typename T = float,
          std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
class vector {
public:
    vector(std::initializer_list<T> content = {}) {}
    /* other public member functions */
    private:
    /* private members */
};

/*
[C++20] Alternatively:

 template <unsigned int L> requires std::is_arithmetic_v<T>
 class vector { ... }
*/

int main()
{
    int vector_count;
    cin >> vector_count;

    vector<3, int> zero;
    vector<vector<3, int>> vecs;
    for (int i = 0; i < vector_count; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        vecs.push_back(vector<3, int>({a,b,c}));
    }
}
