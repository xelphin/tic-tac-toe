#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>

class InvalidSign : public std::exception {
public:
    const char* what() const noexcept override {
        return "Sign Number is Invalid";
    }
};

class OverflowPlayerAmount : public std::exception {
public:
    const char* what() const noexcept override {
        return "There are enough players, can't add more.";
    }
};

#endif // EXCEPTION_H