#ifndef DATA_H
#define DATA_H

#include <iostream>

// Aluno: Gustavo Barbosa de Almeida - 202037589

using namespace std;

/**
 * @brief Classe responsável pela representação de uma data.
 *
 * Esta classe encapsula a lógica relacionada ao gerenciamento de datas,
 * incluindo a validação da data e a manipulação de seus componentes.
 */
class Data {
  private:
    /**
     * @brief Armazena a data no formato DD-MM-AAAA.
     */
    string data;

    /**
     * @brief Valida a data fornecida.
     *
     * Este método verifica se a data está no formato correto e
     * se atende aos critérios de validação.
     * - A data deve ter 10 caracteres.
     * - A data deve estar no formato DD-MM-AAAA.
     * - DD: Dia (01-31).
     * - MM: Mês (01-12).
     * - AAAA: Ano (2000-2100).
     * - Considera ano bissexto.
     *
     * @param data A data a ser validada.
     */
    void validar(const string& data);

    /**
     * @brief Valida o formato da data.
     *
     * Este método verifica se a data está no formato correto (DD-MM-AAAA).
     *
     * @param data A data a ser validada.
     * @return Verdadeiro se a data estiver no formato correto, falso caso contrário.
     */
    bool validarFormato(const string& data);

  public :
    /**
     * @brief Construtor padrão da classe Data.
     */
    Data();

    /**
     * @brief Destrutor padrão da classe Data.
     */
    virtual ~Data();

    /**
     * @brief Define a data.
     *
     * Este método define a data para o objeto. Antes de definir,
     * a data é validada para garantir que atenda aos critérios de validação.
     *
     * @param data A nova data.
     */
    void setData(const string& data);

    /**
     * @brief Retorna a data.
     *
     * Este método retorna a data atual do objeto.
     *
     * @return A data atual.
     */
    string getData() const;

    friend std::istream& operator>>(std::istream& in, Data& data);

    friend std::ostream& operator<<(std::ostream& out, const Data& data);
};

inline string Data::getData() const {
  return data;
}

#endif // DATA_H
