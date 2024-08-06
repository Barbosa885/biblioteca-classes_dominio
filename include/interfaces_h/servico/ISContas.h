#ifndef ISCONTAS_H
#define ISCONTAS_H

#include <iostream>
#include "../../dominios_h/Cpf.h"
#include "../../dominios_h/Senha.h"
#include "../../dominios_h/Nome.h"
#include "../../entidades_h/Conta.h"

using namespace std;

/**
 * @Author Gustavo Barbosa de Almeida - 202037589
 * @class ISContas
 * @brief Interface para o serviço de contas.
 */
class ISContas {
  public:

    /**
     * @brief Método responsável por criar uma conta.
     *
     * @param nome O nome do usuário.
     * @param cpf O CPF do usuário.
     * @param senha A senha da conta.
     */
    virtual bool criarConta(Conta) = 0;

    /**
     * @brief Método para ler uma conta.
     * @param cpf O CPF do titular da conta.
     */
    virtual bool lerConta(Conta*) = 0;

    /**
     * @brief Método para atualizar uma conta.
     * @param cpf O CPF do titular da conta.
     * @param nome O novo nome do titular da conta.
     */
    virtual bool atualizarConta(Conta) = 0;

    /**
     * @brief Método para deletar uma conta.
     * @param cpf O CPF do titular da conta.
     */
    virtual bool excluirConta(Conta) = 0;

    /// Destrutor virtual
    virtual ~ISContas() {}
};

#endif // ISCONTAS_H
