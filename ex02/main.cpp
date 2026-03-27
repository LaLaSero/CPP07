#include "Array.hpp"
#include <exception>
#include <iostream>
#include <string>

int main() {
    try {
        std::cout << "== default constructor ==" << std::endl;
        Array<int> empty;
        std::cout << "empty.size() = " << empty.size() << std::endl;

        std::cout << "\n== sized constructor ==" << std::endl;
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            numbers[i] = static_cast<int>(i * 10);
        }
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        }

        std::cout << "\n== copy constructor deep copy ==" << std::endl;
        Array<int> copied(numbers);
        copied[0] = 999;
        std::cout << "copied[0]  = " << copied[0] << std::endl;
        std::cout << "numbers[0] = " << numbers[0] << std::endl;

        std::cout << "\n== assignment operator deep copy ==" << std::endl;
        Array<int> assigned;
        assigned = numbers;
        assigned[1] = 777;
        std::cout << "assigned[1] = " << assigned[1] << std::endl;
        std::cout << "numbers[1]  = " << numbers[1] << std::endl;

        std::cout << "\n== template with std::string ==" << std::endl;
        Array<std::string> words(3);
        words[0] = "hello";
        words[1] = "cpp";
        words[2] = "templates";
        for (unsigned int i = 0; i < words.size(); ++i) {
            std::cout << "words[" << i << "] = " << words[i] << std::endl;
        }

        std::cout << "\n== out of bounds exception ==" << std::endl;
        std::cout << numbers[100] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "caught std::exception: " << e.what() << std::endl;
        return 0;
    }
    return 0;
}
