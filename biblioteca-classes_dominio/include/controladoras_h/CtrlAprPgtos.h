#ifndef CONTROLADORASPAGAMENTOS_H_INCLUDED
#define CONTROLADORASPAGAMENTOS_H_INCLUDED

#include "../interfaces_h/InterfacesApresentacao.h"
#include "../interfaces_h/InterfacesServicos.h"

// Aluna: Laíssa Beatriz Soares da Silva - 22/2032982

class CtrlAprPagamentos : public IAPagamentos {
private:
    ISPagamentos* servicoPagamentos;
public:
    // Construtor
    CtrlAprPagamentos(ISPagamentos* servicoPagamentos) : servicoPagamentos(servicoPagamentos) {}
    // Implementação do método executar
    void executar(const Cpf& cpf) override;
};

#endif // CONTROLADORASPAGAMENTOS_H_INCLUDED

