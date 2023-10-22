#include "../../include/testes_h/TUCodigo.h"
#include "../../include/dominios_h/Codigo.h"
#include <iostream>

using namespace std;

/**
 * @file TUColuna.cpp
 *
 * Autor: Hideki Tomiyama (190014351)
 *
 * @brief Configura o ambiente de teste.
 * 
 * Esta função é responsável por configurar o ambiente de teste. 
 * Ela inicializa a coluna e define o estado para SUCESSO.
 */

void TUCOLUNA::SetUp(){
    coluna = new COLUNA();
    estado = SUCESSO;
}

/**
 * @brief Limpa o ambiente de teste.
 * 
 * Esta função é responsável por limpar o ambiente de teste. 
 * Ela deleta a coluna.
 */
void TUCOLUNA::TearDown(){ 
    delete coluna;
}

/**
 * @brief Testa o cenário de sucesso.
 * 
 * Esta função é responsável por testar o cenário de sucesso. 
 * Ela tenta definir a coluna para um valor válido e verifica se a coluna foi definida corretamente.
 */
void TUCOLUNA::TestarCenarioSucesso(){ 
    try{
        coluna->SetColuna(COLUNA_VALIDA);
        if (coluna->GetColuna() != COLUNA_VALIDA)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

/**
 * @brief Testa o cenário de falha.
 * 
 * Esta função é responsável por testar o cenário de falha. 
 * Ela tenta definir a coluna para um valor inválido e verifica se uma exceção foi lançada.
 */
void TUCOLUNA::TestarCenarioFalha(){
    try{
        coluna->SetColuna(COLUNA_INVALIDA);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (coluna->GetColuna() == COLUNA_INVALIDA)
            estado = FALHA;
    }
}

/**
 * @brief Executa os testes.
 * 
 * Esta função é responsável por executar os testes. 
 * Ela chama as funções SetUp, TestarCenarioSucesso, TestarCenarioFalha e TearDown na ordem.
 *
 * @return Retorna o estado do teste.
 */
int TUCOLUNA::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado;
}
