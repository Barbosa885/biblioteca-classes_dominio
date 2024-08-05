#include "../../include/persistencia_h/PagamentosOAD.h"
#include <stdexcept>

PagamentoOAD::PagamentoOAD(const std::string& dbPath) : dbConnection(dbPath) {}

PagamentoOAD::~PagamentoOAD() {}

void PagamentoOAD::criarPagamento(const Pagamento& pagamento) {
    std::string sql = "INSERT INTO Pagamento (codigo_pgto, data, percentual, estado) VALUES ('" +
                      pagamento.getCodigoPagamento().getCodigo() + "', '" +
                      pagamento.getData().getData() + "', '" +
                      std::to_string(pagamento.getPercentual().getPercentual()) + "', '" +
                      pagamento.getEstado().getEstado() + "');";
    dbConnection.executarSQL(sql);
}

Pagamento PagamentoOAD::lerPagamento(const std::string& codigo) {
    std::string sql = "SELECT * FROM Pagamento WHERE codigo_pgto = '" + codigo + "';";
    std::vector<std::vector<std::string>> resultados;
    dbConnection.executarSQL(sql, resultados);

    if (resultados.empty()) {
        throw std::runtime_error("Pagamento não encontrado");
    }

    Pagamento pagamento;
    const std::vector<std::string>& row = resultados[0];
    pagamento.setCodigoPagamento(CodigoPagamento(row[0]));
    pagamento.setData(Data(row[1]));
    pagamento.setPercentual(Percentual(std::stof(row[2])));
    pagamento.setEstado(Estado(row[3]));

    return pagamento;
}

std::vector<Pagamento> PagamentoOAD::listarPagamentos() {
    std::vector<Pagamento> pagamentos;
    std::string sql = "SELECT * FROM Pagamento;";
    std::vector<std::vector<std::string>> resultados;
    dbConnection.executarSQL(sql, resultados);

    for (const auto& row : resultados) {
        Pagamento pagamento;
        pagamento.setCodigoPagamento(CodigoPagamento(row[0]));
        pagamento.setData(Data(row[1]));
        pagamento.setPercentual(Percentual(std::stof(row[2])));
        pagamento.setEstado(Estado(row[3]));
        pagamentos.push_back(pagamento);
    }

    return pagamentos;
}

void PagamentoOAD::atualizarPagamento(const Pagamento& pagamento) {
    std::string sql = "UPDATE Pagamento SET data = '" + pagamento.getData().getData() +
                      "', percentual = '" + std::to_string(pagamento.getPercentual().getPercentual()) +
                      "', estado = '" + pagamento.getEstado().getEstado() +
                      "' WHERE codigo_pgto = '" + pagamento.getCodigoPagamento().getCodigo() + "';";
    dbConnection.executarSQL(sql);
}

void PagamentoOAD::excluirPagamento(const std::string& codigo) {
    std::string sql = "DELETE FROM Pagamento WHERE codigo_pgto = '" + codigo + "';";
    dbConnection.executarSQL(sql);
}
