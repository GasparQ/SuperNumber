//
// Created by gaspar_q on 3/26/16.
//

#include <iostream>
#include "SuperNumber.hpp"

int main()
{
    SuperNumber i("3983409842092094908203948432983049823049834902289308422039483209482309482039483");
    SuperNumber j("3923984287289374093831029831093230948029840923840923840923848230948230984");
    SuperNumber k("3923984287289374093831029831093230948029840923840923840923848230948230984");
    SuperNumber l("3923984287289374093831029831093230948029840923840923840923848230948230985");
    SuperNumber m("3923984287289374093831029831093230948029840923840923840923848230948230983");

    std::cout << i + j << std::endl;
    system(std::string("echo \"" + i.getNumber() + "+" + j.getNumber() + "\" | bc").c_str());
    std::cout << std::boolalpha << "j < 3" << (j < 3) << std::endl;
    std::cout << std::boolalpha << "j > 3" << (j > 3) << std::endl;
    std::cout << std::boolalpha << "j > k" << (j > k) << std::endl;
    std::cout << std::boolalpha << "j < k" << (j < k) << std::endl;
    std::cout << std::boolalpha << "j == k" << (j == k) << std::endl;

    std::cout << std::boolalpha << "j > l " << (j > l) << std::endl;
    std::cout << std::boolalpha << "j < l " << (j < l) << std::endl;

    std::cout << std::boolalpha << "j > m " << (j > m) << std::endl;
    std::cout << std::boolalpha << "j < m " << (j < m) << std::endl;


//    i.toInt();
//    std::string test("");
//
//    std::cout << test << std::endl;
//    test.insert(0, 1, '3');
//    std::cout << test << std::endl;
    return 0;
}