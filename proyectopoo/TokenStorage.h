#ifndef TOKENSTORAGE_H
#define TOKENSTORAGE_H

#include <vector>
#include <string>
#include "Token.h"

class TokenStorage {
public:
    TokenStorage(const std::string& path, const std::string& filename);

    std::vector<Token> loadTokens();
    void saveTokens(const std::vector<Token>& tokens);

private:
    std::string filepath;
};

#endif // TOKENSTORAGE_H
