//
// Created by gaspar_q on 3/25/16.
//

#include <limits.h>

#include "SuperNumber.hpp"

SuperNumber::SuperNumber()
{
    number = "0";
}

SuperNumber::SuperNumber(std::string const &expr)
{
    *this = SuperNumber::evalExpr(expr);
}

SuperNumber::SuperNumber(int nb)
{
    std::stringstream   stringstream;

    stringstream << nb;
    number = stringstream.str();
}

SuperNumber::SuperNumber(unsigned int nb)
{
    std::stringstream   stringstream;

    stringstream << nb;
    number = stringstream.str();
}

SuperNumber::SuperNumber(long nb)
{
    std::stringstream   stringstream;

    stringstream << nb;
    number = stringstream.str();
}

SuperNumber::SuperNumber(unsigned long nb)
{
    std::stringstream   stringstream;

    stringstream << nb;
    number = stringstream.str();
}

SuperNumber::SuperNumber(const SuperNumber &number)
{
    *this = number;
}

SuperNumber &SuperNumber::operator=(const SuperNumber &number)
{
    this->number = number.getNumber();
    return *this;
}

std::string const &SuperNumber::getNumber(void) const
{
    return number;
}

SuperNumber     SuperNumber::evalExpr(const std::string &string)
{
    SuperNumber superNumber;

    superNumber.number = string;
    return superNumber;
}

SuperNumber     SuperNumber::factorial(const SuperNumber &number)
{
    SuperNumber facto = 1;

    for (SuperNumber i = 1; i <= number; ++i)
    {
        facto *= i;
    }
    return facto;
}

SuperNumber     SuperNumber::pow(const SuperNumber &number, const SuperNumber &power)
{
    SuperNumber powed = 1;

    for (SuperNumber i = 0; i < power; ++i)
    {
        powed *= number;
    }
    return powed;
}

SuperNumber     SuperNumber::toPositive() const
{
    std::string positiv;

    if (isPositive())
        return *this;
    positiv = getNumber().substr(1, getNumber().length() - 1);
    return SuperNumber(positiv);
}

SuperNumber     SuperNumber::toNegative(void) const
{
    std::string neg;

    if (isNegative())
        return *this;
    neg = "-" + getNumber();
    return SuperNumber(neg);
}

bool SuperNumber::isPositive() const
{
    return getNumber()[0] != '-';
}

bool SuperNumber::isNegative(void) const
{
    return getNumber()[0] == '-';
}

SuperNumber     &SuperNumber::swapValues(SuperNumber &number)
{
    SuperNumber copy(*this);

    *this = number;
    number = copy;
    return *this;
}

int SuperNumber::toInt(void) const throw(std::logic_error)
{
    if (*this > INT_MAX || *this < INT_MIN)
        throw std::logic_error(getNumber() + " does not fit into int");
    return stoi(getNumber());
}

unsigned int SuperNumber::toUInt(void) const throw(std::logic_error)
{
    if (*this > UINT_MAX)
        throw std::logic_error(getNumber() + " does not fit into unsigned int");
    if (*this < 0)
        throw std::logic_error(getNumber() + " is negative and can't be converted as unsigned");
    return static_cast<unsigned int>(stoul(getNumber()));
}

long SuperNumber::toLong(void) const throw(std::logic_error)
{
    if (*this > LONG_MAX || *this < LONG_MIN)
        throw std::logic_error(getNumber() + " does not fit into long");
    return stol(getNumber());
}

unsigned long SuperNumber::toULong(void) const throw(std::logic_error)
{
    if (*this > ULONG_MAX)
        throw std::logic_error(getNumber() + " doest not fit into long");
    if (*this < 0)
        throw std::logic_error(getNumber() + " is negative and can't be converted as unsigned");
    return stoul(getNumber());
}

SuperNumber     SuperNumber::operator+(const SuperNumber &number) const
{
    std::string nb1 = getNumber();
    std::string nb2 = number.getNumber();
    long        len1 = nb1.length() - 1;
    long        len2 = nb2.length() - 1;
    char        ret = 0;
    char        res = 0;
    std::string result = "";

    if (isNegative() && number.isNegative())
        return (toPositive() + number.toPositive()).toNegative();
    else if (isNegative() && number.isPositive())
        return number - toPositive();
    else if (isPositive() && number.isNegative())
        return *this - number.toPositive();
    while (len1 >= 0 || len2 >= 0)
    {
        if (len1 >= 0 && len2 >= 0)
        {
            res = (nb1[len1] - '0') + (nb2[len2] - '0') + ret;
            ret = static_cast<char>(res / 10);
            res = static_cast<char>((res % 10) + '0');
            result.insert(0, 1, res);
        }
        else if (len1 >= 0)
        {
            result.insert(0, 1, nb1[len1]);
        }
        else if (len2 >= 0)
        {
            result.insert(0, 1, nb2[len2]);
        }
        --len1;
        --len2;
    }
    return SuperNumber(result);
}

SuperNumber SuperNumber::operator-(const SuperNumber &number) const
{
    if (isNegative() && number.isPositive())
        return (toPositive() + number.toPositive()).toNegative();
    else if (isPositive() && number.isNegative())
        return (*this + number.toPositive());
    else if (isNegative() && number.isNegative())
        return (number.toPositive() - toPositive());
    //sub inf positive positive implementation
    return SuperNumber();
}

SuperNumber SuperNumber::operator%(const SuperNumber &number) const
{
    return SuperNumber();
}

SuperNumber SuperNumber::operator/(const SuperNumber &number) const
{
    return SuperNumber();
}

SuperNumber SuperNumber::operator*(const SuperNumber &number) const
{
    return SuperNumber();
}

bool SuperNumber::operator==(const SuperNumber &number) const
{
    return getNumber() == number.getNumber();
}

bool SuperNumber::operator!=(const SuperNumber &number) const
{
    return !(*this == number);
}

bool            SuperNumber::operator<(const SuperNumber &number) const
{
    std::string num1 = getNumber();
    std::string num2 = number.getNumber();
    size_t      len1 = num1.length();
    size_t      len2 = num2.length();

    if (len1 < len2)
        return true;
    else if (len1 > len2)
        return false;
    len2 = 0;
    for (size_t i = 0; i < len1; ++i)
    {
        if (num1[i] > num2[i])
            return (false);
        if (num1[i] == num2[i])
            ++len2;
    }
    return len2 < len1;
}

bool            SuperNumber::operator>(const SuperNumber &number) const
{
    std::string num1 = getNumber();
    std::string num2 = number.getNumber();
    size_t      len1 = num1.length();
    size_t      len2 = num2.length();

    if (len1 > len2)
        return true;
    else if (len1 < len2)
        return false;
    len2 = 0;
    for (size_t i = 0; i < len1; ++i)
    {
        if (num1[i] < num2[i])
            return (false);
        if (num1[i] == num2[i])
            ++len2;
    }
    return len2 < len1;
}

bool SuperNumber::operator<=(const SuperNumber &number) const
{
    return (*this < number || *this == number);
}

bool SuperNumber::operator>=(const SuperNumber &number) const
{
    return (*this > number || *this == number);
}

SuperNumber &SuperNumber::operator++()
{
    *this += 1;
    return *this;
}

SuperNumber     SuperNumber::operator++(int nb)
{
    SuperNumber copy(*this);

    if (nb != 0)
        (*this) += nb;
    else
        ++(*this);
    return copy;
}

SuperNumber &SuperNumber::operator--()
{
    *this -= 1;
    return *this;
}

SuperNumber     SuperNumber::operator--(int nb)
{
    SuperNumber copy(*this);

    if (nb != 0)
        (*this) -= nb;
    else
        --(*this);
    return copy;
}

SuperNumber &SuperNumber::operator+=(const SuperNumber &number)
{
    *this = *this + number;
    return *this;
}

SuperNumber &SuperNumber::operator-=(const SuperNumber &number)
{
    *this = *this - number;
    return *this;
}

SuperNumber &SuperNumber::operator/=(const SuperNumber &number)
{
    *this = *this / number;
    return *this;
}

SuperNumber &SuperNumber::operator%=(const SuperNumber &number)
{
    *this = *this % number;
    return *this;
}

SuperNumber &SuperNumber::operator*=(const SuperNumber &number)
{
    *this = *this * number;
    return *this;
}

std::ostream    &operator<<(std::ostream &output, SuperNumber const &number1)
{
    output << number1.getNumber() << std::endl;
    return output;
}