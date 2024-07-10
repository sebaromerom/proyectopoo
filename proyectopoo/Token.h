#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
public:
    Token(const std::string& value);

    std::string getValue() const;

private:
    std::string value;
};

#endif // TOKEN_H
