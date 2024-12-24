#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>

#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>

std::mutex mtx;

int main() {
    const int threadsNum = 4;
    boost::asio::thread_pool pool(threadsNum);
    std::string line;
    std::map<std::string, std::pair<double, int>> category_data;

    while (std::getline(std::cin, line)) {
        boost::asio::post(pool, [line, &category_data]() -> void {
            std::istringstream sstream(line);
            std::string category, revenue_str, quantity_str;

            std::getline(sstream, category, ',');
            std::getline(sstream, revenue_str, ',');
            std::getline(sstream, quantity_str, ',');

            double revenue = stod(revenue_str);
            int quantity = stoi(quantity_str);
            {
                std::lock_guard<std::mutex> lck(mtx);
                category_data[category].first += revenue;
                category_data[category].second += quantity;
            }
        });
    }
    pool.join();

    // Sorting data
    std::vector<std::pair<std::string, std::pair<double, int>>> sorted_data;
    for (const auto& entry : category_data) {
        sorted_data.emplace_back(entry.first, entry.second);
    }
    // Parallel sort using execution policy
    // Note: to compile for it, use `-std=c++17` and `-ltbb` flags (make sure to have libtbb-dev installed!)
    std::sort(std::execution::par_unseq, sorted_data.begin(), sorted_data.end(), [](const auto& a, const auto& b) { return a.second.first > b.second.first; });

    for (const auto& entry : sorted_data) {
        std::cout << entry.first << " --- " << entry.second.first << " --- " << entry.second.second << "\n";
    }
    return 0;
}