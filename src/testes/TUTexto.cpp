void TUTEXTO::SetUp(){  /** Configura o ambiente de teste. */
    texto = new TEXTO();
    estado = SUCESSO;
}

void TUTEXTO::TearDown(){ /** Limpa o ambiente de teste, excluindo a instância TEXTO. */
    delete texto;
}

void TUTEXTO::TestarCenarioSucesso(){ /** Testa um cenário de sucesso em que o texto é definido como um texto válido. */
    try{
        texto->SetTexto(TEXTO_VALIDO);
        if (texto->GetTexto() != TEXTO_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUTEXTO::TestarCenarioFalha(){ /** Testa um cenário de falha em que o texto é definido como um texto inválido. */
    try{
        texto->SetTexto(TEXTO_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (texto->GetTexto() == TEXTO_INVALIDO)
            estado = FALHA;
    }
}

int TUTEXTO::Run(){
    SetUp();
    TestarCenarioSucesso();
    TestarCenarioFalha();
    TearDown();
    return estado; /**< Retorna o estado final dos testes (SUCESSO ou FALHA). */
}
