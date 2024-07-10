#include "TokenStorage.h"
#include <fstream>

TokenStorage::TokenStorage(const std::string& path, const std::string& filename)
    : filepath(path + "/" + filename) {}

std::vector<Token> TokenStorage::loadTokens() {
    std::vector<Token> tokens;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        // Manejo de error si no se puede abrir el archivo
        return tokens; // Devuelve vector vacío si falla la carga
    }

    std::string tokenValue;
    while (std::getline(file, tokenValue)) {
        tokens.emplace_back(tokenValue);
    }

    file.close();
    return tokens;
}

void TokenStorage::saveTokens(const std::vector<Token>& tokens) {
    std::ofstream file(filepath);

    if (!file.is_open()) {
        // Manejo de error si no se puede abrir el archivo
        return;
    }

    for (const auto& token : tokens) {
        file << token.getValue() << "\n";
    }

    file.close();
}
