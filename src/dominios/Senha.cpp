void SENHA::isValid(string senha){
/** 
 * @brief
* verifica se a senha atende a alguns critérios específicos:
* - Deve conter exatamente 5 caracteres;
* - Deve conter pelo menos um caractere maiúsculo;
* - Deve conter pelo menos um caractere minúsculo;
* - Deve conter pelo menos um dígito;
* - Deve conter pelo menos um dos seguintes caracteres de pontuação: '.', ',', '!', '?', ';';
* - Não deve conter caracteres repetidos;
* @param senha a ser verificada.
* @throw exception_type: argumento invalido caso a senha não atenda um dos critérios estabelecidos.
*/
    if (senha.length() != 5) throw invalid_argument("Argumento invalido");
    /**< variaveis para verificação de casa critério. */
    int maiusculo = 0;
    int digito = 0;
    int minusculo = 0;
    int ponto = 0;
    int repetido = 1;

    string pontuacao = ".,!?;";
    for (char i : senha){
	/**
     * Verifica cada caractere na senha para determinar se ele é maiúsculo, 
     * minúsculo, um dígito, um caractere de pontuação 
     */
        if (int(i) >= (int)'A' && int(i) <= (int) 'Z')
        	maiusculo = 1;
        else if (int(i) >= (int)'a' && int(i) <= (int) 'z')
        	minusculo = 1;
        else if (int(i) >= (int)'0' && int(i) <= (int) '9')
        	digito = 1;
        else if (find(pontuacao.begin(), pontuacao.end(), i) != pontuacao.end())
        	ponto = 1;
        else
            throw invalid_argument("Argumento invalido");
    }
    
    for (int i = 0; i < 4; i++){
        for (int j = i+1; j < 5; j++){
	    /**
	     * @brief 
	    Verifica se há caracteres repetidos na senha. */
            if (senha[i] == senha[j]){
                repetido = 1;
				break;
            }
        }
		if (repetido == 0)
			break;
    }
    if (!(maiusculo & minusculo & digito & ponto & repetido))
        throw invalid_argument("Argumento invalido");
}
