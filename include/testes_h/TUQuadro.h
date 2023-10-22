#ifndef TESTES_QUADRO_H
#define TESTES_QUADRO_H

#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Limite.h"
#include "../entidades_h/Quadro.h"
#include <string>

using namespace std;

class TUQuadro {
private:
    const static string CODIGO_VALIDO = "AB12"; 
    const static string NOME_VALIDO = "Texto valido"; 
    const static string DESCRICAO_VALIDA = "Descricao valida"; 
    const static int LIMITE_VALIDO = 5; 
    Quadro *quadro;
    int estado;                             
    void setUp();                           
    void tearDown();                        
    void testarCenarioSucesso();            
public:
    const static int SUCESSO =  0;          
    const static int FALHA   = -1;          
    void run();                              
};

#endif // TESTES_QUADRO_H
