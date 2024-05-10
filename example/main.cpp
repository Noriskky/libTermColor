#include <iostream>
#include "../libtermcolor.h"

int main() {
    std::cout << colors::GREEN.background << "Hello this is background a Example" << colors::RESET << "\n";
    std::cout << colors::GREEN.bold << "Hello this is a bold Example" << colors::RESET << "\n";
    std::cout << colors::GREEN.regular << "Hello this is a regular Example" << colors::RESET << "\n";
    std::cout << colors::GREEN.underline << "Hello this is underlined a Example" << colors::RESET << "\n";
    return 0;
}