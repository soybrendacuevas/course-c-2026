#include <iostream>
#include <type_traits> // Cabecera fundamental
#include <vector>

// Una estructura simple (POD - Plain Old Data)
struct SensorData {
    int id;
    float lectura;
};

// Una clase compleja
struct Usuario {
    std::string nombre; // Contiene punteros internos y memoria dinámica
};

template <typename T>
void guardarEnDisco(const T& dato) {
    std::cout << "--- Analizando tipo ---" << std::endl;

    // 1. Uso de is_trivially_copyable: ¿Se puede copiar con un simple memcpy?
    if constexpr (std::is_trivially_copyable_v<T>) {
        std::cout << "Optimización: Realizando volcado de memoria ultra rápido (Bitwise copy)." << std::endl;
    } 
    // 2. Uso de is_class: ¿Es una clase o estructura compleja?
    else if constexpr (std::is_class_v<T>) {
        std::cout << "Seguridad: El tipo es complejo. Ejecutando serializador de objetos." << std::endl;
    }
    
    // 3. Uso de is_floating_point: ¿Necesita redondeo?
    if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Nota: El tipo es decimal, aplicando formato de precisión." << std::endl;
    }
}

int main() {
    int nivelAgua = 10;
    SensorData sensor = {1, 25.5f};
    Usuario user1 = {"Alice"};

    guardarEnDisco(nivelAgua); // Salida: Bitwise copy
    guardarEnDisco(sensor);    // Salida: Bitwise copy (es una estructura simple)
    guardarEnDisco(user1);     // Salida: Serializador de objetos (string no es trivialmente copiable)

    return 0;
}
