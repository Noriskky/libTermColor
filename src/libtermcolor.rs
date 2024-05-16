pub mod colors {
    use std::collections::HashMap;
    use std::borrow::Borrow;

    #[derive(Clone)]
    pub struct ColorAttributes {
        pub reset: &'static str,
        pub regular: &'static str,
        pub bold: &'static str,
        pub underline: &'static str,
        pub background: &'static str,
    }

    lazy_static::lazy_static! {
        pub static ref COLOR_MAP: HashMap<&'static str, ColorAttributes> = {
            [
                ("black", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;30m", bold: "\x1b[1;30m", underline: "\x1b[4;30m", background: "\x1b[40m" }),
                ("bright_black", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;90m", bold: "\x1b[1;90m", underline: "\x1b[4;90m", background: "\x1b[100m" }),
                ("red", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;31m", bold: "\x1b[1;31m", underline: "\x1b[4;31m", background: "\x1b[41m" }),
                ("bright_red", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;91m", bold: "\x1b[1;91m", underline: "\x1b[4;91m", background: "\x1b[101m" }),
                ("green", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;32m", bold: "\x1b[1;32m", underline: "\x1b[4;32m", background: "\x1b[42m" }),
                ("bright_green", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;92m", bold: "\x1b[1;92m", underline: "\x1b[4;92m", background: "\x1b[102m" }),
                ("yellow", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;33m", bold: "\x1b[1;33m", underline: "\x1b[4;33m", background: "\x1b[43m" }),
                ("bright_yellow", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;93m", bold: "\x1b[1;93m", underline: "\x1b[4;93m", background: "\x1b[103m" }),
                ("blue", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;34m", bold: "\x1b[1;34m", underline: "\x1b[4;34m", background: "\x1b[44m" }),
                ("bright_blue", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;94m", bold: "\x1b[1;94m", underline: "\x1b[4;94m", background: "\x1b[104m" }),
                ("magenta", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;35m", bold: "\x1b[1;35m", underline: "\x1b[4;35m", background: "\x1b[45m" }),
                ("bright_magenta", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;95m", bold: "\x1b[1;95m", underline: "\x1b[4;95m", background: "\x1b[105m" }),
                ("cyan", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;36m", bold: "\x1b[1;36m", underline: "\x1b[4;36m", background: "\x1b[46m" }),
                ("bright_cyan", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;96m", bold: "\x1b[1;96m", underline: "\x1b[4;96m", background: "\x1b[106m" }),
                ("white", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;37m", bold: "\x1b[1;37m", underline: "\x1b[4;37m", background: "\x1b[47m" }),
                ("bright_white", ColorAttributes { reset: "\x1b[0m", regular: "\x1b[0;97m", bold: "\x1b[1;97m", underline: "\x1b[4;97m", background: "\x1b[107m" }),
            ].iter().cloned().collect()
        };
    }

    pub fn black() -> &'static ColorAttributes { &COLOR_MAP["black"] }
    pub fn red() -> &'static ColorAttributes { &COLOR_MAP["red"] }
    pub fn green() -> &'static ColorAttributes { &COLOR_MAP["green"] }
    pub fn yellow() -> &'static ColorAttributes { &COLOR_MAP["yellow"] }
    pub fn blue() -> &'static ColorAttributes { &COLOR_MAP["blue"] }
    pub fn magenta() -> &'static ColorAttributes { &COLOR_MAP["magenta"] }
    pub fn cyan() -> &'static ColorAttributes { &COLOR_MAP["cyan"] }
    pub fn white() -> &'static ColorAttributes { &COLOR_MAP["white"] }

    pub fn bright_black() -> &'static ColorAttributes { &COLOR_MAP["bright_black"] }
    pub fn bright_red() -> &'static ColorAttributes { &COLOR_MAP["bright_red"] }
    pub fn bright_green() -> &'static ColorAttributes { &COLOR_MAP["bright_green"] }
    pub fn bright_yellow() -> &'static ColorAttributes { &COLOR_MAP["bright_yellow"] }
    pub fn bright_blue() -> &'static ColorAttributes { &COLOR_MAP["bright_blue"] }
    pub fn bright_magenta() -> &'static ColorAttributes { &COLOR_MAP["bright_magenta"] }
    pub fn bright_cyan() -> &'static ColorAttributes { &COLOR_MAP["bright_cyan"] }
    pub fn bright_white() -> &'static ColorAttributes { &COLOR_MAP["bright_white"] }

    pub fn reset() -> &'static str { "\x1b[0m" }

    pub fn get_color_code(color: &str, variation: &str) -> Option<&'static str> {
        let color_lower = color.to_lowercase();
        COLOR_MAP.get(&*color_lower).and_then(|color_attr| {
            match variation {
                "reset" => Some(color_attr.reset),
                "regular" => Some(color_attr.regular),
                "bold" => Some(color_attr.bold),
                "underline" => Some(color_attr.underline),
                "background" => Some(color_attr.background),
                _ => None,
            }
        })
    }
}
