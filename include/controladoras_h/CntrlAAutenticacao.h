#ifndef CNTRLAAUTENTICACAO_H
#define CNTRLAAUTENTICACAO_H

#include <iostream>
#include "../interfaces_h/servico/ISAutenticacao.h"
#include "../interfaces_h/apresentacao/IAAutenticacao.h"

using namespace std;

/**
 * @class CntrlAAutenticacao
 * @brief Classe controladora para autenticação que implementa a interface IAAutenticacao.
 */
class CntrlAAutenticacao : public IAAutenticacao {
private:
    ISAutenticacao* cntrlSAutenticacao; ///< Ponteiro para o serviço de autenticação.

public:
    /**
     * @brief Método para autenticar um usuário.
     * @param cpf Ponteiro para o CPF do usuário.
     * @return true se a autenticação foi bem-sucedida, false caso contrário.
     */
    bool autenticar(Cpf*);

    /**
     * @brief Configura o serviço de autenticação.
     * @param cntrl Ponteiro para a instância do serviço de autenticação.
     */
    void setCntrlSAutenticacao(ISAutenticacao*);
};

/**
 * @brief Configura o serviço de autenticação.
 * @param cntrl Ponteiro para a instância do serviço de autenticação.
 */
void inline CntrlAAutenticacao::setCntrlSAutenticacao(ISAutenticacao* cntrl) {
    this->cntrlSAutenticacao = cntrl;
}

#endif // CNTRLAAUTENTICACAO_H
