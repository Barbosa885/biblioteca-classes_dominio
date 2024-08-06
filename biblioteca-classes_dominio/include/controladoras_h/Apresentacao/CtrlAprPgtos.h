#ifndef CONTROLADORASPAGAMENTOS_H_INCLUDED
#define CONTROLADORASPAGAMENTOS_H_INCLUDED

#include "../../interfaces_h/InterfacesApresentacao.h"
#include "../../interfaces_h/InterfacesServicos.h"

// Aluna: Laíssa Beatriz Soares da Silva - 22/2032982

/**
 * @class CtrlAprPagamentos
 * @brief Classe respons&aacute;vel pela interface de apresenta&ccedil;&atilde;o das opera&ccedil;&otilde;es de pagamento.
 *
 * Esta classe implementa a interface IAPagamentos e fornece m&eacute;todos para criar, ler, atualizar e excluir pagamentos.
 */
class CtrlAprPagamentos : public IAPagamentos {
private:
    ISPagamentos* servicoPagamentos;
public:
    /**
     * @brief Construtor da classe CtrlAprPagamentos.
     * @param servicoPagamentos Ponteiro para o servi&ccedil;o de pagamento a ser utilizado.
     */
    CtrlAprPagamentos(ISPagamentos* servicoPagamentos) : servicoPagamentos(servicoPagamentos) {}
    /**
     * @brief Executa o menu de opera&ccedil;&otilde;es de pagamento.
     * @param cpf Refer&ecirc;ncia constante para o objeto Cpf do usu&aacute;rio.
     */
    void executar(const Cpf& cpf) override;
    /**
     * @brief M&eacute;todo para criar um novo pagamento.
     */
    void criarPagamento();    // Declaração correta dos métodos
    /**
     * @brief M&eacute;todo para ler os pagamentos existentes.
     */
    void lerPagamentos();
    /**
     * @brief M&eacute;todo para atualizar um pagamento existente.
     */
    void atualizarPagamento();
    /**
     * @brief M&eacute;todo para excluir um pagamento existente.
     */
    void excluirPagamento();
};

#endif // CONTROLADORASPAGAMENTOS_H_INCLUDED
