/**
 * @file TUColuna.h
 *
 ** @brief Definição da classe de teste TUColuna.
 *
 * Autor: Hideki Tomiyama (190014351)
 */

#include <iostream>
#include <string>
#include "../dominios_h/Coluna.h"
#include "../Entidades.h"


class TUColuna {
private:
    const static string COLUNAS_VALIDAS[]; /**< Constante que representa uma coluna valida para o teste. */
    const static string COLUNAS_INVALIDAS[]; /**< Constante que representa uma coluna invalida para o teste. */
    Coluna *coluna;
    int estado; /**< Variável que armazena o estado do teste. */
    /**
    * Métodos privados
    */
    void setUp(); /**< Método para configurar o ambiente de teste. */
    void tearDown();  /**< Método para limpar o ambiente de teste. */
    void testarCenarioSucesso(); /**< Método para testar o cenário de sucesso. */
    void testarCenarioFalha(); /**< Método para testar o cenário de falha. */

public:
    TUColuna(); /**< Construtor padrão. */
    virtual ~TUColuna(); /**< Destrutor padrão. */
    const static int SUCESSO =  0;  /**< Constante que representa o estado de sucesso do teste. */
    const static int FALHA = -1; /**< Constante que representa o estado de falha do teste. */
    /**< Metodo publico */
    void run(); /**< Método para executar os testes de unidade. */
};
