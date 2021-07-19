#include <boost/regex.hpp>
#include <iostream>

int main() {
    // output the available regex syntaxes
    std::cout
        << "Available regex syntaxes:\n"
        << "\t[0] Perl\n"
        << "\t[1] Perl case insensitive\n"
        << "\t[2] POSIX extended\n"
        << "\t[3] POSIX extended case insensitive\n"
        << "\t[4] POSIX basic\n"
        << "\t[5] POSIX basic case insensitive\n"
        << "Choose regex syntax: ";

    // correctly set up flags, according to the chosen syntax
    boost::regex::flag_type flag;
    switch (std::cin.get()) {
    case '0': flag = boost::regex::perl;
        break;

    case '1': flag = boost::regex::perl|boost::regex::icase;
        break;

    case '2': flag = boost::regex::extended;
        break;

    case '3': flag = boost::regex::extended|boost::regex::icase;
        break;

    case '4': flag = boost::regex::basic;
        break;

    case '5': flag = boost::regex::basic|boost::regex::icase;
        break;
    default:
        std::cout << "Incorrect number of regex syntax. Exiting... \n";
        return -1;
    }
    // Disabling exceptions
    flag |= boost::regex::no_except;

    //requesting regex patterns in a loop
    // Restoring std::cin
    std::cin.ignore();
    std::cin.clear();

    //Getting a String to match: in a loop
    std::string regex, str;
    do {
        std::cout << "Input regex: ";
        if (!std::getline(std::cin, regex) || regex.empty()) {
            return 0;
        }

        // Without `boost::regex::no_except`flag this
        // constructor may throw
        const boost::regex e(regex, flag);
        if (e.status()) {
            std::cout << "Incorrect regex pattern!\n";
            continue;
        }

        std::cout << "String to match: ";
        while (std::getline(std::cin, str) && !str.empty()) {
            bool matched = boost::regex_match(str, e);
            std::cout << (matched ? "MATCH\n" : "DOES NOT MATCH\n");
            std::cout << "String to match: ";
        } // end of `while (std::getline(std::cin, str))`

        std::cout << '\n';

        // Restoring std::cin
        std::cin.ignore();
        std::cin.clear();
    } while (1);

    return 0;
} // int main()

