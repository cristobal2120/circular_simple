#include <iostream>
#include <vector> // Usamos vector para simular una lista de elementos

class Lista {
public:
    void agregar(int elemento) {
        elementos.push_back(elemento);
    }

    void imprimir() {
        for (const auto& elemento : elementos) {
            std::cout << elemento << " ";
             if (elementos.empty()) {
        std::cout << "La lista está vacía." << std::endl;
    } else {
        std::cout << "Cabeza: " << elementos.front() << std::endl;
        std::cout << "Elementos: ";
        for (const auto& elemento : elementos) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
        std::cout << "Cola: " << elementos.back() << std::endl;
    }
        }
        std::cout << std::endl;
    }

    bool buscar(int elemento) {
        for (const auto& e : elementos) {
            if (e == elemento) {
                return true;
            }
        }
        return false;
    }

    bool eliminar(int elemento) {
        for (auto it = elementos.begin(); it != elementos.end(); ++it) {
            if (*it == elemento) {
                elementos.erase(it);
                return true;
            }
        }
        return false;
    }

    bool actualizar(int valorAActualizar, int nuevoValor) {
        for (auto& elemento : elementos) {
            if (elemento == valorAActualizar) {
                elemento = nuevoValor;
                return true;
            }
        }
        return false;
    }

private:
    std::vector<int> elementos;
};

int main() {
    char opcion;
    Lista lista;

    do {
        std::cout << "Menú:" << std::endl;
        std::cout << "1. Insertar elemento" << std::endl;
        std::cout << "2. Mostrar elementos" << std::endl;
        std::cout << "3. Buscar elemento" << std::endl;
        std::cout << "4. Eliminar elemento" << std::endl;
        std::cout << "5. Actualizar elemento" << std::endl;
        std::cout << "6. Otra opción" << std::endl; // Nueva opción
        std::cout << "7. Salir" << std::endl;
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1':
                int nuevoElemento;
                std::cout << "Ingrese el nuevo elemento: ";
                std::cin >> nuevoElemento;
                lista.agregar(nuevoElemento);
                break;

            case '2':
                std::cout << "Elementos: ";
                lista.imprimir();
                break;

            case '3':
                int elementoABuscar;
                std::cout << "Ingrese el elemento a buscar: ";
                std::cin >> elementoABuscar;
                if (lista.buscar(elementoABuscar)) {
                    std::cout << "Elemento encontrado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '4':
                int elementoAEliminar;
                std::cout << "Ingrese el elemento a eliminar: ";
                std::cin >> elementoAEliminar;
                if (lista.eliminar(elementoAEliminar)) {
                    std::cout << "Elemento eliminado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '5':
                int valorAActualizar, nuevoValor;
                std::cout << "Ingrese el valor a actualizar: ";
                std::cin >> valorAActualizar;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> nuevoValor;
                if (lista.actualizar(valorAActualizar, nuevoValor)) {
                    std::cout << "Elemento actualizado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '6':
                std::cout << "Esta es la nueva opción." << std::endl;
                // Agrega aquí el código correspondiente a la nueva opción.
                break;

            case '7':
                std::cout << "Saliendo del programa." << std::endl;
                break;

            default:
                std::cout << "Opción no válida. Por favor, elija una opción válida." << std::endl;
                break;
        }
    } while (opcion != '7');

    return 0;
}
