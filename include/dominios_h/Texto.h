/**
 * @file Texto.h
 * @brief Definição da classe Texto.
 *
 * @brief Esta classe é usada para manipular e verificar uma string de texto.
 *
 * Autor: Gabriel Kenzo Nomura (211037176)
 */

class Texto{
    private:
        /** 
         * @brief Variável de texto.
         * 
         * Esta variável armazena a string de texto que a classe manipula.
         */
        string texto;
        
        /** 
         * @brief Método de verificação.
         * 
         * Este método privado é usado para verificar a string de texto de acordo com algum critério.
         * @param string A string a ser verificada.
         */
        void isValid(const string &texto);
    
    public:
        Texto();          /**< Construtor */
        virtual ~Texto(); /**< Destrutor */
        /** 
         * @brief Método GetTexto.
         * 
         * Este método é usado para obter o valor da variável de texto.
         * @return Retorna a string de texto.
         */
        const string &getTexto() const;
        
        /** 
         * @brief Método SetTexto.
         * 
         * Este método é usado para definir o valor da variável de texto.
         * @param string A nova string de texto.
         */
        void setTexto(const string &texto);
};

inline const string &Texto::getTexto() const
{
   return texto;
}

#endif // TEXTO_H
