/**
 * @file TUEmail.h
 * @brief Definição da classe de teste TUEmail.
 *
 * Esta classe de teste verifica a validade do domínio Email, seguindo critérios de formato definidos.
 *
 * Autor: Gustavo Barbosa (202037589)
 */

#ifndef TESTE_EMAIL_H
#define TESTE_EMAIL_H

#include "../dominios_h/Email.h"

using namespace std;

class TUEmail
{
private:
    const static string EMAILS_VALIDOS[];   /**< Definição de constante para evitar número mágico. */
    const static string EMAILS_INVALIDOS[]; /**< Definição de constante para evitar número mágico. */
    int estado;                             /**< Estado do teste. */
    Email *email;                           /**< Referência para o objeto a ser testado. */
    void setUp();                           /**< Método para criar unidade em teste. */
    void tearDown();                        /**< Método para destruir unidade em teste. */
    void testarCenarioSucesso();            /**< Cenário de teste. */
    void testarCenarioFalha();              /**< Cenário de falha. */

public:
    TUEmail();                              /**< Construtor padrão. */
    virtual ~TUEmail();                     /**< Destrutor padrão. */
    const static int SUCESSO =  0;          /**< Definição de constante para reportar resultado de teste. */
    const static int FALHA = -1;            /**< Definição de constante para reportar resultado de teste. */
    void run();                             /**< Executa teste. */
};

#endif // TESTE_EMAIL_H
