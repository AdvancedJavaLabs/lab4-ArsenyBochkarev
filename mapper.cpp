#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    // TODO: parallel file reading
    while (std::getline(std::cin, line)) {
        std::istringstream sstream(line);
        std::string transaction_id, product_id, category, price_str, quantity_str;
        std::getline(sstream, transaction_id, ',');
        std::getline(sstream, product_id, ',');
        std::getline(sstream, category, ',');
        std::getline(sstream, price_str, ',');
        std::getline(sstream, quantity_str, ',');

        double price = std::stod(price_str);
        int quantity = std::stoi(quantity_str);

        std::cout << category << "," << price * quantity << "," << quantity << std::endl;
    }
    return 0;
}