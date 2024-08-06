#ifndef CNTRINTERFACEUSUARIO_H
#define CNTRINTERFACEUSUARIO_H

#include "../interfaces_h/apresentacao/IAAutenticacao.h"
#include "../interfaces_h/apresentacao/IAContas.h"
#include "../controladoras_h/CntrlAAutenticacao.h"
#include "../controladoras_h/CntrlAContas.h"

class CntrlIU {
private:
    IAAutenticacao *cntrlAAutenticacao;
    IAContas *cntrlIAConta;

public:
    void interagirComUsuario();
    void setCntrlAAutenticacao(IAAutenticacao*);
    void setCntrlIAConta(IAContas*);
};

#endif // CNTRINTERFACEUSUARIO_H
