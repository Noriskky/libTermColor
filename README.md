# **LTC** - libTermColor

🚀 LTC provides a convenient way to use Color in the Terminal using C/C++ & Rust

![C Badge](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=fff&style=for-the-badge) ![C++ Badge](https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=fff&style=for-the-badge) ![Rust Badge](https://img.shields.io/badge/Rust-000?logo=rust&logoColor=fff&style=for-the-badge)

## Installation 

### C/C++:

When you want to use it in your project it's really Easy just get the newest ``libtermcolor.h`` from the Releases Tab.
Then put this file in your ``src/`` folder and include the Libary with
```c++
#include "libtermcolor.h"
```
If you have it another location have to replace ``libtermcolor.h`` with your path to the ``.h`` file.

### Rust:

For just you have to add it the following in your ``Cargo.toml``:

```toml
[dependencies]
libtermcolor = "<version>"
```

or use the following command:

```bash
cargo add libtermcolor
```

## How to Use?

If you just want an example just can look at for C/C++ ``example/main.cpp`` and ``example.rs`` for Rust.

### Basic Usage

#### C/C++
```c++
colors::RED.regular
         ^     ^
         |     |
       Color TYPE
```

#### Rust

```rust
use libtermcolor; <-- Import the Libary

libtermcolor::colors::red().regular
                       ^       ^
                       |       |
                     Color   TYPE
```

**Color**: This specifies what color you want to use as List can be found at `` #Colors`` or by typing ``colors::`` and pressing ``CTRL + SPACE`` in your code. <br>
**Type**: The type says if it should be:
- **Bold**
- <span style="text-decoration:underline">Underline<span>
- Background (This is for changing Background Color)
- Reset (This will reset the effect of before specified Colors)
>
>[!NOTE]
>Reset can also be used with:

```c++
colors::RESET
```

### By String
You can also get The Colors by string with the following:

#### C/C++

```c++
colors::getColorCode("RED", "REGULAR")
                       ^        ^
                       |        |
                     Color    Type
```

#### Rust

```rust
libtermcolor::colors::get_color_code("RED", "REGULAR");
                                       ^        ^
                                       |        |
                                     Color     Type
```

>[!NOTE]
>The capitalization does not matter.

## Example

![Screenshot of Example](https://github.com/Noriskky/libTermColor/blob/main/screenshots/screenshots.jpeg?raw=true)

I have written a quick example that will output every Color + It's states:

#### C/C++

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

#### Rust

```rust
use libtermcolor;

fn main() {
    for (color_name, color_attributes) in libtermcolor::colors::COLOR_MAP.iter() {
        println!("{}{}{}:", color_attributes.background, color_name, libtermcolor::colors::reset());
        println!("  Regular:    {}{}{}{}", color_attributes.regular, color_name, color_attributes.reset, libtermcolor::colors::reset());
        println!("  Bold:       {}{}{}{}", color_attributes.bold, color_name, color_attributes.reset, libtermcolor::colors::reset());
        println!("  Underline:  {}{}{}{}", color_attributes.underline, color_name, color_attributes.reset, libtermcolor::colors::reset());
        println!("  Background: {}{}{}{}", color_attributes.background, color_name, color_attributes.reset, libtermcolor::colors::reset());
    }
}
```
This code can also be found at ``example/main.rs``.

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

#### C/C++
```shell
make clean
make build
./output/main
```

#### Rust
```shell
cd example
cargo build
```

### Compile Rust Libary

```shell
cargo build
```
