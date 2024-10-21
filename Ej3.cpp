/*Registro de productos en una tienda. Almacenar productos de una tienda usando un código
único como clave y el nombre del producto como valor. Usa el HashMap para almacenar los
productos. El código de producto es la clave y el nombre es el valor.
Implementa opciones para:
● Añadir productos.
● Buscar productos por su código.
● Actualizar el nombre de un producto existente.
● Eliminar productos.
● Imprimir todos los productos registrados.
● Desafío adicional: Implementa el manejo de colisiones, y lanza excepciones cuando se
intenten agregar productos con códigos ya existentes o buscar productos no
registrados.*/
#include <iostream>
#include "HashMap/HashMap.h"
using namespace std;

unsigned int hashString(string clave){ // Cambiado a string en lugar de const string&
    unsigned int hash=0;
    for (char c:clave) {
        hash +=c;
    }
    return hash;
}

int main() {
    int opcion, numero;
    string nombre, nombreNuevo;
    HashMap<int, string> tienda(10);

    do {
        cout << "1. Anadir un producto" << endl;
        cout << "2. Buscar productos con su codigo" << endl;
        cout << "3. Actualizar el nombre de un producto" << endl;
        cout << "4. Eliminar un producto" << endl;
        cout << "5. Imprimir todos los productos" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout<<"Ingresa el codigo del producto"<<endl;
                cin>>numero;
                cout<<"Ingresa el nombre del producto"<<endl;
                cin>>nombre;
                tienda.put(numero, nombre);
                cout<<"Se agrego el producto correctamente"<<endl;
                break;
            case 2:
                cout<<"Ingresa el codigo del producto"<<endl;
                cin>>numero;
                try{
                    nombre=tienda.get(numero);
                    cout<<"El nombre del producto es: "<<nombre<<endl;
                } catch(int e){
                    cout<<"No se encontro el producto"<<endl;
                }
                break;
            case 3:
                cout<<"Ingrese el numero del producto a modificar: ";
                cin>>numero;
                try {
                    tienda.remove(numero);
                    cout << "producto eliminado!" << endl;
                } catch (int e) {
                    cout << "Error: producto no encontrado" << endl;
                }
                cout<<"Ingrese el nombre nuevo del producto"<<endl;
                cin>>nombreNuevo;
                cout<<"Ingrese el mismo codigo que elimino"<<endl;
                cin>>numero;
                tienda.put(numero, nombreNuevo);
                cout<<"Se actualizo el nombre del producto correctamente"<<endl;
                break;
            case 4:
                cout<<"Ingresa el codigo del producto"<<endl;
                cin>>numero;
                tienda.remove(numero);
                cout<<"Se elimino el producto correctamente"<<endl;
                break;
            case 5:
                tienda.print();
                break;
            case 6:
                cout<<"Salir"<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while (opcion != 6);
    return 0;
}