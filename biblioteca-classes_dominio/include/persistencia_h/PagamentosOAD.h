#ifndef PAGAMENTOOAD_H
#define PAGAMENTOOAD_H

#include <vector>
#include <string>
#include "Conexaobanco.h"
#include "../entidades_h/Pagamento.h"

class PagamentoOAD {
public:
    PagamentoOAD(const std::string& dbPath);
    ~PagamentoOAD();

    void criarPagamento(const Pagamento& pagamento);
    Pagamento lerPagamento(const std::string& codigo);
    std::vector<Pagamento> listarPagamentos();
    void atualizarPagamento(const Pagamento& pagamento);
    void excluirPagamento(const std::string& codigo);

private:
    Conexaobanco dbConnection;
};

#endif // PAGAMENTOOAD_H
