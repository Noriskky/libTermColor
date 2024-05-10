#include <iostream>
#include "../libtermcolor.h"

int main() {
    for (const auto& pair : colors::color_map) {
        std::cout << pair.second.background << pair.first << colors::RESET << ":\n";
        std::cout << colors::BLACK.background << "  Regular:    " << colors::RESET << pair.second.regular << pair.first << pair.second.reset << std::endl;
        std::cout << colors::BLACK.background << "  Bold:       " << colors::RESET << pair.second.bold << pair.first << pair.second.reset << std::endl;
        std::cout << colors::BLACK.background << "  Underline:  " << colors::RESET << pair.second.underline << pair.first << pair.second.reset << std::endl;
        std::cout << colors::BLACK.background << "  Background: " << colors::RESET << pair.second.background << pair.first << pair.second.reset << std::endl;
    }
    return 0;
}