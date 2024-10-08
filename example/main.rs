use libtermcolor::colors;

fn main() {
    for (color_name, color_attributes) in colors::COLOR_MAP.iter() {
        println!("{}{}{}:", color_attributes.background, color_name, colors::reset());
        println!("  Regular:    {}{}{}{}", color_attributes.regular, color_name, color_attributes.reset, colors::reset());
        println!("  Bold:       {}{}{}{}", color_attributes.bold, color_name, color_attributes.reset, colors::reset());
        println!("  Underline:  {}{}{}{}", color_attributes.underline, color_name, color_attributes.reset, colors::reset());
        println!("  Background: {}{}{}{}", color_attributes.background, color_name, color_attributes.reset, colors::reset());
    }
}
