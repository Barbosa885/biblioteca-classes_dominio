#ifndef CNTRIACONTA_H
#define CNTRIACONTA_H

#include <iostream>
#include "../interfaces_h/apresentacao/IAContas.h"

using namespace std;

class CntrIAContas:public IAContas {
private:
    ISContas* cntrSContas;

public:
    void criar();
    bool executar(Cpf);
    void setCntrSConta(ISContas*);
};

inline void CntrIAContas::setCntrSConta(ISContas* cntrlSContas){
    this -> cntrSContas = cntrlSContas;
}

#endif // CNTRIACONTA_H
