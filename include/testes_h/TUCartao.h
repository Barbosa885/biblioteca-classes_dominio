#ifndef TESTES_CARTAO_H
#define TESTES_CARTAO_H

#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Coluna.h"
#include "../entidades_h/Cartao.h"
#include <string>

using namespace std;

/**
 * @class TUCartao
 * @brief Classe de teste para a classe Cartao.
 */
class TUCartao {
private:
    const static string CODIGO_VALIDO; ///< Código válido para teste
    const static string NOME_VALIDO; ///< Nome válido para teste
    const static string DESCRICAO_VALIDA; ///< Descrição válida para teste
    const static string COLUNA_VALIDA; ///< Coluna válida para teste
    Cartao *cartao; ///< Ponteiro para o objeto Cartao a ser testado
    int estado; ///< Estado do teste

    /**
     * @brief Configura o ambiente de teste.
     */
    void setUp();                           

    /**
     * @brief Limpa o ambiente de teste.
     */
    void tearDown();                        

    /**
     * @brief Testa um cenário de sucesso.
     */
    void testarCenarioSucesso();            
public:
    const static int SUCESSO; ///< Indica que o teste foi bem-sucedido
    const static int FALHA; ///< Indica que o teste falhou

    /**
     * @brief Executa o teste.
     */
    void run();                              
};

#endif // TESTES_CARTAO_H
