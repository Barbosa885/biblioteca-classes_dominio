#ifndef TU_CODIGO_TITULO_H
#define TU_CODIGO_TITULO_H

#include "../../dominios_h/CodigoTitulo.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUCodigoTitulo {
  private:
    const static string CODIGO_VALIDO;
    const static string CODIGO_INVALIDO;

    CodigoTitulo *codigoTitulo;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};


#endif // TU_CODIGO_TITULO_H

