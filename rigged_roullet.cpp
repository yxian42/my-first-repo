#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <chrono>
void lfsr(std::uint32_t &value, const std::uint32_t mask = 0x8020'0003) {
    bool parity = 0;
    std::uint32_t temp = value & mask;
    while (temp) {
        parity = !parity;
        temp = temp & (temp - 1);
    }
    value = (value << 1) | (std::uint32_t)parity;
}
template <typename T>
T& rigged_sample(std::vector<T>& vec, std::uint32_t& lfsr_state) {
    lfsr(lfsr_state);
    unsigned int rand_val = lfsr_state % 100;
    if (rand_val < 50 || vec.size() == 1) {
        return vec[0];
    } else {
        unsigned int index = 1 + (lfsr_state % (vec.size() - 1));
        return vec[index];
    }
}

int main() {
    std::vector<std::string> options;
    std::string line;

    // 1. 開始計時（計算使用者輸入選項花費的時間）
    auto start = std::chrono::high_resolution_clock::now();

    // 2. 讀取多行輸入，直到遇到空白行為止
    while (std::getline(std::cin, line) && !line.empty()) {
        options.push_back(line);
    }

    // 結束計時並計算毫秒數 x
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    unsigned int x = static_cast<unsigned int>(duration.count());

    // 若輸入太快導致 0 毫秒，至少補償 1 次更新
    if (x == 0) {
        x = 1;
    }

    // 3. 設定 LFSR 起始值為 0x40896701，並依照花費毫秒數 x 更新 x 次
    std::uint32_t lfsr_state = 0x40896701;
    for (unsigned int i = 0; i < x; ++i) {
        lfsr(lfsr_state);
    }

    // 4. 進行抽獎並印出結果
    if (!options.empty()) {
        std::string& selected = rigged_sample(options, lfsr_state);
        std::cout << selected << std::endl;
    }

    return 0;
}