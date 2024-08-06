#ifndef ISAUTENTICACAO_H
#define ISAUTENTICACAO_H

#include <iostream>
#include "../../dominios_h/Cpf.h"
#include "../../dominios_h/Senha.h"

using namespace std;

/**
 * @Author Gustavo Barbosa de Almeida - 202037589
 * @class ISAutenticacao
 * @brief Interface para o serviço de autenticação.
 */
class ISAutenticacao {
  public:

    /**
     * @brief Método para autenticar um usuário.
     * @param cpf O CPF do usuário.
     * @param senha A senha do usuário.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    virtual bool autenticar(const Cpf&, const Senha&) = 0;

    /// Destrutor virtual.
    virtual ~ISAutenticacao() {}
};

#endif // ISAUTENTICACAO_H
