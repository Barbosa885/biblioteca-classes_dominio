#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

// Incluir cabeçalhos.

#include "dominios.h"
#include "entidades.h"

using namespace std;

class TUCartao {
private:
    const static string CODIGOS_VALIDOS[];   // Definição de constante para evitar número mágico.
    Projeto *projeto;                       // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

#endif // TESTES_H_INCLUDED
