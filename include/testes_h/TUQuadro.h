/**
 * @file TUQuadro.h
 *
 * @brief Definição da classe de teste TUQuadro.
 *
 * Autor: Gabriel Kenzo Nomura (211037176)
 */

#ifndef TESTES_QUADRO_H
#define TESTES_QUADRO_H

#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Limite.h"
#include "../entidades_h/Quadro.h"
#include <string>

using namespace std;

/**
 * @class TUQuadro
 * @brief Classe de teste para a classe Quadro.
 */
class TUQuadro {
private:
    const static string CODIGO_VALIDO; ///< Código válido para teste
    const static string NOME_VALIDO; ///< Nome válido para teste
    const static string DESCRICAO_VALIDA; ///< Descrição válida para teste
    const static int LIMITE_VALIDO; ///< Limite válido para teste
    Quadro *quadro; ///< Ponteiro para o objeto Quadro a ser testado
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

#endif // TESTES_QUADRO_H
