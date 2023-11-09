#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;


class ExcepcionGradoInvalido : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Grado no valido.";
    }
};


class Estudiante {
private:
    string nombre;
    int edad;
    string grado;
    vector<string> materias;

public:
    Estudiante(string n, int e, string g) : nombre(n), edad(e), grado(g) {
        if (g == "Primero" || g == "Segundo" || g == "Tercero") {
            grado = g;
        } else {
            throw ExcepcionGradoInvalido();
        }
    }
    string obtener_grado() const {
        return grado;
    }

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
vector<Estudiante> filtrar_por_grado(const vector<Estudiante>& estudiantes, const string& grado) {
    vector<Estudiante> estudiantes_filtrados;

    for (const Estudiante &estudiante: estudiantes) {
        if (estudiante.obtener_grado() == grado) {
            estudiantes_filtrados.push_back(estudiante);
        }
    }
    return estudiantes_filtrados;
}

void intercambiar_valores(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double calcular_promedio(const vector<int>& calificaciones) {
    if (calificaciones.empty()) {
        cerr << "Error: La lista de calificaciones esta vacia." << endl;
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
    Estudiante estudiante1("Chahla", 19, "Primero");
    estudiante1.mostrar_info();
    estudiante1.registrar_materia("Matematicas");
    estudiante1.registrar_materia("Programacion");
    estudiante1.registrar_materia("Fisica");
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
        vector<Estudiante> lista_estudiantes = {
                Estudiante("Chahla", 19, "Primero"),
                Estudiante("Maria", 19, "Segundo"),
                Estudiante("Lisa", 18, "Primero"),
                Estudiante("Oihana", 18, "Primero"),
                Estudiante("Dina", 19, "Segundo")
        };
        string grado_a_filtrar = "Primero";
        vector<Estudiante> estudiantes_filtrados = filtrar_por_grado(lista_estudiantes, grado_a_filtrar);
        cout << "Estudiantes de " << grado_a_filtrar << ":\n";
        for (Estudiante estudiante : estudiantes_filtrados) {
            estudiante.mostrar_info();
        }
        try {

            Estudiante estudiante1("Juan", 15, "Cuarto");
            estudiante1.mostrar_info();
        } catch (const ExcepcionGradoInvalido& e) {
            std::cerr << "Excepcion capturada: " << e.what() << std::endl;
        }













        return 0;

}
