#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------------
// Declaração de classe stub.

class StubLNAutenticacao:public ILNAutenticacao{
public:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declaração de método previsto na interface.

    bool autenticar(const Matricula&, const Senha&) ;
};

#endif // STUBS_H_INCLUDED

#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Classe stub do serviço autenticação.

#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Classe stub do serviço autenticação.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(CPF, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço pessoal.

class StubServicoPessoal:public IServicoPessoal {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço produtos financeiros.

class StubServicoProdutosFinanceiros:public IServicoProdutosFinanceiros {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarConta(Conta);
        bool consultarConta(Conta*);
        bool cadastrarProdutoInvestimento(Produto);
        bool descadastrarProdutoInvestimento(Codigo);
        bool realizarAplicacao(Aplicacao);
        bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

#endif // STUBS_H_INCLUDED


class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(CPF, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço pessoal.

class StubServicoPessoal:public IServicoPessoal {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------
// Classe stub do serviço produtos financeiros.

class StubServicoProdutosFinanceiros:public IServicoProdutosFinanceiros {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarConta(Conta);
        bool consultarConta(Conta*);
        bool cadastrarProdutoInvestimento(Produto);
        bool descadastrarProdutoInvestimento(Codigo);
        bool realizarAplicacao(Aplicacao);
        bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

#endif // STUBS_H_INCLUDED
