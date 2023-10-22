/**
 * @file TUSenha.h
 *
 * @brief Definição da classe de teste TUSenha.
 *
 * Autor: Gabriel Kenzo Nomura (211037176)
 */

#include <iostream>
#include <string>
#include "../dominios_h/Senha.h"
#include "../Entidades.h"

class TUSenha {
private:
    const static string SENHAS_VALIDAS[]; /**< Constante que representa uma senha valida para o teste. */
    const static string SENHAS_INVALIDAS[]; /**< Constante que representa uma senha invalida para o teste. */
    Senha *senha;
    int estado; /**< Variável que armazena o estado do teste. */
    /**
    * Métodos privados
    */
    void setUp(); /**< Método para configurar o ambiente de teste. */
    void tearDown();  /**< Método para limpar o ambiente de teste. */
    void testarCenarioSucesso(); /**< Método para testar o cenário de sucesso. */
    void testarCenarioFalha(); /**< Método para testar o cenário de falha. */   

public:
    TUSenha(); /**< Construtor padrão. */
    virtual ~TUSenha(); /**< Destrutor padrão. */
    const static int SUCESSO =  0;  /**< Constante que representa o estado de sucesso do teste. */
    const static int FALHA = -1; /**< Constante que representa o estado de falha do teste. */
    /**< Metodo publico */
    void run(); /**< Método para executar os testes de unidade. */
};
