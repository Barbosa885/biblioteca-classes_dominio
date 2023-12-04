#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

// Incluir cabeçalhos.

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.

class ISAuth;
class ISConta;
class ISCartao;
class ISQuadro;

// Declaração de interface da camada de apresentação.

class IUAuth {
  public:
    virtual bool autenticar(Email *) = 0;                   // Método por meio do qual é solicitado serviço.
    virtual void setCntrLNAutenticacao(ISAuth *) = 0;       // Método para ligar (link) controladora na camada de serviço.
    virtual ~IUAuth(){}                                     // Método destrutor virtual.
};

class IUConta {
  public:
    virtual void cadastrar(Email) = 0;                      // Método por meio do qual é solicitado serviço.
    virtual void executar(Email) = 0;                       // Método por meio do qual é solicitado serviço.
    virtual void setCntrISConta(ISConta *) = 0;             // Método para ligar (link) controladora na camada de serviço.
    virtual ~IUConta(){}                                    // Método destrutor virtual.
};

class IUCartao {
  public:
    virtual void executar(Email) = 0;                       // Método por meio do qual é solicitado serviço.
    virtual void setCntrISCartao(ISCartao *) = 0;           // Método para ligar (link) controladora na camada de serviço.
    virtual ~IUCartao(){}                                   // Método destrutor virtual.
};

class IUQuadro {
  public:
    virtual void executar(Email) = 0;                       // Método por meio do qual é solicitado serviço.
    virtual void setCntrISQuadro(ISQuadro *) = 0;           // Método para ligar (link) controladora na camada de serviço.
    virtual ~IUQuadro(){}                                   // Método destrutor virtual.
};

// Declaração de interface da camada de serviço.

/* class ILNAutenticacao { */
/*   public: */
/*     virtual bool autenticar(const Matricula&, const Senha&) = 0;    // Método por meio do qual é solicitado serviço. */
/*     virtual ~ILNAutenticacao(){}                                    // Método destrutor virtual. */
/* }; */

#endif // INTERFACES_H_INCLUDED
