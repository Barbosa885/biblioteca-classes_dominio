#ifndef CONEXAOBANCO_H
#define CONEXAOBANCO_H

#include "../sqlite/sqlite3.h"
#include <string>
#include <vector>

class Conexaobanco {
public:
    Conexaobanco(const std::string& dbPath);
    ~Conexaobanco();

    sqlite3* getConnection() const;
    void closeConnection();

    void executarSQL(const std::string& sql);
    void executarSQL(const std::string& sql, std::vector<std::vector<std::string>>& resultados);

private:
    sqlite3* db;
    std::string dbPath;

    void openConnection();
    void inicializarBancoDeDados(); // Declaração da nova função
};

#endif // CONEXAOBANCO_H
