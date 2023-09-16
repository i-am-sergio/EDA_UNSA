#include <iostream>
#include <cmath>
#include <vector>

double distanciaEuclidiana(const std::vector<double> &puntoA, const std::vector<double> &puntoB)
{
    double sumaCuadrados = 0;
    for (int i = 0; i < puntoA.size(); ++i)
    {
        double diferencia = puntoA[i] - puntoB[i];
        sumaCuadrados += diferencia * diferencia;
    }
    return std::sqrt(sumaCuadrados);
}

int main()
{
    std::vector<double> a = {0.712017, 0.6023};
    std::vector<double> b = {0.0781524, 0.841441};

    std::cout << a[0] << " , " << a[1] << "\n";
    std::cout << b[0] << " , " << b[1] << "\n";

    double distancia = distanciaEuclidiana(a, b);
    std::cout << "distancia: " << distancia << "\n";

    return 0;
}