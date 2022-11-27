#pragma once
#include <iostream>
#include <sstream>
#include <string>

class FigureException : public std::domain_error
{
public:
    FigureException(const std::string& what) : std::domain_error(what) { }
};