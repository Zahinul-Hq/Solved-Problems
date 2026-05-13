#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <ctime>


std::string random_batch_name(std::mt19937& rng, int max_length = 10) {
    static const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<> len_dist(1, max_length);
    std::uniform_int_distribution<> char_dist(0, chars.size() - 1);
    int length = len_dist(rng);
    std::string result;
    for (int i = 0; i < length; ++i) {
        result += chars[char_dist(rng)];
    }
    return result;
}


std::string random_message(std::mt19937& rng, int length) {
    static const std::string chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?-:;";
    std::uniform_int_distribution<> dist(0, chars.size() - 1);
    std::string result;
    for (int i = 0; i < length; ++i) {
        result += chars[dist(rng)];
    }
    return result;
}

void generate_test_case(const std::string& filename, int t, int min_len, int max_len, int min_key, int max_key) {
    std::ofstream fout(filename);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> key_dist(min_key, max_key);
    // Ensure min_len is at least 20
    int real_min_len = std::max(min_len, 20);
    std::uniform_int_distribution<> len_dist(real_min_len, max_len);
    fout << t << "\n";
    for (int i = 0; i < t; ++i) {
        int key = key_dist(rng);
        int msg_len = len_dist(rng);
        std::string msg = random_message(rng, msg_len);
        std::string batch = random_batch_name(rng, 10);
        fout << batch << " " << key << ": " << msg << "\n";
    }
    fout.close();
}

int main() {
    // Generate 10 demo files with different sizes and parameters, min length always at least 20, and at least 21 test cases per file
    generate_test_case("TLE_TEST_CASE_EyeHearYou.txt", 1000, 10000, 10000, -5, 5);

    std::cout << "10 demo test case files generated.\n";
    return 0;
}