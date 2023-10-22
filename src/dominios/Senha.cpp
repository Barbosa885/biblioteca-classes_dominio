#include <iostream>
#include <regex>
#include <string>

using namespace std;

Senha::Senha()
{
	//ctor
}

Senha::~Senha()
{
	//dtor	
}

void Senha::isValid(const string &senha){
/** 
 * @brief
* verifica se a senha atende a alguns critérios específicos:
* - Deve conter exatamente 5 caracteres;
* - Pelo menos um caractere é letra maiúscula;
* - Pelo menos um caractere é letra minúscula;
* - Pelo menos um caractere é dígito;
* - Pelo menos um caracter é sinal de pontuação;
* - Não há caractere duplicado;
* @param senha a ser verificada.
* @throw exception_type: argumento invalido caso a senha não atenda um dos critérios estabelecidos.
*/

    // Verifica se a senha tem pelo menos 5 caracteres
    if (senha.length() < 5) {
        throw invalid_argument("Senha inválida")
    }

    // Verifica se a senha contém pelo menos uma letra maiúscula
    if (!std::regex_search(senha, std::regex("[A-Z]"))) {
	throw invalid_argument("Senha inválida")
    }

    // Verifica se a senha contém pelo menos uma letra minúscula
    if (!std::regex_search(senha, std::regex("[a-z]"))) {
        throw invalid_argument("Senha inválida")
    }

    // Verifica se a senha contém pelo menos um dígito
    if (!std::regex_search(senha, std::regex("[0-9]"))) {
        throw invalid_argument("Senha inválida")
    }

    // Verifica se a senha contém pelo menos um caractere de pontuação
    if (!std::regex_search(senha, std::regex("[.,;?!]"))) {
        throw invalid_argument("Senha inválida")
    }

    // Verifica se não há caracteres duplicados
    for (size_t i = 0; i < senha.length(); ++i) {
        for (size_t j = i + 1; j < senha.length(); ++j) {
            if (senha[i] == senha[j]) {
                throw invalid_argument("Senha inválida")
            }
        }
    }
}

void Senha::setSenha(const string &senha){
	isValid(senha);
	this->senha = senha;
}
