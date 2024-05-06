#include <map>
#include <string>
#include <algorithm> // For std::tolower
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace utils {
    inline std::vector<std::string> splitString(const std::string& input, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(input);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    inline const char * stringToChar(const std::string& str) {
        // Allocate memory on the heap for the char array
        char * cstr = new char[str.length() + 1];
        // Copy the string contents to the char array
        std::strcpy(cstr, str.c_str());
        // Return the pointer to the char array
        return cstr;
    }
}

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

    inline const char* getColorCodebyString(std::string color) {
        std::vector<std::string> colors = utils::splitString(color, '-');
        return getColorCode(colors[0], colors[1]);
    }

    inline const char * hexToColor(const std::string& hexCode) {
        // Check if the hex code has a valid format
        if (hexCode.size() != 7 || hexCode[0] != '#') {
            // Invalid format
            return "";
        }

        // Extract RGB components from the hex code
        std::stringstream ss;
        ss << std::hex << hexCode.substr(1); // Skip the '#'
        int r, g, b;
        ss >> r >> g >> b;

        // Convert RGB to nearest 8-color palette
        int paletteIndex = (r > 128) * 4 + (g > 128) * 2 + (b > 128);
        static const char* palette[] = {
            "0;30",  // Black
            "0;34",  // Blue
            "0;32",  // Green
            "0;36",  // Cyan
            "0;31",  // Red
            "0;35",  // Purple
            "0;33",  // Yellow
            "0;37"   // White
        };

        // Convert RGB to terminal color code
        std::ostringstream colorStream;
        colorStream << "\033[" << palette[paletteIndex] << "m";
        return utils::stringToChar(colorStream.str());
    }
}
