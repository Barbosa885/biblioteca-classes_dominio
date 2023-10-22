/**
 * @file TUTexto.h
 *
 * @brief Definição da classe de teste TUTexto.
 *
 * Autor: Gabriel Kenzo Nomura (211037176)
 */

#ifndef TESTE_TEXTO_H
#define TESTE_TEXTO_H

#include <iostream>
#include <string>
#include "../dominios_h/Texto.h"

using namespace std;

class TUTexto {
private:
    const static string TEXTOS_VALIDOS[]; /**< Constante que representa um texto valido para o teste. */
    const static string TEXTOS_INVALIDOS[];  /**< Constante que representa um texto invalido para o teste. */
    Texto *texto;
    int estado; /**< Variável que armazena o estado do teste. */
    /**
    * Métodos privados
    */
    void setUp(); /**< Método para configurar o ambiente de teste. */
    void tearDown();  /**< Método para limpar o ambiente de teste. */
    void testarCenarioSucesso(); /**< Método para testar o cenário de sucesso. */
    void testarCenarioFalha(); /**< Método para testar o cenário de falha. */

public:
    TUTexto();          /**< Construtor padrão. */
    virtual ~TUTexto(); /**< Destrutor padrão. */
    const static int SUCESSO =  0;  /**< Constante que representa o estado de sucesso do teste. */
    const static int FALHA = -1; /**< Constante que representa o estado de falha do teste. */
    /**< Metodo publico */
    void run(); /**< Método para executar os testes de unidade. */
};
