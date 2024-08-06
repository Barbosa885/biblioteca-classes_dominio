#ifndef CNTRLAUTENTICACAO_H
#define CNTRLAUTENTICACAO_H

#include "../interfaces_h/servico/ISAutenticacao.h"
#include "../dominios_h/Cpf.h"
#include "../entidades_h/Conta.h"
#include <iostream>

using namespace std;

/**
 * @class CntrlSAutenticacao
 * @brief Classe controladora para o serviço de autenticação que implementa a interface ISAutenticacao.
 */
class CntrlSAutenticacao : public ISAutenticacao {
public:
    /**
     * @brief Método para autenticar um usuário.
     * @param cpf CPF do usuário.
     * @param senha Senha do usuário.
     * @return true se a autenticação foi bem-sucedida, false caso contrário.
     */
    bool autenticar(Cpf, Senha);
};

#endif // CNTRLAUTENTICACAO_H
