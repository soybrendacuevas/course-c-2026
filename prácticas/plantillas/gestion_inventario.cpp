#include <iostream>
#include <string>

using namespace std;

// 1. PLANTILLA DE FUNCIÓN (Genericidad)
// Compara dos elementos de cualquier tipo que soporte el operador '>'
template <typename T>
T obtenerMayor(T a, T b) {
    return (a > b) ? a : b;
}

// 2. ESPECIALIZACIÓN TOTAL
// Comportamiento especial para caracteres: 'V' (VIP) siempre es mayor
template <>
char obtenerMayor<char>(char a, char b) {
    if (a == 'V' || a == 'v') return a;
    return (a > b) ? a : b;
}

// 3. PLANTILLA DE CLASE
// Un contenedor genérico para almacenar elementos del inventario
template <typename T, int Capacidad>
class Inventario {
private:
    T items[Capacidad];
    int cantidadActual;

public:
    Inventario() : cantidadActual(0) {}

    void agregar(T item) {
        if (cantidadActual < Capacidad) {
            items[cantidadActual++] = item;
        } else {
            cout << "Inventario lleno!" << endl;
        }
    }

    void mostrarUltimo() {
        if (cantidadActual > 0) {
            cout << "Último producto: " << items[cantidadActual - 1] << endl;
        }
    }
};

int main() {
    // --- Prueba de Plantilla de Función ---
    int id1 = 105, id2 = 200;
    double precio1 = 45.50, precio2 = 12.99;

    cout << "ID mayor: " << obtenerMayor(id1, id2) << endl;
    cout << "Precio mayor: $" << obtenerMayor(precio1, precio2) << endl;

    // --- Prueba de Especialización ---
    char cat1 = 'A', cat2 = 'V'; 
    // Aunque 'V' es alfabéticamente mayor que 'A', aquí aplicamos lógica VIP
    cout << "Categoría prioritaria: " << obtenerMayor(cat1, cat2) << endl;

    // --- Prueba de Plantilla de Clase ---
    // Creamos un inventario de strings con capacidad para 5 elementos
    Inventario<string, 5> miTienda;
    miTienda.agregar("Laptop");
    miTienda.agregar("Teclado Mecánico");
    miTienda.mostrarUltimo();

    // Creamos un inventario de enteros (IDs) con capacidad para 100
    Inventario<int, 100> almacenIds;
    almacenIds.agregar(5001);
    almacenIds.mostrarUltimo();

    return 0;
}
