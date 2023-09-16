#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cmath>
#include <string>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

void generarPuntosAleatorios(int n, int dimension, Matrix<double> &puntos)
{
    std::ofstream datos;
    datos.open("datos_dim" + std::to_string(dimension));
    // Semilla aleatoria
    std::random_device rd;
    std::mt19937 gen(rd());

    // Rango de generacion (0 a 1)
    std::uniform_real_distribution<double> distribucion(0, 1);
    std::vector<double> auxPunto;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            double coordenada = distribucion(gen);
            datos << coordenada << ",";
            auxPunto.emplace_back(coordenada);
        }
        datos << "\n";
        puntos.emplace_back(auxPunto);
        auxPunto.clear();
    }
    datos.close();
}

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

void calcularDistancias(Matrix<double> &puntos) // 4950 distancias
{
    std::ofstream distancias;
    distancias.open("distancias_dim" + std::to_string(puntos[0].size()));
    for (int i = 0; i < puntos.size(); i++)
    {
        for (int j = i + 1; j < puntos.size(); j++)
        {
            double distancia = distanciaEuclidiana(puntos[i], puntos[j]);
            // std::cout << "Distancia entre Punto " << i + 1 << " y Punto " << j + 1 << ": " << distancia << std::endl;
            distancias << distancia << "\n";
        }
    }
    distancias.close();
}

void printMatrix(Matrix<double> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void casoDimension(int dimension)
{
    std::ofstream env("env");
    env << dimension;
    env.close();
    int nPuntos = 100;                                   // 10
    Matrix<double> puntos;                               // nPunto x dimension
    generarPuntosAleatorios(nPuntos, dimension, puntos); // Dimension 10
    calcularDistancias(puntos);                          // calcula las 4950 distancias
    // printMatrix(puntos);
    system("echo Generacion de Histograma...");
    system("python -u .\\histograma.py");
}

int main()
{
    // casoDimension(2);
    // casoDimension(10);
    // casoDimension(50);
    casoDimension(500);
    // casoDimension(1000);
    // casoDimension(2000);
    // casoDimension(5000);
    return 0;
}