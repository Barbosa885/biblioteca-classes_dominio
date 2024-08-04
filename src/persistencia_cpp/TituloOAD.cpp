#include "../../include/persistencia_h/TituloOAD.h"
#include <stdexcept>

// Construtor
TituloOAD::TituloOAD(const std::string& dbPath) : dbConnection(dbPath) {}

// Destrutor
TituloOAD::~TituloOAD() {
    // Destrutor, se necessário
}

// Criar um novo título
void TituloOAD::criarTitulo(const Titulo& titulo) {
    std::string sql = "INSERT INTO Titulo (codigo, emissor, setor, emissao, vencimento, valor) VALUES ('" +
                      titulo.getCodigoTitulo().getCodigoTitulo() + "', '" +
                      titulo.getEmissor().getNome() + "', '" +
                      titulo.getSetor().getSetor() + "', '" +
                      titulo.getEmissao().getData() + "', '" +
                      titulo.getVencimento().getData() + "', " +
                      std::to_string(titulo.getValor().getValor()) + ");";
    dbConnection.executarSQL(sql);
}

// Obter um título pelo código
Titulo TituloOAD::obterTitulo(const std::string& codigo) {
    std::string sql = "SELECT * FROM Titulo WHERE codigo = '" + codigo + "';";
    std::vector<std::vector<std::string>> resultados;
    dbConnection.executarSQL(sql, resultados);

    if (resultados.empty()) {
        throw std::runtime_error("Título não encontrado");
    }

    Titulo titulo;
    const std::vector<std::string>& row = resultados[0];
    titulo.setCodigoTitulo(CodigoTitulo(row[0]));
    titulo.setEmissor(Nome(row[1]));
    titulo.setSetor(Setor(row[2]));
    titulo.setEmissao(Data(row[3]));
    titulo.setVencimento(Data(row[4]));
    titulo.setValor(Dinheiro(std::stof(row[5])));

    return titulo;
}

// Listar todos os títulos
std::vector<Titulo> TituloOAD::listarTitulos() {
    std::vector<Titulo> titulos;
    std::string sql = "SELECT * FROM Titulo;";
    std::vector<std::vector<std::string>> resultados;
    dbConnection.executarSQL(sql, resultados);

    for (const auto& row : resultados) {
        Titulo titulo;
        titulo.setCodigoTitulo(CodigoTitulo(row[0]));
        titulo.setEmissor(Nome(row[1]));
        titulo.setSetor(Setor(row[2]));
        titulo.setEmissao(Data(row[3]));
        titulo.setVencimento(Data(row[4]));
        titulo.setValor(Dinheiro(std::stof(row[5])));
        titulos.push_back(titulo);
    }

    return titulos;
}

// Atualizar um título existente
void TituloOAD::atualizarTitulo(const Titulo& titulo) {
    std::string sql = "UPDATE Titulo SET emissor = '" + titulo.getEmissor().getNome() +
                      "', setor = '" + titulo.getSetor().getSetor() +
                      "', emissao = '" + titulo.getEmissao().getData() +
                      "', vencimento = '" + titulo.getVencimento().getData() +
                      "', valor = " + std::to_string(titulo.getValor().getValor()) +
                      " WHERE codigo = '" + titulo.getCodigoTitulo().getCodigoTitulo() + "';";
    dbConnection.executarSQL(sql);
}

// Excluir um título pelo código
void TituloOAD::excluirTitulo(const std::string& codigo) {
    std::string sql = "DELETE FROM Titulo WHERE codigo = '" + codigo + "';";
    dbConnection.executarSQL(sql);
}

