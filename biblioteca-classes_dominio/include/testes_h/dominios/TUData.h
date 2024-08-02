#ifndef TU_DATA_H
#define TU_DATA_H

#include "../../dominios_h/Data.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUData {
  private:
    static const string DATA_VALIDA;
    static const string DATA_INVALIDA;
    
    Data *data;
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

#endif // TU_DATA_H
