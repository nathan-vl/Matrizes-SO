#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>

class Matriz
{
private:
    std::vector<std::vector<int>> valores;

public:
    static Matriz gerarAleatoria(std::size_t largura, std::size_t altura);
    static Matriz gerarEntradaPadrao(std::size_t largura, std::size_t altura);

    int getValor(std::size_t x, std::size_t y) const;
    std::size_t getAltura() const;
    std::size_t getLargura() const;

    void printar();

    Matriz multiplicar(Matriz m);
    static int multiplicarPosicao(const Matriz &a, const Matriz &b, std::size_t x, std::size_t y);
};

#endif
