/** @brief Configura o ambiente de teste. */
void TULIMITE::SetUp(){  
    limite = new LIMITE();
    estado = SUCESSO;
}

/** @brief Limpa o ambiente de teste, excluindo a instância LIMITE. */
void TULIMITE::TearDown(){ 
    delete limite;
}

/** @brief Testa um cenário de sucesso em que o limite é definido como um limite válido. */
void TULIMITE::TestarCenarioSucesso(){ 
    try{
        limite->SetLimite(LIMITE_VALIDO);
        if (limite->GetLimite() != LIMITE_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

/** @brief Testa um cenário de falha em que o limite é definido como um limite inválido. */
void TULIMITE::TestarCenarioFalha(){ 
    try{
        limite->SetLimite(LIMITE_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (limite->GetLimite() == LIMITE_INVALIDO)
            estado = FALHA;
    }
}

/**
 * @brief Executa os testes.
 * 
 * Esta função é responsável por executar os testes. 
 * Ela chama as funções SetUp, TestarCenarioSucesso, TestarCenarioFalha e TearDown na ordem.
 *
 * @return Retorna o estado do teste (SUCESSO ou FALHA).
 */
int TULIMITE::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado; 
}
