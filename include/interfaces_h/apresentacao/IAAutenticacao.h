#ifndef IAAUTENTICACAO_H
#define IAAUTENTICACAO_H

#include <iostream>
#include "../../dominios_h/Cpf.h"

using namespace std;

// Pré declaração
class ISAutenticacao;

/**
 * @Author Gustavo Barbosa de Almeida - 202037589
 * @class IAAutenticacao
 * @brief Interface para a apresentação de autenticação.
 */
class IAAutenticacao {
  public:
    /**
     * @brief Método responsável por autenticar um usuário.
     *
     * @param cpf O CPF do usuário.
     * @param senha A senha do usuário.
     */
    virtual bool autenticar(Cpf*) = 0;
    /**
     * @brief Método responsável por setar o controlador de apresentação de autenticação.
     *
     * @param cntrISAutenticacao O controlador de apresentação de autenticação.
     */
    virtual void setCntrISAutenticacao(ISAutenticacao*) = 0;
    /** 
     * @brief Método destrutor virtual.
     */
    virtual ~IAAutenticacao() {}
};

#endif // IAAUTENTICACAO_H
