/**
 * @file Texto.h
 * @brief Definição da classe Texto.
 *
 * @brief Esta classe é usada para manipular e verificar uma string de texto.
 *
 * Autor: Gabriel Kenzo Nomura ()
 */

class TEXTO{
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
        void verifica(string);
    
    public:
        /** 
         * @brief Método GetTexto.
         * 
         * Este método é usado para obter o valor da variável de texto.
         * @return Retorna a string de texto.
         */
        string GetTexto();
        
        /** 
         * @brief Método SetTexto.
         * 
         * Este método é usado para definir o valor da variável de texto.
         * @param string A nova string de texto.
         */
        void SetTexto(string);
};
