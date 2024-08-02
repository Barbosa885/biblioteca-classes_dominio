#ifndef TU_TITULO_H
#define TU_TITULO_H

#include "../../entidades_h/Titulo.h"

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

class TUTitulo {
  private:
    const static string CODIGO_VALIDO;
    const static string EMISSOR_VALIDO;
    const static string SETOR_VALIDO;
    const static string EMISSAO_VALIDA;
    const static string VENCIMENTO_VALIDO;
    const static float VALOR_VALIDO;

    Titulo *titulo;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();

  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TU_TITULO_H
