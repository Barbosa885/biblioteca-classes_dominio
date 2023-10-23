/**
 * @file TUQuadro.h
 *
 * @brief Definição da classe de teste TUQuadro.
 *
 * Autor: Hideki Tomiyama (190014351)
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
    string CODIGO_VALIDO = ""; ///< Código válido para teste
    string NOME_VALIDO = "Gustavo Barbosa"; ///< Nome válido para teste
    string DESCRICAO_VALIDA = "Descricao valida"; ///< Descrição válida para teste
    int LIMITE_VALIDO = 5; ///< Limite válido para teste
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
    TUQuadro();
    virtual ~TUQuadro();
    const static int SUCESSO = 0; ///< Indica que o teste foi bem-sucedido
    const static int FALHA = -1; ///< Indica que o teste falhou

    /**
     * @brief Executa o teste.
     */
    void run();
};

#endif // TESTES_QUADRO_H
