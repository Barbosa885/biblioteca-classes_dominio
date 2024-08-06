#ifndef CNTRLAUTENTICACAO_H
#define CNTRLAUTENTICACAO_H

#include "../interfaces_h/servico/ISAutenticacao.h"
#include "../dominios_h/Cpf.h"
#include "../entidades_h/Conta.h"
#include <iostream>

using namespace std;

class CntrlSAutenticacao : public ISAutenticacao {
  public:
    bool autenticar(Cpf, Senha);
};


#endif // CNTRLAUTENTICACAO_H
