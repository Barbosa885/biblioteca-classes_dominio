#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

// Incluir cabeçalhos.

#include "dominios.h"
#include "entidades.h"

using namespace std;

class TUCartao {
private:
    const static string CODIGO_VALIDO = "AB12"; 
    const static string NOME_VALIDO = "Arroz"; 
    const static string DESCRICAO_VALIDA = "Vamos testar codigos"; 
    const static string COLUNA_VALIDA = "CONCLUIDO"; 
    CARTAO *cartao;
    int estado;                             
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    int run();                              
};

#endif // TESTES_H_INCLUDED
