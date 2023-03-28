#include <Matriz.hpp>
#include <cstdlib>
#include <iostream>

Matriz Matriz::gerarAleatoria(std::size_t largura, std::size_t altura)
{
    std::vector<std::vector<int>> valores = std::vector<std::vector<int>>(altura);

    for (std::size_t y = 0; y < altura; y++)
    {
        std::vector<int> linha = std::vector<int>(largura);
        for (std::size_t x = 0; x < largura; x++)
        {
            linha[x] = rand() % 100 + 1;
        }
        valores[y] = linha;
    }

    Matriz matriz = Matriz();
    matriz.valores = valores;

    return matriz;
}

Matriz Matriz::gerarEntradaPadrao(std::size_t largura, std::size_t altura)
{
    std::vector<std::vector<int>> valores = std::vector<std::vector<int>>(altura);

    for (std::size_t y = 0; y < altura; y++)
    {
        std::vector<int> linha = std::vector<int>(largura);
        for (std::size_t x = 0; x < largura; x++)
        {
            int valor = rand() % 100 + 1;
            std::cin >> linha[x];
            linha[x] = valor;
        }
        valores[y] = linha;
    }

    Matriz matriz = Matriz();
    matriz.valores = valores;

    return matriz;
}

int Matriz::getValor(std::size_t x, std::size_t y) const
{
    return valores[y][x];
}

std::size_t Matriz::getAltura() const
{
    return valores.size();
}

std::size_t Matriz::getLargura() const
{
    return valores[0].size();
}

void Matriz::printar()
{
    for (auto linha : valores)
    {
        for (auto valor : linha)
        {
            std::cout << valor << " ";
        }
        std::cout << "\n";
    }
}

int Matriz::multiplicarPosicao(const Matriz &a, const Matriz &b, std::size_t x, std::size_t y)
{
    int resultado = 0;
    for (std::size_t k = 0; k < b.getAltura(); k++)
    {
        resultado += a.getValor(k, y) * b.getValor(x, k);
    }
    return resultado;
}

Matriz Matriz::multiplicar(Matriz m)
{
    if (getLargura() != m.getAltura())
    {
        std::cout << "As matrizes são inválidas para serem multiplicadas\n";
        return Matriz();
    }

    std::vector<std::vector<int>> valores = std::vector<std::vector<int>>(getAltura());

    for (std::size_t y = 0; y < getAltura(); y++)
    {
        std::vector<int> linha = std::vector<int>(m.getLargura());
        for (std::size_t x = 0; x < m.getLargura(); x++)
        {
            linha[x] = multiplicarPosicao(*this, m, x, y);
        }
        valores[y] = linha;
    }

    Matriz matriz = Matriz();
    matriz.valores = valores;
    return matriz;
}
