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


class IndexOutOfBounds : public std::exception {
private:
    int m_line;
    std::string* m_msg;
public:
    explicit IndexOutOfBounds(const int lineOfError) : m_line(lineOfError) {
        m_msg = new std::string(std::string("The requested index is out of bounds.\nIndex: ") + std::to_string(m_line));
    }
    const char* what() const noexcept override {
        return (*m_msg).c_str();
    }
    ~IndexOutOfBounds() override {
        delete m_msg;
    }
};

class IllegalSlot : public std::exception {
public:
    const char* what() const noexcept override {
        return "The sign is illegal.";
    }
};

class UnavailableSlot : public std::exception {
public:
    const char* what() const noexcept override {
        return "The requested slot is already taken.";
    }
};

class InvalidVerticalArgument : public std::exception {
public:
    const char* what() const noexcept override {
        return "The vertical argument is invalid.";
    }
};

class InvalidHorizontalArgument : public std::exception {
public:
    const char* what() const noexcept override {
        return "The horizontal argument is invalid.";
    }
};

#endif // EXCEPTION_H