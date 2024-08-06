#ifndef CNTRLCONTAS_H
#define CNTRLCONTAS_H

#include "../interfaces_h/servico/ISContas.h"
#include "../dominios_h/Cpf.h"
#include "../entidades_h/Conta.h"
#include <iostream>

using namespace std;

class CntrlContas: public ISContas {
  public:
    bool criarConta(Conta);
    bool lerConta(Conta*);
    bool atualizarConta(Conta);
    bool excluirConta(Cpf);
};

#endif // CNTRLCONTAS_H
