// Diego Sahid García Galván and Antonio Marban Regalado
// Started on 21/11/2022

#include <iostream>
#include <string>
#include "Clases/Producto.cpp"
#include "Clases/Cliente.cpp"
#include "Clases/Tienda.cpp"
using namespace std;

int main(){
    // Tienda T1;
    // Cliente Diego;
    // // Diego.setIdentificadorC("0");
    // // T1.setClientesT(Diego, 0);
    // T1.agregarLosProductos("MiCarrito.txt");
    // T1.agregarCliente();
    // T1.llenarCarrito();
    string identificadorTienda, nombreTienda, direccionTienda, nombreArchivo;
    cout << "\nBienvenido! Por favor ingrese el identificador de la tienda: " << endl;
    cin >> identificadorTienda;
    cout << "\nA continuacion ingrese el nombre de la tienda: " << endl;
    cin >> nombreTienda;
    cout << "\nPor ultimo, ingrese la direccion de la tienda: " << endl;
    cin >> direccionTienda;

    Tienda tiendita(identificadorTienda, nombreTienda, direccionTienda); // Genero un objeto tipo Tienda.h con los parametros que ingresó el usuario.

    tiendita.imprimirTienda();
    tiendita.imprimirProductos();

    cout << "\n\nBienvenido a la tienda virtual de \"" << tiendita.getNombreT() << "\"" << endl;

    int eleccion;
    bool hayArchivo = true;
    do { // Repetir el menu hasta que escoja la opcion de salir
        cout << "\n============================================================" << endl;
        cout << "\nPor favor elija una opcion del menu" << endl;
        cout << "\n[1] Agregar productos desde archivo" << endl;
        cout << "[2] Agregar productos uno a uno" << endl;
        cout << "[3] Agregar clientes" << endl;
        cout << "[4] Comprar productos" << endl;
        cout << "[5] Realizar cierre del dia" << endl;
        cout << "[6] Salir\n" << endl;
        cout << "============================================================\n" << endl;

        cout << ">";
        cin >> eleccion;

        if (eleccion < 0) {
            cout << "\n<< Esa no es una opcion valida. >>" << endl;
        }
        else if (eleccion == 1 && hayArchivo) { // Agregar productos desde archivo
            cout << "\nIngrese el nombre del archivo que contiene los datos de los productos: " << endl;
            cout << ">";
            cin >> nombreArchivo;
            ifstream miArchivo; // objeto de tipo archivos de entrada
            miArchivo.open(nombreArchivo.c_str(), ios::out | ios::in);
            miArchivo.close();
            // el archivo cuyo nombre llega como parametro, se abre para lectura
            if (!miArchivo) // si el archivo no se encuentra, marcara error 
                cout<<"\n<< El archivo no existe >>\n";
            else {
                tiendita.agregarLosProductos(nombreArchivo);
                hayArchivo = false;
            }
            
        }
        else if (eleccion == 1 && hayArchivo == false){
            cout << "\nYa no puedes añadir productos desde un archivo, ya lo hiciste" << endl;
        }
        else if (eleccion == 2) { // Agregar productos uno a uno
            cout << "\nAgreguemos los productos juntos: " << endl;
            tiendita.agregarElProducto();
        }
        else if (eleccion == 3) { // Agregar clientes
            tiendita.agregarCliente();
        }
        else if (eleccion == 4) { // Comprar productos
            tiendita.llenarCarrito();
        }
        else if (eleccion == 5) { // Realizar cierre del dia
            tiendita.cerrarOperaciones();
        }
    }while(eleccion != 6);
    cout << "\nMuchas gracias, vuelva pronto ;)" << endl;
}
