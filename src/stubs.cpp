#include "../include/stubs.h"

//-----------------------------------------------------------------------------------------
// Implementações de métodos de classe stub.

bool StubLNAutenticacao::autenticar(const Matricula &matricula, const Senha &senha) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNAutenticacao::autenticar" << endl ;

    cout << "Matricula = " << matricula.getValor() << endl ;
    cout << "Senha     = " << senha.getValor()     << endl ;

    // Diferentes comportamentos dependendo do valor da matrícula.

    switch(matricula.getValor()){
        case TRIGGER_FALHA:
            return false;
        case TRIGGER_ERRO_SISTEMA:
            throw runtime_error("Erro de sistema");
    }

    return true;
}

#include "stubs.h"

// Adequar os valores.

const string StubServicoAutenticacao::INVALIDO = "12345";
const string StubServicoPessoal::INVALIDO = "12345";
const string StubServicoProdutosFinanceiros::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs.

bool StubServicoAutenticacao::autenticar(CPF cpf, Senha senha){
    if(cpf.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoPessoal::cadastrarUsuario(Usuario usuario){
    if(usuario.getCPF().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::cadastrarConta(Conta conta){
    if(conta.getNumero().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::consultarConta(Conta *conta){
    if(conta->getNumero().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoProdutosFinanceiros::cadastrarProdutoInvestimento(Produto produto){
    if(produto.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::descadastrarProdutoInvestimento(Codigo codigo){
    if(codigo.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::realizarAplicacao(Aplicacao aplicacao){
    if(aplicacao.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::recuperarAplicacao(Aplicacao *aplicacao){
    if(aplicacao->getCodigo().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por aplicacao.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

#include "stubs.h"

// Adequar os valores.

const string StubServicoAutenticacao::INVALIDO = "12345";
const string StubServicoPessoal::INVALIDO = "12345";
const string StubServicoProdutosFinanceiros::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos dos stubs.

bool StubServicoAutenticacao::autenticar(CPF cpf, Senha senha){
    if(cpf.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoPessoal::cadastrarUsuario(Usuario usuario){
    if(usuario.getCPF().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::cadastrarConta(Conta conta){
    if(conta.getNumero().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::consultarConta(Conta *conta){
    if(conta->getNumero().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoProdutosFinanceiros::cadastrarProdutoInvestimento(Produto produto){
    if(produto.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::descadastrarProdutoInvestimento(Codigo codigo){
    if(codigo.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::realizarAplicacao(Aplicacao aplicacao){
    if(aplicacao.getCodigo().getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProdutosFinanceiros::recuperarAplicacao(Aplicacao *aplicacao){
    if(aplicacao->getCodigo().getValor().compare(INVALIDO) == 0)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar código que atribui valores ao objeto identificado por aplicacao.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}
