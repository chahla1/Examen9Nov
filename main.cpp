#include <iostream>
#include <string>

using namespace std;

int a, b, suma;
class Estudiante {
private:
    string nombre;
    int edad;
    string grado;

public:
    Estudiante(string n, int e, string g) : nombre(n), edad(e), grado(g) {}

    void mostrar_info() {
        std::cout << "\nNombre: " << nombre << std::endl;
        std::cout << "\nEdad: " << edad << std::endl;
        std::cout << "\nGrado: " << grado << std::endl;
    }
};


int main() {

    cout<<"Ingrese un valor para a: "<<endl;
    cin>>a;
    cout<<"Ingrese un valor para b: "<<endl;
    cin>>b;
    suma = a + b;
    cout<<"\nLa suma de los valores es: "<<suma<<endl;
    Estudiante estudiante1("Chahla", 19, "Primero de carrera");
    estudiante1.mostrar_info();




    return 0;

}
