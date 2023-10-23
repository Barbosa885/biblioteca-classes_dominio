/**
 * @file TUCartao.h
 *
 * @brief Definição da classe de teste TUCartao.
 *
 * Autor: Hideki Tomiyama (190014351)
 */

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
    string CODIGO_VALIDO = "AB12"; ///< Código válido para teste
    string NOME_VALIDO = "Gustavo barbosa"; ///< Nome válido para teste
    string DESCRICAO_VALIDA = "Isso e uma descricao"; ///< Descrição válida para teste
    string COLUNA_VALIDA = "CONCLUIDO"; ///< Coluna válida para teste
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
    TUCartao();
    virtual ~TUCartao();
    const static int SUCESSO = 0; ///< Indica que o teste foi bem-sucedido
    const static int FALHA = -1; ///< Indica que o teste falhou

    /**
     * @brief Executa o teste.
     */
    void run();
};

#endif // TESTES_CARTAO_H
