void TUSENHA::SetUp(){  /** Configura o ambiente de teste. */
    senha = new SENHA();
    estado = SUCESSO;
}

void TUSENHA::TearDown(){ /** Limpa o ambiente de teste, excluindo a instância SENHA. */
    delete senha;
}

void TUSENHA::TestarCenarioSucesso(){ /** Testa um cenário de sucesso em que a senha é definida como uma senha válida. */
    try{
        senha->SetSenha(SENHA_VALIDA);
        if (senha->GetSenha() != SENHA_VALIDA)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
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
