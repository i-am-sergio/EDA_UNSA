import matplotlib.pyplot as plt


def graficarhistograma(dimension):
    datos = []
    dimensiones = {
        2: [0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4],
        10: [0, 0.25, 0.50, 0.75, 1.00, 1.25, 1.50, 1.75, 2.0],
        50: [0, 1, 2, 3, 4, 5],
        100: [0, 1, 2, 3, 4, 5],
        1000: [0, 2, 4, 6, 8, 10, 12, 14]
    }

    valores_x = dimensiones.get(dimension, [])

    # Abrir el archivo y leer los datos línea por línea
    with open(f"distancias_dim{dimension}", 'r') as file:
        for line in file:
            dato = float(line.strip())
            datos.append(dato)

    # Crear el histograma
    plt.hist(datos, bins=8, color='#69FF7B',
             edgecolor='white', linewidth=3)
    plt.grid(True)
    plt.xlabel('Distancias')
    plt.ylabel('Frecuencia')
    plt.title(
        f'Histograma de las distancias entre puntos con dimension {dimension}')
    plt.xticks(valores_x)
    plt.savefig(f"dimension{dimension}.png")

    # Mostrar el histograma
    # plt.show()


with open('env', 'r') as archivo:
    contenido = archivo.read()
    dimension = int(contenido)

graficarhistograma(dimension)
