class TUSENHA {
private:
    const string SENHA_VALIDA = "T3s!A"; /**< Constante que representa uma senha valida para o teste. */
    const string SENHA_INVALIDA = "Fa!hA"; /**< Constante que representa uma senha invalida para o teste. */
    SENHA *senha;
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
