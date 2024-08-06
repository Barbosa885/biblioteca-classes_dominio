#ifndef CTRLSERPAGAMENTOS_H_INCLUDED
#define CTRLSERPAGAMENTOS_H_INCLUDED

#include "../../interfaces_h/InterfacesServicos.h"
#include "../../persistencia_h/PagamentosOAD.h"
#include <vector>

// Aluna: Laíssa Beatriz Soares da Silva - 22/2032982

/**
 * @class CtrlSerPagamentos
 * @brief Classe respons&aacute;vel pela implementa&ccedil;&atilde;o dos servi&ccedil;os de pagamento.
 *
 * Esta classe implementa a interface ISPagamentos e fornece m&eacute;todos para criar, ler, atualizar e excluir pagamentos.
 */
class CtrlSerPagamentos : public ISPagamentos {
public:
    /**
     * @brief Construtor da classe CtrlSerPagamentos.
     * @param oad Ponteiro para o objeto de acesso a dados de pagamento a ser utilizado.
     */
    CtrlSerPagamentos(PagamentoOAD* oad);
    /**
     * @brief Destrutor da classe CtrlSerPagamentos.
     */
    ~CtrlSerPagamentos();
    /**
     * @brief M&eacute;todo para criar um novo pagamento.
     * @param pagamento Refer&ecirc;ncia constante para o objeto Pagamento a ser criado.
     * @return true se a cria&ccedil;&atilde;o for bem-sucedida, false caso contr&aacute;rio.
     */
    bool criar(const Pagamento& pagamento) override;
    /**
     * @brief M&eacute;todo para ler os dados de um pagamento espec&iacute;fico.
     * @param pagamento Ponteiro para o objeto Pagamento onde os dados serão armazenados.
     * @return true se a leitura for bem-sucedida, false caso contr&aacute;rio.
     */
    bool ler(Pagamento* pagamento) override;
    std::vector<Pagamento> lerPagamentos(); // Declaração adicionada
    Pagamento lerPagamento(const CodigoPagamento& codigo); // Declaração adicionada
    /**
     * @brief M&eacute;todo para atualizar os dados de um pagamento existente.
     * @param pagamento Refer&ecirc;ncia constante para o objeto Pagamento a ser atualizado.
     * @return true se a atualiza&ccedil;&atilde;o for bem-sucedida, false caso contr&aacute;rio.
     */
    bool atualizar(const Pagamento& pagamento) override;
    /**
     * @brief M&eacute;todo para excluir um pagamento existente pelo c&oacute;digo.
     * @param codigoPagamento Refer&ecirc;ncia constante para o objeto CodigoPagamento do pagamento a ser exclu&iacute;do.
     * @return true se a exclus&atilde;o for bem-sucedida, false caso contr&aacute;rio.
     */
    bool excluir(const CodigoPagamento& codigoPagamento) override;
private:
    PagamentoOAD* oad;
};

#endif // CTRLSERPAGAMENTOS_H_INCLUDED

