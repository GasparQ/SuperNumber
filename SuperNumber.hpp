//
// Created by gaspar_q on 3/25/16.
//

#ifndef C_SUPERNUMBER_HPP
#define C_SUPERNUMBER_HPP

#include <string>
#include <sstream>
#include <stdexcept>

class   SuperNumber
{
public:
    SuperNumber();
    SuperNumber(std::string const &expr);
    SuperNumber(int nb);
    SuperNumber(unsigned int nb);
    SuperNumber(long nb);
    SuperNumber(unsigned long nb);
    SuperNumber(SuperNumber const &);
    SuperNumber &operator=(SuperNumber const &);

public:
    std::string const   &getNumber(void) const;
    SuperNumber         toPositive(void) const;
    SuperNumber         toNegative(void) const;
    bool                isPositive(void) const;
    bool                isNegative(void) const;
    int                 toInt(void) const throw(std::logic_error);
    unsigned int        toUInt(void) const throw(std::logic_error);
    long                toLong(void) const throw(std::logic_error);
    unsigned long       toULong(void) const throw(std::logic_error);
    SuperNumber         &swapValues(SuperNumber &);
    static SuperNumber  evalExpr(std::string const &);
    static SuperNumber  factorial(SuperNumber const &);
    static SuperNumber  pow(SuperNumber const &, SuperNumber const &);

public:
    SuperNumber         operator+(SuperNumber const &) const;
    SuperNumber         operator-(SuperNumber const &) const;
    SuperNumber         operator%(SuperNumber const &) const;
    SuperNumber         operator/(SuperNumber const &) const;
    SuperNumber         operator*(SuperNumber const &) const;
    bool                operator==(SuperNumber const &) const;
    bool                operator!=(SuperNumber const &) const;
    bool                operator<(SuperNumber const &) const;
    bool                operator>(SuperNumber const &) const;
    bool                operator<=(SuperNumber const &) const;
    bool                operator>=(SuperNumber const &) const;
    SuperNumber         &operator++();
    SuperNumber         operator++(SuperNumber const &);
    SuperNumber         &operator--();
    SuperNumber         operator--(SuperNumber const &);
    SuperNumber         &operator+=(SuperNumber const &);
    SuperNumber         &operator-=(SuperNumber const &);
    SuperNumber         &operator/=(SuperNumber const &);
    SuperNumber         &operator%=(SuperNumber const &);
    SuperNumber         &operator*=(SuperNumber const &);

private:
    std::stringstream   number;
};

#endif //C_SUPERNUMBER_HPP
