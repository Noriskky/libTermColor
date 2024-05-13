# **LTC** - libTermColor

🚀 LTC provides a convenient way to use Color in the Terminal using C/C++

<img align="center" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
<img align="center" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++">

## Installation 

When you want to use it in your project it's really Easy just get the newest ``libtermcolor.h`` from the Releases Tab.
Then put this file in your ``src/`` folder and include the Libary with
```c++
#include "libtermcolor.h"
```
If you have it another location have to replace ``libtermcolor.h`` with your path to the ``.h`` file.

## How to Use?

If you just want an example just can look at ``example/main.cpp``.

### Basic Usage

```c++
colors::RED.regular
         ^     ^
         |     |
       Color TYPE
```

**Color**: This specifies what color you want to use as List can be found at `` #Colors`` or by typing ``colors::`` and pressing ``CTRL + SPACE`` in your code. <br>
**Type**: The type says if it should be:
- **Bold**
-  <span style="text-decoration:underline">Underline<span>
- Background (This is for changing Background Color)
- Reset (This will reset the effect of before specified Colors)

**NOTE**: Reset can also be used with:
```c++
colors::RESET
```

### By String
You can also get The Colors by string with the following:

```c++
colors::getColorCode("RED", "REGULAR")
                       ^        ^
                       |        |
                     Color    Type
```

**NOTE**: This capitalization does not matter.

## Example

![Screenshot of Example](https://github.com/Noriskky/libTermColor/blob/main/screenshots/screenshots.jpeg?raw=true)

I have written a quick example that will output every Color + It's states:
```c++
#include <iostream>
#include "libtermcolor.h"

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
```
This code can also be found at ``example/main.cpp``.

## Colors

```
- BLACK
- BRIGHT_BLACK
- RED
- BRIGHT_RED
- GREEN
- BRIGHT_GREEN
- YELLOW
- BRIGHT_YELLOW
- BLUE
- BRIGHT_BLUE
- MAGENTA
- BRIGHT_MAGENTA
- CYAN
- BRIGHT_CYAN
- WHITE
- BRIGHT_WHITE
```

## How to Contribute
You can use the example to test your Code.

### Compile Example
You can compile and test the example with the following command:
```shell
make clean
make build
./output/main
```
