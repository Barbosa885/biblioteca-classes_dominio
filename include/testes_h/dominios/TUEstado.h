#ifndef TUEstado_h
#define TUEstado_h

#include "../../dominios_h/Estado.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUEstado {
  private:
    const static string ESTADO_VALIDO;
    const static string ESTADO_INVALIDO;

    Estado *estado;
    int estadoAtual;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};


#endif // TUEstado_h
