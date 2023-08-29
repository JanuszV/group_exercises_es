use std::io;
use std::process::Command;
use chrono::Local;

fn main() {
    println!("Hi! Please choose an action:
    1. Display Rustc version.
    2. Display the current time and date.
    3. I want to see a rainbow colored \"Hello, World!\"!
    4. Calculate the area of a circle using a user-provided radius as input.
    5. Take user inputs for their first and last names, then reverse the order of the names, add a space between them, and display the result as a single output.
    0. Exit.");

    let mut action = String::new();

    io::stdin()
        .read_line(&mut action)
        .expect("Failed to read line");

    match action.trim() {
        "1" => rustc_version(),
        "2" => check_date(),
        "3" => hello_world(),
        "4" => circle_radius(),
        "5" => name_switch(),
        _ => println!("Exiting!"), 
    }

    fn rustc_version(){
        //std::env::var("RUSTC_VERSION") didn't work
        let version_raw = Command::new("rustc")
            .arg("--version")
            .output()
            .expect("Failed to execute command");

        
        if version_raw.status.success() {
            let version = String::from_utf8_lossy(&version_raw.stdout);
            println!("Rust compiler version:\n{}", version);
        } else {
            let error_message = String::from_utf8_lossy(&version_raw.stderr);
            println!("Error: {}", error_message);
        }
    }

    fn check_date(){
        let now = Local::now();
        println!("Current time: {}", now);
    }

    fn hello_world(){
        let reset = "\x1b[0m";
        let red = "\x1b[31m";
        let orange = "\x1b[38;5;202m";
        let yellow = "\x1b[33m";
        let green = "\x1b[32m";
        let blue = "\x1b[34m";
        let indigo = "\x1b[38;5;69m";
        let violet = "\x1b[38;5;129m";

        println!("{red}H{orange}e{yellow}l{green}l{blue}o{indigo}, {violet}W{red}o{orange}r{yellow}l{green}d{blue}!{reset}");
    }

    fn circle_radius(){
        let mut radius_raw = String::new();
        println!("Enter the radius of the circle: ");
        io::stdin()
            .read_line(&mut radius_raw)
            .expect("Failed to read line");

        let radius: f64 = match radius_raw.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid input. Please enter a valid integer.");
                return;
            }
        };
        
        let area = radius.powi(2) * std::f64::consts::PI;
        println!("The area of a circle with radius {} is: {}", radius, area);
    }

    fn name_switch(){
        let mut first_name = String::new();
        let mut last_name = String::new();

        println!("Enter your first name: ");
        io::stdin()
            .read_line(&mut first_name)
            .expect("Failed to read line");

        println!("Enter your last name: ");        
        io::stdin()
            .read_line(&mut last_name)
            .expect("Failed to read line");

        println!("Hello there, {} {}!", last_name.trim(), first_name.trim());
    }

}