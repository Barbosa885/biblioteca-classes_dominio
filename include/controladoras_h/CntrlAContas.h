#ifndef CNTRIACONTA_H
#define CNTRIACONTA_H

#include <iostream>
#include "../interfaces_h/apresentacao/IAContas.h"

using namespace std;

/**
 * @class CntrIAContas
 * @brief Classe controladora para gerenciamento de contas que implementa a interface IAContas.
 */
class CntrIAContas : public IAContas {
private:
    ISContas* cntrSContas; ///< Ponteiro para o serviço de contas.

public:
    /**
     * @brief Método para criar uma conta.
     */
    void criar();

    /**
     * @brief Método para executar operações com uma conta baseada no CPF.
     * @param cpf CPF do titular da conta.
     * @return true se a operação foi bem-sucedida, false caso contrário.
     */
    bool executar(Cpf);

    /**
     * @brief Configura o serviço de contas.
     * @param cntrlSContas Ponteiro para a instância do serviço de contas.
     */
    void setCntrSConta(ISContas*);
};

/**
 * @brief Configura o serviço de contas.
 * @param cntrlSContas Ponteiro para a instância do serviço de contas.
 */
inline void CntrIAContas::setCntrSConta(ISContas* cntrlSContas) {
    this->cntrSContas = cntrlSContas;
}

#endif // CNTRIACONTA_H
