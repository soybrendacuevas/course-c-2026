#include <iostream>
#include <cstring>
#include <algorithm>

// 1. CLASE BASE: Demuestra Encapsulamiento y Polimorfismo
class Recurso {
protected:
    std::string nombre;
public:
    Recurso(std::string n) : nombre(n) {}
    
    // Destructor virtual: Esencial para polimorfismo
    virtual void mostrarInfo() const {
        std::cout << "Recurso: " << nombre << std::endl;
    }
    virtual ~Recurso() { std::cout << "Destruyendo base\n"; }
};

// 2. CLASE DERIVADA: Demuestra Herencia y Regla de los 5
class Documento : public Recurso {
private:
    char* contenido; // Recurso manejado manualmente

public:
    // Constructor estándar
    Documento(std::string n, const char* texto) : Recurso(n) {
        contenido = new char[std::strlen(texto) + 1];
        std::strcpy(contenido, texto);
        std::cout << "[Constructor] Creado: " << nombre << "\n";
    }

    // --- REGLA DE LOS 5 ---

    // 1. Destructor
    ~Documento() {
        delete[] contenido;
        std::cout << "[Destructor] Liberando memoria de: " << nombre << "\n";
    }

    // 2. Constructor de Copia (Deep Copy)
    Documento(const Documento& otro) : Recurso(otro.nombre + "_copia") {
        contenido = new char[std::strlen(otro.contenido) + 1];
        std::strcpy(contenido, otro.contenido);
        std::cout << "[Copia] Copiando contenido de: " << otro.nombre << "\n";
    }

    // 3. Operador de Asignación de Copia
    Documento& operator=(const Documento& otro) {
        if (this != &otro) {
            delete[] contenido; // Liberar memoria actual
            nombre = otro.nombre + "_asignado";
            contenido = new char[std::strlen(otro.contenido) + 1];
            std::strcpy(contenido, otro.contenido);
        }
        return *this;
    }

    // 4. Constructor de Movimiento (Move Semantics)
    Documento(Documento&& otro) noexcept : Recurso(std::move(otro.nombre)) {
        contenido = otro.contenido; // Robar el recurso
        otro.contenido = nullptr;   // Dejar al original en estado nulo
        std::cout << "[Movimiento] Movido: " << nombre << "\n";
    }

    // 5. Operador de Asignación de Movimiento
    Documento& operator=(Documento&& otro) noexcept {
        if (this != &otro) {
            delete[] contenido;
            nombre = std::move(otro.nombre);
            contenido = otro.contenido;
            otro.contenido = nullptr;
        }
        return *this;
    }

    // Polimorfismo: Sobrescritura de método
    void mostrarInfo() const override {
        std::cout << "Documento: " << nombre << " | Contenido: " << (contenido ? contenido : "vacio") << std::endl;
    }
};

int main() {
    // Demostración de Polimorfismo
    Recurso* miArchivo = new Documento("Proyecto_Final", "Datos confidenciales");
    
    // El compilador decide en tiempo de ejecución llamar a Documento::mostrarInfo
    miArchivo->mostrarInfo(); 

    std::cout << "\n--- Probando Movimiento ---\n";
    Documento docA("Original", "Texto de prueba");
    Documento docB = std::move(docA); // Llama al Constructor de Movimiento

    delete miArchivo; // Llama al destructor de Documento gracias al destructor virtual
    return 0;
}
