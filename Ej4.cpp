/*Sistema de votacionesObjetivo: Crear un sistema de votaciones donde cada votante tiene un número de
identificación y vota por un candidato.
La clave será el número de identificación del votante y el valor será el nombre del candidato
por el que ha votado.
Implementa funciones para:
● Registrar un voto.
● Verificar por quién votó una persona (buscando por su ID).
● Eliminar un voto si fue incorrecto.
● Imprimir todos los votos registrados.
Puntos clave:
● Prevenir que un votante registre más de un voto.
● Mostrar un error si se intenta eliminar un voto no existente.*/
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
    HashMapList<int,string> votos(11); //HashMap de 10 posiciones
    int id,opcion;
    string nombre;
    do{
        cout<<"1. Votar"<<endl;
        cout<<"2. Ver votos por persona"<<endl;
        cout<<"3. Eliminar votos"<<endl;
        cout<<"4. Imprimir votos"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingresa una opcion"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Ingresa el ID"<<endl;
                cin>>id;
                cout<<"Ingresa el nombre del candidato"<<endl;
                cin>>nombre;
                try{
                votos.put(id,nombre);
                cout<<"Voto registrado"<<endl;
                } catch(int e){
                    cout<<"Ya se voto"<<endl;
                }
                break;
            case 2:
                cout<<"Ingresa el ID"<<endl;
                cin>>id;
                try {
                    cout<<"Voto por: "<<votos.get(id)<<endl;
                } catch (int e) {
                    cout<<"No se encontro el ID"<<endl;
                }
                break;
            case 3:
                cout<<"Ingresa el ID"<<endl;
                cin>>id;
                try {
                    votos.remove(id);
                    cout<<"Voto eliminado"<<endl;
                } catch (int e) {
                    cout<<"No se encontro el ID"<<endl;
                }
                    break;
            case 4:
                votos.print();
                break;
            case 5:
                cout<<"Salir"<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
        }
    }while(opcion!=5);

    return 0;
}