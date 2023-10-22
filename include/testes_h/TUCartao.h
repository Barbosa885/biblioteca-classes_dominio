#ifndef TESTES_CARTAO_H
#define TESTES_CARTAO_H

#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Coluna.h"
#include "../entidades_h/Cartao.h"
#include <string>

using namespace std;

class TUCartao {
private:
    const static string CODIGO_VALIDO = "AB12"; 
    const static string NOME_VALIDO = "Texto valido"; 
    const static string DESCRICAO_VALIDA = "Descricao valida"; 
    const static string COLUNA_VALIDA = "SOLICITADO"; 
    Cartao *cartao;
    int estado;                             
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    void run();                              
};

#endif // TESTES_CARTAO_H
