/*Sistema de gestión de empleados. Usar HashMap para almacenar y gestionar empleados por
su número de identificación (ID).
● La clave será el número de identificación del empleado y el valor será su nombre.
● Implementa un menú con opciones para:
● Agregar un nuevo empleado.
● Buscar un empleado por su número de identificación.
● Eliminar un empleado del sistema.
● Imprimir la lista completa de empleados*/
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
    int opcion,numero;
    string nombre;
    HashMap<int,string> sistema(10);

    do{
        cout<<"1. Agrgar nuevo empleado"<<endl;
        cout<<"2. Buscar empleado por numero de identificacion"<<endl;
        cout<<"3. Eliminar empleado"<<endl;
        cout<<"4. Imprimir lista de empleados"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingresa una opcion"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Ingresa el numero de identificacion"<<endl;
                cin>>numero;
                cout<<"Ingresa el nombre"<<endl;
                cin>>nombre;
                sistema.put(numero,nombre);
                cout<<"Se agrego el empleado correctamente"<<endl;
                break;
            case 2:
                cout<<"Ingresa el numero del empleado"<<endl;
                cin>>numero;
                try {
                    nombre=sistema.get(numero);
                    cout<<"El nombre del empleado es: "<<nombre<<endl;
                }catch(int e){
                    cout<<"No se encontro el empleado"<<endl;
                }
                break;
            case 3:
                cout<<"Ingrese el numero del empleado que desea eliminar"<<endl;
                cin>>numero;
                sistema.remove(numero);
                cout<<"Se elimino el empleado correctamente"<<endl;
                break;
            case 4:
                sistema.print();
                break;
            case 5:
                cout<<"Salir"<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }
    } while(opcion!=5);
    return 0;
}
