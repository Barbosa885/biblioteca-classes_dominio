void TEXTO::isValid(string texto) {
/** 
* verifica se o texto atende a alguns critérios específicos:
* - O texto deve ter no mínimo 5 e no máximo 30 caracteres;
* - Cada caractere é letra(A - Z, a - z), dígito (0-9), sinal de pontuação(.,;?!);
* - Não há espaços em branco em sequência;
* - Não há sinais de pontuação em sequência;
* - Não há acentuação
* - Primeiro caractere é letra maiúscula;
* - Primeiro caractere após sinal de pontuação (exceto vírgula ou ponto-e-vírgula) é letra maiúscula;
* @param o texto verificado
* saida: "argumento invalido" caso o texto não atenda um dos critérios estabelecidos.
*/
    string pontuacao = ".,;!?";
    if (!isupper(texto[0]))
        throw invalid_argument("Argumento invalido");
    if (texto.length() < 5 || texto.length() > 30)
        throw invalid_argument("Argumento invalido");
    for (int i = 1; i < texto.length(); i++) {
        if (isalnum(texto[i]))
            continue;
        else if (find(pontuacao.begin(), pontuacao.end(), texto[i]) != pontuacao.end()) {
            if (i != texto.length() -1){
                if (find(pontuacao.begin(), pontuacao.end(), texto[i+1]) != pontuacao.end())
                    throw invalid_argument("Argumento invalido");
                if (texto[i] == ',' || texto[i] == ';')
                    continue;
                if (!isupper(texto[i+1]))
                    throw invalid_argument("Argumento invalido");
            }    
        }
        else if (texto[i] == ' ') {
            if (i != texto.length() -1){
                if (texto[i+1] == ' ')
                    throw invalid_argument("Argumento invalido");
                continue;
            }
        }
    }
}
