#include <boost/any.hpp>
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<boost::any> some_values;

    some_values.push_back(10);
    const char* c_str = "Hello there!";
    some_values.push_back(c_str);
    some_values.push_back(std::string("Wow!"));

    std::string& s = boost::any_cast<std::string&>(some_values.back());
    s += " That is great!\n";
    std::cout << s;
}

void example_func() {
    boost::any variable(std::string("Hello world!"));

    // Following method may throw a boost::bad_any_cast exception
    // if actual value in variable is not a std::string
    std::string s1 = boost::any_cast<std::string>(variable);

    // Never throws. If actual value in variable is not a std::string
    // will return an NULL pointer.
    std::string* s2 = boost::any_cast<std::string>(&variable);

    (void)s2; // Supressing warnings about unused variable
    (void)s1;
}
