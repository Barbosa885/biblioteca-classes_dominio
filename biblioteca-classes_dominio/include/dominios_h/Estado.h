#ifndef ESTADO_H
#define ESTADO_H

#include <stdexcept>
#include <iostream>
#include <vector>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de um estado.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de estados,
 * incluindo a validação do estado e a manipulação de seus componentes.
 */
class Estado {
  private:
    /**
     * @brief Lista de estados válidos.
     *
     * Esta lista contém os estados que são considerados válidos.
     */
    const static vector<string> ESTADOS;

    /**
     * @brief Armazena o estado.
     */
    string estado;

    /**
     * @brief Valida o estado fornecido.
     *
     * Este método verifica se o estado está na lista de estados válidos.
     *
     * @param estado O estado a ser validado.
     */
    static void validar(const string& estado);

  public:
    /**
     * @brief Construtor padrão da classe Estado.
     */
    Estado();

    /**
     * @brief Destrutor padrão da classe Estado.
     */
    virtual ~Estado();

    /**
     * @brief Define o estado.
     *
     * Este método define o estado para o objeto. Antes de definir,
     * o estado é validado para garantir que esteja na lista de estados válidos.
     *
     * @param estado O novo estado.
     */
    void setEstado(const string& estado);

    /**
     * @brief Retorna o estado.
     *
     * Este método retorna o estado atual do objeto.
     *
     * @return O estado atual.
     */
    string getEstado() const;
    friend std::istream& operator>>(std::istream& in, Estado& estado);

    friend std::ostream& operator<<(std::ostream& out, const Estado& estado);
};

inline string Estado::getEstado() const {
  return estado;
}

#endif // ESTADO_H
