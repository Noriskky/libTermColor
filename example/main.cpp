#include <iostream> // include the standard libary

#include "../libtermcolor.h" // include the libary

int main() {
    std::cout << colors::GREEN.background << "Hello this is background a Example" << colors::RESET << "\n";
    std::cout << colors::GREEN.bold << "Hello this is a bold Example" << colors::RESET << "\n";
    std::cout << colors::GREEN.regular << "Hello this is a regular Example" << colors::RESET << "\n";
    std::cout << colors::GREEN.underline << "Hello this is underlined a Example" << colors::RESET << "\n";

    std::cout << colors::hexToColor("#46b364").background << "Hello this is background a Example" << colors::RESET << "\n";
    std::cout << colors::hexToColor("#46b364").bold << "Hello this is a bold Example" << colors::RESET << "\n";
    std::cout << colors::hexToColor("#46b364").regular << "Hello this is a regular Example" << colors::RESET << "\n";
    std::cout << colors::hexToColor("#46b364").underline << "Hello this is underlined a Example" << colors::RESET << "\n";
    return 0;
}