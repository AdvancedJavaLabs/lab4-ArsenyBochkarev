#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream sstream(line);
        std::string category, revenue_str, quantity_str;

        std::getline(sstream, category, ',');
        std::getline(sstream, revenue_str, ',');
        std::getline(sstream, quantity_str, ',');

        std::cout << category << "," << revenue_str << "," << quantity_str << "\n";
    }
    return 0;
}