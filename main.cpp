#include <iostream>
#include<fstream>
#include<math.h>
#include <stdio.h>

using namespace std;
//Funciones para la encriptacion de la contraseña
template<typename T>
T array(T AntorAct[],T binario[],int posi, int n);
template<typename T>
T Nceros(T array[],int tam);
template<typename T>
T Nunos(T array[],int tam);
bool metodo1();
bool metodo2();

//Funciones del programa
bool verificar_conts();
void tabla_peliculas();
void peliculas_cartelera();
void selec_asiento();
bool verf_asiento();
void pago();
void generar_reporte();

int main()
{
    int opcion,metodo;


    do{

        cout<<"-----Bienvenido al cine-----"<<endl<<
              "\nSeleccione una opcion"<<endl<<
              "1.Ingresar como administrador"<<endl<<
              "2.Ingresar como usuario"<<endl<<
              "3.Salir"<<endl;
              cin>>opcion;
              system("cls");

        switch(opcion){
            case 1:{

            }break;
            case 2:{

            }break;
        }

    }while(opcion!=3);


}
bool verificar_conts(){

}
void tabla_peliculas(){

}
void peliculas_cartelera(){

}
void selec_asiento(){

}
bool verf_asiento(){

}
void pago(){

}
void generar_reporte(){

}
template<typename T>
T Nceros(T array[],int tam){

    T Nceros=0;

    for(int i=0;i<tam;i++){
        if(array[i]=='0'){Nceros+=1;}
    }
    return (Nceros);
}
template<typename T>
T Nunos(T array[],int tam){
    T Nunos=0;

    for(int i=0;i<tam;i++){
        if(array[i]=='1'){Nunos+=1;}
    }
    return(Nunos);
}
