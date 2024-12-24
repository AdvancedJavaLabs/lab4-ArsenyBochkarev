#include <iostream>
#include <sstream>
#include <string>
#include <mutex>

#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>

std::mutex mtx;

int main() {
    const int threadsNum = 4;
    boost::asio::thread_pool pool(threadsNum);
    std::string line;
    while (std::getline(std::cin, line)) {
        boost::asio::post(pool, [line]() -> void {
            std::istringstream sstream(line);
            std::string transaction_id, product_id, category, price_str, quantity_str;
            std::getline(sstream, transaction_id, ',');
            std::getline(sstream, product_id, ',');
            std::getline(sstream, category, ',');
            std::getline(sstream, price_str, ',');
            std::getline(sstream, quantity_str, ',');

            double price = std::stod(price_str);
            int quantity = std::stoi(quantity_str);
            {
                std::lock_guard<std::mutex> lck(mtx);
                std::cout << category << "," << price * quantity << "," << quantity << "\n";
            }
        });
    }

    pool.join();
    return 0;
}