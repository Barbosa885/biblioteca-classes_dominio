#ifndef PAGAMENTOOAD_H
#define PAGAMENTOOAD_H

#include <vector>
#include <string>
#include "Conexaobanco.h"
#include "../entidades_h/Pagamento.h"

// Aluna: Laíssa Beatriz Soares da Silva - 22/2032982

/**
 * @class PagamentoOAD
 * @brief Classe respons&aacute;vel pelo acesso a dados dos pagamentos.
 *
 * Esta classe fornece m&eacute;todos para criar, ler, listar, atualizar e excluir pagamentos no banco de dados.
 */
class PagamentoOAD {
public:
    /**
     * @brief Construtor da classe PagamentoOAD.
     * @param dbPath Caminho para o arquivo do banco de dados.
     */
    PagamentoOAD(const std::string& dbPath);
    /**
     * @brief Destrutor da classe PagamentoOAD.
     */
    ~PagamentoOAD();

    /**
     * @brief M&eacute;todo para criar um novo pagamento no banco de dados.
     * @param pagamento Refer&ecirc;ncia constante para o objeto Pagamento a ser criado.
     */
    void criarPagamento(const Pagamento& pagamento);
    /**
     * @brief M&eacute;todo para ler os dados de um pagamento espec&iacute;fico pelo c&oacute;digo.
     * @param codigo String contendo o c&oacute;digo do pagamento a ser lido.
     * @return Objeto Pagamento correspondente ao c&oacute;digo fornecido.
     */
    Pagamento lerPagamento(const std::string& codigo);
    /**
     * @brief M&eacute;todo para listar todos os pagamentos existentes no banco de dados.
     * @return Vetor de objetos Pagamento.
     */
    std::vector<Pagamento> listarPagamentos();
    /**
     * @brief M&eacute;todo para atualizar os dados de um pagamento existente no banco de dados.
     * @param pagamento Refer&ecirc;ncia constante para o objeto Pagamento a ser atualizado.
     */
    void atualizarPagamento(const Pagamento& pagamento);
    /**
     * @brief M&eacute;todo para excluir um pagamento existente no banco de dados pelo c&oacute;digo.
     * @param codigo String contendo o c&oacute;digo do pagamento a ser exclu&iacute;do.
     */
    void excluirPagamento(const std::string& codigo);

private:
    Conexaobanco dbConnection;
};

#endif // PAGAMENTOOAD_H
