#ifndef INTERFACESAPRESENTACAO_H_INCLUDED
#define INTERFACESAPRESENTACAO_H_INCLUDED

#include "../dominios_h/Cpf.h"
#include "../entidades_h/Conta.h"
#include <stdexcept>

using namespace std;

// Aluna: Laíssa Beatriz Soares da Silva - 22/2032982
//-----------------------------------------------------------------------------------
// ---------------------------------------IAA----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class IAAutenticacao
 * @brief Define um m&eacute;todo para autenticar um usu&aacute;rio baseado em seu CPF.
 */
class IAAutenticacao {
public:
    virtual ~IAAutenticacao() = default;
    /**
     * @brief Autentica um usu&aacute;rio com base no CPF fornecido.
     * @param cpf Refer&ecirc;ncia constante para o objeto Cpf do usu&aacute;rio.
     * @return 'true' se a autentica&ccedil;&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool autenticar(const Cpf&) = 0;
};

//-----------------------------------------------------------------------------------
// ---------------------------------------IAC----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class IAConta
 * @brief Define m&eacute;todos para criar e executar opera&ccedil;&otilde;s relacionadas a contas utilizando um CPF.
 */
class IAConta {
public:
    virtual ~IAConta() = default;
    /**
     * @brief Cria uma nova conta.
     */
    virtual void criar() = 0;
    /**
     * @brief Executa opera&ccedil;&otilde;es relacionadas a conta usando o CPF fornecido.
     * @param cpf Refer&ecirc;ncia constante para o objeto Cpf do usu&aacute;rio.
     * @return Um inteiro indicando o resultado da operação (0 = conta existe, 1 = conta exclu&iacute;da).
     */
    virtual int executar(const Cpf&) = 0;
};
//-----------------------------------------------------------------------------------
// ---------------------------------------IAP----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class IAPagamentos
 * @brief Define um m&eacutetodo para executar opera&ccedil;&otilde;es de pagamento utilizando um CPF.
 */
class IAPagamentos {
public:
    virtual ~IAPagamentos() = default;
    /**
     * @brief Executa opera&ccedil;&otilde;es de pagamento usando o CPF fornecido.
     * @param cpf Refer&ecirc;ncia constante para o objeto Cpf do usu&aacute;rio.
     */
    virtual void executar(const Cpf&) = 0;
};
//-----------------------------------------------------------------------------------
// ---------------------------------------IAT----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class IATitulos
 * @brief Define um m&eacutetodo para executar opera&ccedil;&otilde;es relacionadas a t&iacutetulos utilizando um CPF.
 */
class IATitulos {
public:
    virtual ~IATitulos() = default;
    /**
     * @brief Executa opera&ccedil;&otilde;es relacionadas a t&iacute;tulos usando o CPF fornecido.
     * @param cpf Refer&ecirc;ncia constante para o objeto Cpf do usu&aacute;rio.
     */
    virtual void executar(const Cpf&) = 0;
};

#endif // INTERFACESAPRESENTACAO_H_INCLUDED
