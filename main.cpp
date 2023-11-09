#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;


class Estudiante {
private:
    string nombre;
    int edad;
    string grado;
    vector<string> materias;

public:
    Estudiante(string n, int e, string g) : nombre(n), edad(e), grado(g) {}

    void mostrar_info() {
        std::cout << "\nNombre: " << nombre << std::endl;
        std::cout << "\nEdad: " << edad << std::endl;
        std::cout << "\nGrado: " << grado << std::endl;
    }

    void registrar_materia(const string &materia) {
        materias.push_back(materia);
    }

    void mostrar_materias() {
        cout << "\nMaterias registradas: " << endl;
        for (const auto &materia: materias) {
            cout << " - " << materia << endl;
        }
    }
};

void intercambiar_valores(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double calcular_promedio(const vector<int>& calificaciones) {
    if (calificaciones.empty()) {
        cerr << "Error: La lista de calificaciones está vacía." << endl;
        return 0.0;
    }
    int suma1 = 0;
    for (int calificacion: calificaciones) {
        suma1 += calificacion;
    }
    return static_cast<double>(suma1) / calificaciones.size();
}

int dividir(int a, int b) {
    if (b == 0) {
        throw invalid_argument("Error: Division por cero.");
    }
    return a / b;
}

class RegistroAsistencia{
private:
    string fecha;
    string estado;
public:
    RegistroAsistencia(const string& fecha, const string& estado): fecha(fecha), estado(estado){}
    void mostrar_asistencia(){
        cout<<"Fecha: "<<fecha<<endl;
        cout<<"Estado de asistencia: "<<estado<<endl;

    }
};


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
    estudiante1.registrar_materia("Matematicas");
    estudiante1.registrar_materia("Ciencias");
    estudiante1.registrar_materia("Historia");
    estudiante1.mostrar_materias();
    cout<<"\nLos valores originales son x = "<<x<<" e y = "<<y<<endl;
    intercambiar_valores(&x, &y);
    cout<<"\nLos valores intercambiados son x = "<<x<<" e y = "<< y <<endl;
        vector<int> calificaciones = {5, 8, 7, 9, 6};
        double promedio = calcular_promedio(calificaciones);
        cout<<"\nEl promedio de calificaciones es: "<<promedio<<endl;
    try{
        int resultado = dividir(20,5);
        cout<<"\nEl resultado de la division es: "<< resultado<<endl;
        resultado = dividir(10, 0);
        cout<<"\nEste mennsaje no se imprimira"<<endl;
    }catch(const exception& e){
        cerr<<"\nSe captura la excepcion, "<< e.what()<<endl;
    }
    RegistroAsistencia registro1("08/11/2023", "Ha Asistido");
    RegistroAsistencia registro2("09/11/2023", "Ha Faltado");
    cout<<"Primer registro: "<<endl;
    registro1.mostrar_asistencia();
    cout << "\nRegistro 2:" << endl;
    registro2.mostrar_asistencia();












    return 0;

}
