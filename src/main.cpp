#include <chrono>
#include <cstdlib>
#include <iostream>

#include "Matriz.hpp"

int main(int argc, char *argv[])
{
    if (argc != 5) {
        std::cout << "Informe as larguras e alturas das duas matrizes corretamente\n";
        return -1;
    }
    int larguraA = atoi(argv[1]);
    int alturaA = atoi(argv[2]);
    int larguraB = atoi(argv[3]);
    int alturaB = atoi(argv[4]);

    Matriz a = Matriz::gerarAleatoria(larguraA, alturaA);
    Matriz b = Matriz::gerarAleatoria(larguraB, alturaB);

    std::cout << "Matriz A:\n";
    a.printar();

    std::cout << "Matriz B:\n";
    b.printar();

    std::cout << "Matriz resultado:\n";
    Matriz res = a.multiplicar(b);
    res.printar();

    return 0;
}
