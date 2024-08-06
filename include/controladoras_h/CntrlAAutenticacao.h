#ifndef CNTRLAAUTENTICACAO_H
#define CNTRLAAUTENTICACAO_H

#include <iostream>
#include "../interfaces_h/servico/ISAutenticacao.h"
#include "../interfaces_h/apresentacao/IAAutenticacao.h"

using namespace std;

class CntrlAAutenticacao:public IAAutenticacao {
private:
    ISAutenticacao* cntrlSAutenticacao;

public:
    bool autenticar(Cpf*) override;
    void setCntrlSAutenticacao(ISAutenticacao *);
};

void inline CntrlAAutenticacao::setCntrlSAutenticacao(ISAutenticacao* cntrl){
        this->cntrlSAutenticacao = cntrl;
}

#endif // CNTRLAAUTENTICACAO_H
