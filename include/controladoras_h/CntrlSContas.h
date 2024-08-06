#ifndef CNTRLCONTAS_H
#define CNTRLCONTAS_H

#include "../interfaces_h/servico/ISContas.h"
#include "../dominios_h/Cpf.h"
#include "../entidades_h/Conta.h"
#include <iostream>

using namespace std;

/**
 * @class CntrlContas
 * @brief Classe controladora para o serviço de contas que implementa a interface ISContas.
 */
class CntrlSContas : public ISContas {
public:
    /**
     * @brief Método para criar uma conta.
     * @param conta Objeto Conta a ser criado.
     * @return true se a conta foi criada com sucesso, false caso contrário.
     */
    bool criarConta(Conta) ;

    /**
     * @brief Método para ler uma conta.
     * @param conta Ponteiro para o objeto Conta a ser lido.
     * @return true se a conta foi lida com sucesso, false caso contrário.
     */
    bool lerConta(Conta*) ;

    /**
     * @brief Método para atualizar uma conta.
     * @param conta Objeto Conta a ser atualizado.
     * @return true se a conta foi atualizada com sucesso, false caso contrário.
     */
    bool atualizarConta(Conta) ;

    /**
     * @brief Método para excluir uma conta.
     * @param cpf CPF do titular da conta a ser excluída.
     * @return true se a conta foi excluída com sucesso, false caso contrário.
     */
    bool excluirConta(Cpf) ;
};

#endif // CNTRLCONTAS_H
