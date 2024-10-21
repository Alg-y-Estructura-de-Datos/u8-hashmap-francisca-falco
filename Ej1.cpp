/*Simulación de un pequeño diccionario. Utilizaremos el HashMap para almacenar pares de
palabras (clave) y sus significados (valor).
El usuario podrá:
● Agregar nuevas palabras y sus significados.
● Buscar el significado de una palabra.
● Eliminar una palabra del diccionario.
● Ver todas las palabras en el diccionario*/
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
    int opcion;
    string palabra,significado;
    unsigned int tamanoTabla=10;
    HashMap<string,string> diccionario(tamanoTabla,hashString);

    do{
        cout<<"1. Agregar nueva palabra y significado"<<endl;
        cout<<"2. Buscar significado de una palabra"<<endl;
        cout<<"3. Eliminar palabra del diccionario"<<endl;
        cout<<"4. Ver todas las palabras en el diccionario"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingresar opcion"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese la palabra nueva"<<endl;
                cin>>palabra;
                cout<<"Ingrese el significado de la palabra nueva"<<endl;
                cin.ignore();
                getline(cin, significado);
                diccionario.put(palabra, significado);
                cout<<"Se agrego la palabra corecctamente"<<endl;
                break;
            case 2:
                cout<<"Ingrese la palabra a buscar"<<endl;
                cin>>palabra;
                try {
                        significado=diccionario.get(palabra);
                        cout<<"Significado de "<<palabra<<": "<<significado<<endl;
                }catch(int e){
                    if(e==404){
                        cout<<"No se encontro la palabra"<<endl;
                    }else{
                        cout<<"Error: Conflicto en la busqueda"<<endl;
                    }
                }
                break;
            case 3:
                cout<<"Ingrese la palabra a eliminar:"<<endl;
                cin>>palabra;
                diccionario.remove(palabra);
                cout<<"Palabra eliminada correctamente"<<endl;
                break;
            case 4:
                cout<<"Las palabras del diccionario son:"<<endl;
                diccionario.print();
                break;
            case 5:
                cout<<"Saliendo"<<endl;
            default:
                cout<<"Opcion invalida"<<endl;
        }
    } while (opcion!=0);

    return 0;
}
