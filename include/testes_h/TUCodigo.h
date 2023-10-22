/**
 * @file TUCodigo.h
 * @brief Definição da classe de teste TUCodigo.
 *
 * Esta classe de teste verifica a validade do domínio Codigo, seguindo critérios de formato definidos.
 *
 * Autor: Gustavo Barbosa (202037589)
 */

#ifndef TESTE_CODIGO_H
#define TESTE_CODIGO_H

#include "../dominios_h/Codigo.h"

using namespace std;

class TUCodigo
{
private:
    const static string CODIGOS_VALIDOS[];   /**< Definição de constante para evitar número mágico. */
    const static string CODIGOS_INVALIDOS[]; /**< Definição de constante para evitar número mágico. */
    Codigo *codigo;                          /**< Referência para o objeto a ser testado. */
    int estado;                              /**< Estado do teste. */
    void setUp();                            /**< Método para criar unidade em teste. */
    void tearDown();                         /**< Método para destruir unidade em teste. */
    void testarCenarioSucesso();             /**< Cenário de teste. */
    void testarCenarioFalha();               /**< Cenário de falha. */

public:
    TUCodigo();                              /**< Construtor padrão. */
    virtual ~TUCodigo();                     /**< Destrutor padrão. */
    const static int SUCESSO =  0;           /**< Definição de constante para reportar resultado de teste. */
    const static int FALHA = -1;             /**< Definição de constante para reportar resultado de teste. */
    void run();                              /**< Executa teste. */
};

#endif // TESTE_CODIGO_H
