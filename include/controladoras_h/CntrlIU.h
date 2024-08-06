#ifndef CNTRINTERFACEUSUARIO_H
#define CNTRINTERFACEUSUARIO_H

#include "../interfaces_h/apresentacao/IAAutenticacao.h"
#include "../interfaces_h/apresentacao/IAContas.h"
#include "../controladoras_h/CntrlAAutenticacao.h"
#include "../controladoras_h/CntrlAContas.h"

/**
 * @class CntrlIU
 * @brief Classe controladora para interação com o usuário.
 */
class CntrlIU {
private:
    IAAutenticacao* cntrlAAutenticacao; ///< Ponteiro para a controladora de autenticação.
    IAContas* cntrlIAConta; ///< Ponteiro para a controladora de contas.

public:
    /**
     * @brief Método para interagir com o usuário.
     */
    void interagirComUsuario();

    /**
     * @brief Configura a controladora de autenticação.
     * @param cntrlAAutenticacao Ponteiro para a instância da controladora de autenticação.
     */
    void setCntrlAAutenticacao(IAAutenticacao*);

    /**
     * @brief Configura a controladora de contas.
     * @param cntrlIAConta Ponteiro para a instância da controladora de contas.
     */
    void setCntrlIAConta(IAContas*);
};

#endif // CNTRINTERFACEUSUARIO_H
