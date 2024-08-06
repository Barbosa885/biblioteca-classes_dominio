#ifndef IACONTA_H
#define IACONTA_H

#include <iostream>
#include "../../dominios_h/Cpf.h"

using namespace std;

// Pré declaração
class ISContas;

/**
 * @Author Gustavo Barbosa de Almeida - 202037589
 * @class IAContas
 * @brief Interface para a apresentação de contas.
 */
class IAContas {
public:

    /**
     * @brief Cria uma nova conta.
     */
    virtual void criar() = 0;

    /**
     * @brief Executa operações associadas a uma conta(crud).
     * @param cpf CPF da conta a ser executada.
     */
    virtual bool executar(Cpf) = 0;

    /**
     * @brief Define o controlador de contas.
     * @param cntrSConta Ponteiro para o controlador de contas.
     */
    virtual void setCntrSConta(ISContas*) = 0;

    virtual ~IAContas() {}
};

#endif // IACONTA_H
