/**
 * @file TULimite.h
 *
 * Autor: Hideki Tomiyama (190014351)
 */

class TULIMITE {
private:
    const int LIMITE_VALIDO = 10;  /**< Constante que representa um limite valido para o teste. */
    const int LIMITE_INVALIDO = 30; /**< Constante que representa um limite invalido para o teste. */
    LIMITE *limite;
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
