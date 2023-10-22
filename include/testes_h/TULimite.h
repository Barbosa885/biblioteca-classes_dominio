/**
 * @file TULimite.h
 *
 * @brief Definição da classe de teste TULimite.
 *
 * Autor: Hideki Tomiyama (190014351)
 */

#ifndef TESTE_LIMITE_H
#define TESTE_LIMITE_H

#include <iostream>
#include "../dominios_h/Limite.h"

using namespace std;

class TULimite {
private:
    const static int LIMITES_VALIDOS[];   /**< Constante que representa um limite valido para o teste. */
    const static int LIMITES_INVALIDOS[]; /**< Constante que representa um limite invalido para o teste. */
    Limite *limite;
    int estado;                           /**< Variável que armazena o estado do teste. */

    void setUp();                         /**< Método para configurar o ambiente de teste. */
    void tearDown();                      /**< Método para limpar o ambiente de teste. */
    void testarCenarioSucesso();          /**< Método para testar o cenário de sucesso. */
    void testarCenarioFalha();            /**< Método para testar o cenário de falha. */

public:
    TULimite();                           /**< Construtor da classe. */
    virtual ~TULimite();                  /**< Destrutor da classe. */
    const static int SUCESSO =  0;        /**< Constante que representa o estado de sucesso do teste. */
    const static int FALHA = -1;          /**< Constante que representa o estado de falha do teste. */
    void run();                           /**< Método para executar os testes de unidade. */
};
