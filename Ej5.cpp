/*Biblioteca digital
Objetivo: Gestionar una colección de libros usando un sistema de hash.
● La clave será el ISBN del libro y el valor será el título del libro.
● Crea funciones para:
● Agregar nuevos libros a la biblioteca.
● Buscar un libro por su ISBN.
● Eliminar libros del sistema.
● Imprimir todos los libros registrados.
Desafíos:
● Implementar la resolución de colisiones.
● Verificar que no se repitan libros con el mismo ISBN.*/
#include <iostream>
#include "HashMap/HashMapList.h"
using namespace std;

unsigned int hashString(string clave){ // Cambiado a string en lugar de const string&
    unsigned int hash=0;
    for (char c:clave) {
        hash +=c;
    }
    return hash;
}

int main(){
    HashMapList<int,string> libros(10);
    int ISBN;
    string titulo;
    do{
        cout<<"1. Agregar nuevo libro"<<endl;
        cout<<"2. Buscar un libro por ISBN"<<endl;
        cout<<"3. Eliminar un libro"<<endl;
        cout<<"4. Imprimir todos los libros"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingresa una opcion"<<endl;
        cin>>ISBN;
        switch(ISBN){
            case 1:
                cout<<"Ingresa el ISBN"<<endl;
                cin>>ISBN;
                cout<<"Ingresa el titulo"<<endl;
                cin>>titulo;
                try{
                    libros.put(ISBN,titulo);
                    cout<<"Libro agregado"<<endl;
                } catch(int e){
                    cout<<"Error: "<<e<<endl;
                }
                break;
            case 2:
                cout<<"Ingresa el ISBN"<<endl;
                cin>>ISBN;
                try{
                    cout<<"El libro con ISBN "<<ISBN<<" es: "<<libros.get(ISBN)<<endl;
                } catch(int e){
                    cout<<"Error: "<<e<<endl;
                }
                break;
            case 3:
                cout<<"Ingresa el ISBN"<<endl;
                cin>>ISBN;
                try{
                    libros.remove(ISBN);
                    cout<<"Libro eliminado"<<endl;
                } catch(int e){
                    cout<<"Error: "<<e<<endl;
                }
                break;
            case 4:
                libros.print();
                break;
            case 5:
                cout<<"Salir"<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(ISBN!=5);

    return 0;
}