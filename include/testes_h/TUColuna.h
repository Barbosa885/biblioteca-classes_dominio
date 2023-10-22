/**
 * @file TUColuna.h
 *
 ** @brief Definição da classe de teste TUColuna.
 *
 * Autor: Hideki Tomiyama (190014351)
 */

class TUCOLUNA {
private:
    const string COLUNA_VALIDA = "CONCLUIDO"; /**< Constante que representa uma coluna valida para o teste. */
    const string COLUNA_INVALIDA = "Conclui"; /**< Constante que representa uma coluna invalida para o teste. */
    COLUNA *coluna;
    int estado; /**< Variável que armazena o estado do teste. */
    /**
    * Métodos privados
    */
    void SetUp(); /**< Método para configurar o ambiente de teste. */
    void TearDown();  /**< Método para limpar o ambiente de teste. */
    void TestarCenarioSucesso(); /**< Método para testar o cenário de sucesso. */
    void TestarCenarioFalha(); /**< Método para testar o cenário de falha. */    

public:
    const static int SUCESSO =  0;  /**< Constante que representa o estado de sucesso do teste. */
    const static int FALHA = -1; /**< Constante que representa o estado de falha do teste. */
    /**< Metodo publico */
    int Run(); /**< Método para executar os testes de unidade. */
};
