#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

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
    int run();                              
};

#endif // TESTES_H_INCLUDED
