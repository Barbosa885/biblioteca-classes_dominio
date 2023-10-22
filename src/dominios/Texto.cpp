#include "../../include/dominios_h/Textos.h"
#include <string>
#include <iostream>
#include <regex>

Texto::Texto()
{
    //ctor
}

Texto::~Texto()
{
    //dtor
}

void Texto::isValid(const string &texto) {
/** 
 * @brief
* verifica se o texto atende a alguns critérios específicos:
* - O texto deve ter no mínimo 5 e no máximo 30 caracteres;
* - Cada caractere é letra(A - Z, a - z), dígito (0-9), sinal de pontuação(.,;?!);
* - Não há espaços em branco em sequência;
* - Não há sinais de pontuação em sequência;
* - Não há acentuação
* - Primeiro caractere é letra maiúscula;
* - Primeiro caractere após sinal de pontuação (exceto vírgula ou ponto-e-vírgula) é letra maiúscula;
* @param o texto verificado
* @throw exception_type: argumento invalido caso o texto não atenda um dos critérios estabelecidos.
*/

void verificaDominioTexto(const std::string& texto) {
    // Verifica se o texto tem entre 5 e 30 caracteres
    if (texto.length() < 5 || texto.length() > 30) {
        throw invalid_argument("Texto inválido")
    }

    // Verifica se o primeiro caractere é uma letra maiúscula
    if (!std::regex_search(texto, std::regex("^[A-Z]"))) {
            throw invalid_argument("Texto inválido")
    }

    // Verifica se não há espaços em branco em sequência
    if (std::regex_search(texto, std::regex("\\s{2,}"))) {
            throw invalid_argument("Texto inválido")
    }

    // Verifica se não há sinais de pontuação em sequência, exceto vírgula ou ponto-e-vírgula
    if (std::regex_search(texto, std::regex("[.,;?!]{2,}"))) {
            throw invalid_argument("Texto inválido")
    }

    // Verifica se não há acentuação (caracteres especiais)
    if (std::regex_search(texto, std::regex("[áéíóúÁÉÍÓÚàèìòùÀÈÌÒÙâêîôûÂÊÎÔÛãẽĩõũÃẼĨÕŨäëïöüÄËÏÖÜ]"))) {
            throw invalid_argument("Texto inválido")
    }

    // Verifica se o primeiro caractere após sinal de pontuação (exceto vírgula ou ponto-e-vírgula) é letra maiúscula
    if (std::regex_search(texto, std::regex("[.,;?!][a-z]"))) {
            throw invalid_argument("Texto inválido")
    }

    // Se todas as verificações passaram, o texto é válido
    cout << "Texto válido" << endl;
}
