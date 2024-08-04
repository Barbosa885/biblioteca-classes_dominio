#include "../../include/persistencia_h/Conexaobanco.h"
#include "../../include/sqlite/sqlite3.h"
#include <stdexcept>
#include <iostream> // Para depuração
#include <vector>

Conexaobanco::Conexaobanco(const std::string& dbPath) : db(nullptr), dbPath(dbPath) {
    std::cout << "Tentando abrir conexão com o banco de dados em: " << dbPath << std::endl; // Depuração
    openConnection();
    inicializarBancoDeDados(); // Inicializa o banco de dados e cria tabelas, se necessário
}

Conexaobanco::~Conexaobanco() {
    closeConnection();
}

void Conexaobanco::openConnection() {
    int result = sqlite3_open(dbPath.c_str(), &db); // Captura o resultado da tentativa de abrir a conexão
    if (result != SQLITE_OK) {
        std::cerr << "Erro ao tentar abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl; // Detalhes do erro de conexão
        throw std::runtime_error("Não foi possível abrir a conexão com o banco de dados.");
    } else {
        std::cout << "Conexão com o banco de dados estabelecida com sucesso." << std::endl;
    }
}

sqlite3* Conexaobanco::getConnection() const {
    return db;
}

void Conexaobanco::closeConnection() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void Conexaobanco::inicializarBancoDeDados() {
    const char* sqlCriacaoTabela =
        "CREATE TABLE IF NOT EXISTS Titulo ("
        "codigo TEXT PRIMARY KEY NOT NULL, "
        "emissor TEXT NOT NULL, "
        "setor TEXT NOT NULL, "
        "emissao TEXT NOT NULL, "
        "vencimento TEXT NOT NULL, "
        "valor REAL NOT NULL);";

    try {
        executarSQL(sqlCriacaoTabela);
        std::cout << "Tabela Titulo criada ou já existe." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar tabela: " << e.what() << std::endl;
    }
}

void Conexaobanco::executarSQL(const std::string& sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string error = "Erro ao executar SQL: " + std::string(errMsg);
        sqlite3_free(errMsg);
        throw std::runtime_error(error);
    }
}

void Conexaobanco::executarSQL(const std::string& sql, std::vector<std::vector<std::string>>& resultados) {
    char* errMsg = nullptr;
    char** results = nullptr;
    int rows, cols;

    if (sqlite3_get_table(db, sql.c_str(), &results, &rows, &cols, &errMsg) != SQLITE_OK) {
        std::string error = "Erro ao executar SQL: " + std::string(errMsg);
        sqlite3_free(errMsg);
        throw std::runtime_error(error);
    }

    resultados.clear();
    for (int i = 1; i <= rows; ++i) {
        std::vector<std::string> row;
        for (int j = 0; j < cols; ++j) {
            row.push_back(results[i * cols + j]);
        }
        resultados.push_back(row);
    }

    sqlite3_free_table(results);
}
