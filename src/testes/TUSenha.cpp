#include <iostream>
#include "../../include/testes_h/TUSenha.h"
#include "../../include/dominios_h/Senha.h"

TUSenha::TUSenha()
{
    //ctor    
}

TUSenha::~TUSenha()
{
    //dtor
}

using namespace std;

const string TUSenha::SENHAS_VALIDAS[] = {
    "Abc1.",
    "Zy?x2"
};

const string TUSenha::SENHAS_INVALIDAS[] = {
    "abc.1",
    "ABC?2",
    "Abc!e",
    "Abcd3",
    "Abb,4"
};

void TUSenha::setUp(){  /** Configura o ambiente de teste. */
    senha = new SENHA();
    estado = SUCESSO;
}

void TUSenha::tearDown(){ /** Limpa o ambiente de teste, excluindo a instância SENHA. */
    delete senha;
}

void TUSenha::testarCenarioSucesso(){ /** Testa um cenário de sucesso em que a senha é definida como uma senha válida. */
    for (const string &senhaValida : SENHAS_VALIDAS){
        try{
            senha->setSenha(SENHA_VALIDA);
            if (senha->getSenha() != SENHA_VALIDA)
                estado = FALHA;
        }
        catch(invalid_argument &excecao){
            estado = FALHA;
        }
    }
}

void TUSENHA::TestarCenarioFalha(){ /** Testa um cenário de falha em que a senha é definida como uma senha inválida. */
    try{
        senha->SetSenha(SENHA_INVALIDA);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->GetSenha() == SENHA_INVALIDA)
            estado = FALHA;
    }
}

int TUSENHA::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado; /**< Retorna o estado final dos testes (SUCESSO ou FALHA). */
}
