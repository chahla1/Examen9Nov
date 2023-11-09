#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


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
void intercambiar_valores(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int dividir(int a, int b) {
    if (b == 0) {
        throw invalid_argument("Error: Division por cero.");
    }
    return a / b;
}



int main() {
    int a, b, suma;
    int x = 5, y = 10;

    cout<<"Ingrese un valor para a: "<<endl;
    cin>>a;
    cout<<"Ingrese un valor para b: "<<endl;
    cin>>b;
    suma = a + b;
    cout<<"\nLa suma de los valores es: "<<suma<<endl;
    Estudiante estudiante1("Chahla", 19, "Primero de carrera");
    estudiante1.mostrar_info();
    cout<<"\nLos valores originales son x = "<<x<<" e y = "<<y<<endl;
    intercambiar_valores(&x, &y);
    cout<<"\nLos valores intercambiados son x = "<<x<<" e y = "<< y <<endl;
    try{
        int resultado = dividir(20,5);
        cout<<"\nEl resultado de la division es: "<< resultado<<endl;
        resultado = dividir(10, 0);
        cout<<"\nEste mennsaje no se imprimira"<<endl;
    }catch(const exception& e){
        cerr<<"Se captura la excepcion"<< e.what()<<endl;
    }




    return 0;

}
