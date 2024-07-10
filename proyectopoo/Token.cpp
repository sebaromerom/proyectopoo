#include "Token.h"

Token::Token(const std::string& value)
    : value(value) {}

std::string Token::getValue() const {
    return value;
}
