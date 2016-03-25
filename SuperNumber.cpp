//
// Created by gaspar_q on 3/25/16.
//

#include <limits.h>

#include "SuperNumber.hpp"

SuperNumber::SuperNumber()
{
    number << 0;
}

SuperNumber::SuperNumber(std::string const &expr)
{
    *this = SuperNumber::evalExpr(expr);
}

SuperNumber::SuperNumber(int nb)
{
    number << nb;
}

SuperNumber::SuperNumber(unsigned int nb)
{
    number << nb;
}

SuperNumber::SuperNumber(long nb)
{
    number << nb;
}

SuperNumber::SuperNumber(unsigned long nb)
{
    number << nb;
}

SuperNumber::SuperNumber(const SuperNumber &number)
{
    *this = number;
}

SuperNumber &SuperNumber::operator=(const SuperNumber &number)
{
    this->number.clear();
    this->number << number.getNumber();
    return *this;
}

std::string const &SuperNumber::getNumber(void) const
{
    return number.str();
}

SuperNumber     SuperNumber::evalExpr(const std::string &string)
{
    SuperNumber superNumber;

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
    SuperNumber result;

    if (isNegative() && number.isNegative())
        return (toPositive() + number.toPositive()).toNegative();
    else if (isNegative() && number.isPositive())
        return number - toPositive();
    else if (isPositive() && number.isNegative())
        return *this - number.toPositive();
    //add inf positive positive implementation
    return result;
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
    return this->number.str() == number.number.str();
}

bool SuperNumber::operator!=(const SuperNumber &number) const
{
    return !(*this == number);
}

bool SuperNumber::operator<(const SuperNumber &number) const
{
    return false;
}

bool SuperNumber::operator>(const SuperNumber &number) const
{
    return false;
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

SuperNumber     SuperNumber::operator++(const SuperNumber &number)
{
    SuperNumber copy(*this);

    ++(*this);
    return copy;
}

SuperNumber &SuperNumber::operator--()
{
    *this -= 1;
    return *this;
}

SuperNumber     SuperNumber::operator--(const SuperNumber &number)
{
    SuperNumber copy(*this);

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
