void TEXTO::verifica(string texto) {
/** 
* verifica se o texto atende a alguns critérios específicos:
* - A primeira letra deve ser maiúscula;
* - O texto deve ter no mínimo 5 e no máximo 30 caracteres;
* - Os caracteres permitidos são letras (maiúsculas e minúsculas), pontuações ('.', ',', ';', '!', '?') e espaços em branco;
* - Não deve conter caracteres com acentuação;
* - Não deve conter sequências de pontuação ou espaços em branco consecutivos;
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
