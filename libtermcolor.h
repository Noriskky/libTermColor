#include <map>
#include <string>
#include <algorithm> // For std::tolower
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <string>
#include <map>
#include <cmath>

namespace colors {
    struct ColorAttributes {
        const char * reset;
        const char * regular;
        const char * bold;
        const char * underline;
        const char * background;
    };

    const std::map<std::string, ColorAttributes> color_map = {
            {"black", {"\033[0m", "\033[0;30m", "\033[1;30m", "\033[4;30m", "\033[40m"}},
            {"red", {"\033[0m", "\033[0;31m", "\033[1;31m", "\033[4;31m", "\033[41m"}},
            {"green", {"\033[0m", "\033[0;32m", "\033[1;32m", "\033[4;32m", "\033[42m"}},
            {"yellow", {"\033[0m", "\033[0;33m", "\033[1;33m", "\033[4;33m", "\033[43m"}},
            {"blue", {"\033[0m", "\033[0;34m", "\033[1;34m", "\033[4;34m", "\033[44m"}},
            {"magenta", {"\033[0m", "\033[0;35m", "\033[1;35m", "\033[4;35m", "\033[45m"}},
            {"cyan", {"\033[0m", "\033[0;36m", "\033[1;36m", "\033[4;36m", "\033[46m"}},
            {"white", {"\033[0m", "\033[0;37m", "\033[1;37m", "\033[4;37m", "\033[47m"}}
    };

    const ColorAttributes& BLACK = color_map.at("black");
    const ColorAttributes& RED = color_map.at("red");
    const ColorAttributes& GREEN = color_map.at("green");
    const ColorAttributes& YELLOW = color_map.at("yellow");
    const ColorAttributes& BLUE = color_map.at("blue");
    const ColorAttributes& MAGENTA = color_map.at("magenta");
    const ColorAttributes& CYAN = color_map.at("cyan");
    const ColorAttributes& WHITE = color_map.at("white");

    const char* RESET = "\033[0m";

    inline const char* getColorCode(const std::string& color, const std::string& variation) {
        std::string colorLower = color;
        std::transform(colorLower.begin(), colorLower.end(), colorLower.begin(), ::tolower);

        auto it = color_map.find(colorLower);
        if (it != color_map.end()) {
            if (variation == "reset") return it->second.reset;
            else if (variation == "regular") return it->second.regular;
            else if (variation == "bold") return it->second.bold;
            else if (variation == "underline") return it->second.underline;
            else if (variation == "background") return it->second.background;
        }
        return nullptr;
    }
}