

// #include <iostream>
// #include <sstream>
// #include <string>

// int main(void)
// {
//     std::string str1 = "Abdallah 23 96";
//     std::istringstream iss(str1);        
    
    
//     std::string name ;
//     int age;
//     float score;
//     iss >> name >> age >>score;
//     // Check for parsing errors
//     if (iss.fail()) {
//         std::cout << "Failed to parse the input string." << std::endl;
//     } else {
//         // Print the parsed information
//         std::cout << "Name: " << name << std::endl;
//         std::cout << "Age: " << age << std::endl;
//         std::cout << "Score: " << score << std::endl;
//     }

//     return 0;
// }

#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string inputString = "Email : abdallahahmed17120@gmail.com , Mobile : 01018982284";

    // Define regular expressions for email and mobile number
    std::regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    std::regex mobileRegex(R"(\b\d{11}\b)");

    // Create an std::smatch object to hold the results of the regex match
    std::smatch match;

    // Match email
    if (std::regex_search(inputString, match, emailRegex))
    {
        std::string email = match.str();
        std::cout << "Email: " << email << std::endl;
    } else {
        std::cout << "Email not found." << std::endl;
    }

    // Match mobile number
    if (std::regex_search(inputString, match, mobileRegex)) 
    {
        std::string mobile = match.str();
        std::cout << "Mobile: " << mobile << std::endl;
    } else {
        std::cout << "Mobile number not found." << std::endl;
    }

    return 0;
}


/*
std::regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
\b: Represents a word boundary, ensuring that the pattern matches whole words.
[A-Za-z0-9._%+-]+: Matches one or more occurrences of characters that can be letters (both uppercase and lowercase), digits, or specific characters like period (.), underscore (_), percent (%), plus (+), or hyphen (-). This part represents the local part of an email address before the "@" symbol.
@: Matches the "@" symbol.
[A-Za-z0-9.-]+: Matches one or more occurrences of characters that can be letters (both uppercase and lowercase), digits, or specific characters like period (.) or hyphen (-). This represents the domain name part of an email address before the top-level domain.
\.: Matches a literal period (dot). It's escaped with a backslash () because dot is a special character in regex that matches any character. To match a literal dot, it needs to be escaped.
[A-Z|a-z]{2,}: Matches two or more occurrences of uppercase or lowercase letters. This is usually the top-level domain part of an email address, such as com, org, net, etc.
\b: Another word boundary, ensuring that the pattern matches a whole word.

*/

/*

std::regex mobileRegex(R"(\b\d{11}\b)");

\b: Represents a word boundary, ensuring that the pattern matches whole words.
\d{11}: Matches exactly 11 digits (0-9). The \d represents any digit, and {11} specifies that there should be exactly 11 occurrences of digits.
\b: Another word boundary, ensuring that the pattern matches a whole word.

*/