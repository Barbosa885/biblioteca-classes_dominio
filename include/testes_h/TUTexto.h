class TUTEXTO {
private:
    const string TEXTO_VALIDO = "Testei um caso.Ponto conta?"; /**< Constante que representa um texto valido para o teste. */
    const string TEXTO_INVALIDO = "Pontuacao invalida.teste";  /**< Constante que representa um texto invalido para o teste. */
    TEXTO *texto;
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
