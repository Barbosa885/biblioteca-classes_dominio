#ifndef INTERFACESSERVICOS_H_INCLUDED
#define INTERFACESSERVICOS_H_INCLUDED

#include "../dominios_h/Cpf.h"
#include "../dominios_h/Senha.h"
#include "../dominios_h/CodigoPagamento.h"
#include "../dominios_h/CodigoTitulo.h"
#include "../entidades_h/Conta.h"
#include "../entidades_h/Titulo.h"
#include "../entidades_h/Pagamento.h"
#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Declaração de interface da camada de serviços.
// Aluna: Laíssa Soares - 22/2032982
//-----------------------------------------------------------------------------------
// ---------------------------------------ISA----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class ISAutenticacao
 * @brief Define m&eacute;todo para autenticar um usu&aacute;rio baseado em seu CPF e Senha.
 */
class ISAutenticacao {
public:
    /**
     * @brief Autentica um usu&aacute;rio com base no CPF e Senha fornecidos.
     * @param cpf Refer&ecirc;ncia constante para o objeto Cpf do usu&aacute;rio.
     * @param senha Refer&ecirc;ncia constante para o objeto Senha do usuário.
     * @return 'true' se a autentica&ccedil;&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool autenticar(const Cpf&, const Senha&) = 0
};

//-----------------------------------------------------------------------------------
// ---------------------------------------ISC----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class ISConta
 * @brief Define m&eacute;todos para criar, ler, atualizar ou excluir uma Conta.
 */
class ISConta {
public:
    virtual ~ISConta() = default;
    /**
     * @brief Cria uma nova conta.
     * @param conta Refer&ecirc;ncia constante para o objeto Conta a ser criado.
     * @return 'true' se a criação for bem-sucedida, 'false' caso contrário.
     */
    virtual bool criar(const Conta&) = 0;
    /**
     * @brief Lê os dados de uma conta.
     * @param conta Ponteiro para o objeto Conta onde os dados serão armazenados.
     * @return 'true' se a leitura for bem-sucedida, 'false' caso contrário.
     */
    virtual bool ler(Conta*) = 0;
    /**
     * @brief Atualiza os dados de uma conta.
     * @param conta Referência constante para o objeto Conta a ser atualizado.
     * @return 'true' se a atualiza&ccedil;&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool atualizar(const Conta&) = 0;
    /**
     * @brief Exclui uma conta com base no CPF fornecido.
     * @param cpf Refer&ecirc;ncia constante para o objeto Cpf do usuário cuja conta ser&aacute; exclu&iacute;da.
     * @return 'true' se a exclus&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool excluir(const Cpf&) = 0;
};
//-----------------------------------------------------------------------------------
// ---------------------------------------ISP----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class ISPagamentos
 * @brief Define m&eacute;todos para criar, ler, atualizar ou excluir uma Pagamento.
 */
class ISPagamentos {
public:
    virtual ~ISPagamentos() = default;
    /**
     * @brief Cria um novo pagamento.
     * @param pagamento Refer&ecirc;ncia constante para o objeto Pagamento a ser criado.
     * @return 'true' se a cria&ccedil;&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool criar(const Pagamento&) = 0;
    /**
     * @brief L&ecirc; os dados de um pagamento.
     * @param pagamento Ponteiro para o objeto Pagamento onde os dados ser&atilde;oo armazenados.
     * @return 'true' se a leitura for bem-sucedida, 'false' caso cont&aacute;ário.
     */
    virtual bool ler(Pagamento*) = 0;
    /**
     * @brief Atualiza os dados de um pagamento.
     * @param pagamento Refer&ecirc;ncia constante para o objeto Pagamento a ser atualizado.
     * @return 'true' se a atualiza&ccedil;&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool atualizar(const Pagamento&) = 0;
    /**
     * @brief Exclui um pagamento com base no C&oacute;digo de Pagamento fornecido.
     * @param codigoPagamento Refer&ecirc;ncia constante para o objeto CodigoPagamento do pagamento a ser exclu&iacute;do.
     * @return 'true' se a exclus&atilde;oo for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool excluir(const CodigoPagamento&) = 0;
};
//-----------------------------------------------------------------------------------
// ---------------------------------------IST----------------------------------------
// ----------------------------------------------------------------------------------
/**
 * @class ISTitulos
 * @brief Define m&eacute;todos para criar, ler, atualizar ou excluir uma T&iacute;tulo.
 */
class ISTitulos {
public:
    virtual ~ISTitulos() = default;
    /**
     * @brief Cria um novo t&iacute;tulo.
     * @param titulo Refer&ecirc;ncia constante para o objeto Titulo a ser criado.
     * @return 'true' se a cria&ccedil;&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool criar(const Titulo&) = 0;
    /**
     * @brief L&ecirc; os dados de um t&iacute;tulo.
     * @param titulo Ponteiro para o objeto Titulo onde os dados ser&atilde;o armazenados.
     * @return 'true' se a leitura for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool ler(Titulo*) = 0;
    /**
     * @brief Atualiza os dados de um t&iacute;tulo.
     * @param titulo Refer&ecirc;ncia constante para o objeto Titulo a ser atualizado.
     * @return 'true' se a atualiza&ccedil;&atilde;o for bem-sucedida, 'false' caso contr&aacute;rio.
     */
    virtual bool atualizar(const Titulo&) = 0;
    /**
     * @brief Exclui um t&iacute;tulo com base no C&oacute;digo de T&iacute;tulo fornecido.
     * @param codigoTitulo Refer&ecirc;ncia constante para o objeto CodigoTitulo do t&iacute;tulo a ser exclu&iacute;do.
     * @return 'true' se a exclus&atilde;o for bem-sucedida, 'false' caso contr&iacute;rio.
     */
    virtual bool excluir(const CodigoTitulo&) = 0;
};

#endif // INTERFACESSERVICOS_H_INCLUDED

