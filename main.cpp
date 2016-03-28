//
// Created by gaspar_q on 3/26/16.
//

#include <iostream>
#include "SuperNumber.hpp"

int main()
{
    SuperNumber i("3983409842092094908203948432983049823049834902289308422039483209482309482039483");
    SuperNumber j("3923984287289374093831029831093230948029840923840923840923848230948230984");
//    SuperNumber k("3923984287289374093831029831093230948029840923840923840923848230948230984");
//    SuperNumber l("3923984287289374093831029831093230948029840923840923840923848230948230985");
//    SuperNumber m("3923984287289374093831029831093230948029840923840923840923848230948230983");
//    SuperNumber test(3), test1(4);

//    std::cout << i + j << std::endl;
//    system(std::string("echo \"" + i.getNumber() + "+" + j.getNumber() + "\" | bc").c_str());
//
//    std::cout << std::boolalpha << "j < 3" << (j < 3) << std::endl;
//    std::cout << std::boolalpha << "j > 3" << (j > 3) << std::endl;
//    std::cout << std::boolalpha << "j > k" << (j > k) << std::endl;
//    std::cout << std::boolalpha << "j < k" << (j < k) << std::endl;
//    std::cout << std::boolalpha << "j == k" << (j == k) << std::endl;
//
//    std::cout << std::boolalpha << "j > l " << (j > l) << std::endl;
//    std::cout << std::boolalpha << "j < l " << (j < l) << std::endl;
//
//    std::cout << std::boolalpha << "j > m " << (j > m) << std::endl;
//    std::cout << std::boolalpha << "j < m " << (j < m) << std::endl;
//
//    std::cout << i - j << std::endl;
//    system(std::string("echo \"" + i.getNumber() + "-" + j.getNumber() + "\" | bc").c_str());
//
//    std::cout << j - i << std::endl;
//    system(std::string("echo \"" + j.getNumber() + "-" + i.getNumber() + "\" | bc").c_str());

    std::cout << "i * j : " << i * j << std::endl;
    system(std::string("echo \"" + i.getNumber() + "*" + j.getNumber() + "\" | bc").c_str());

    std::cout << "3 * 2: " << SuperNumber(3) * SuperNumber(2) << std::endl;
    system(std::string("echo \"3*2\" | bc").c_str());

    std::cout << "18 * 2: " << SuperNumber(18) * SuperNumber(2) << std::endl;
    system(std::string("echo \"18*2\" | bc").c_str());

    std::cout << "50 * 50: " << SuperNumber(50) * SuperNumber(50) << std::endl;
    system(std::string("echo \"50*50\" | bc").c_str());

    std::cout << "1996 * 20: " << SuperNumber(1996) * SuperNumber(20) << std::endl;
    system(std::string("echo \"1996*20\" | bc").c_str());

//    i.toInt();
//    std::string test("");
//
//    std::cout << test << std::endl;
//    test.insert(0, 1, '3');
//    std::cout << test << std::endl;
    return 0;
}