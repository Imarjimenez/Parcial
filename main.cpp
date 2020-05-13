#include <iostream>
#include<fstream>
#include<math.h>
#include <stdio.h>
#include <string>


using namespace std;
//Funciones para la encriptacion de la contraseña

void array(int AntorAct[],int binario[],int posi, int n);

int Nceros(int array[],int tam);

int Nunos(int array[],int tam);
bool metodo1(int semilla,string cont_ingresada);

void DetoBin( int arrayBin[8],int a);
bool verificar_arreglos(char *g, char *contras);

//Funciones del programa

void tabla_peliculas();

int pago();
void generar_reporte();
void printsala(int m, int n, char **matriz);
void reserva_asiento(int m, int n, char **matriz, int num_boletas);
void cancelar_reserva(int m, int n, char **matriz, int num_boletas);

int main()
{
    int opcion,opcion2,semilla=4,id,num_sala,hora,asiento_disp=5,cant_asiento=128;
    string password,nom_pel,genero,duracion,clasificacion,formato,mes,dia;
    ofstream Guardar;


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

            cout<<"Ingrese la contrasena: ";
            cin>>password;

            if(metodo1(semilla,password)){
                cout<<"Correcta"<<endl;
                Guardar.open("cartelera.txt", ios::app); //abrir la base de datos
                do{
                    //Menu para el administrador
                    cout << "Bienvenido admin, seleccione una opcion, presione 0 para finalizar: " << endl
                   << "1) Ingresar peliculas en cartelera. "<<endl
                   << "2) Ingresar peliculas en estreno. "<<endl
                   << "3) Mostrar disponibilidad de asientos segun la pelicula. "<<endl
                   << "4) Reporte de ventas diario. "<<endl
                   << "5) Eliminar una pelicula en cartelera."<<endl
                   << "6) Eliminar peliculas en estreno."<<endl
                   << "7)Salir del menu del administrador."<<endl;cin>>opcion2;


                    switch(opcion2){
                    case 1:{

                        cout << "Ingrese ID: "<<endl;
                        cin>>id;
                        cout << "Ingrese el nombre de la pelicula: "<<endl;
                        cin>>nom_pel;
                        cout << "Ingrese el genero de la pelicula: "<<endl;
                        cin>>genero;
                        cout << "Ingrese la duracion de la pelicula: "<<endl;
                        cin>>duracion;
                        cout << "Ingrese la sala: "<<endl;
                        cin>>num_sala;
                        cout << "Ingrese la hora: "<<endl;
                        cin>>hora;
                        cout << "Ingrese la clasificacion de la pelicula: "<<endl;
                        cin>>clasificacion;
                        cout << "Ingrese si el formato es en 2D o 3D : "<<endl;
                        cin>>formato;


                       Guardar<<id<<" | "<<nom_pel<<" | "<<genero<<" | "<<duracion<<" min"<<" | "<<num_sala<<"/"<<hora<<" | "<<asiento_disp<<
                                "/"<<cant_asiento<<" | "<<clasificacion<<" | "<<formato<<" | "<<endl;


                    }break;
                    case 2:{
                        Guardar.open("estreno.txt", ios::app); //abrir la base de datos
                        cout << "Ingrese ID: "<<endl;
                        cin>>id;
                        cout << "Ingrese el nombre de la pelicula: "<<endl;
                        cin>>nom_pel;
                        cout << "Ingrese el genero de la pelicula: "<<endl;
                        cin>>genero;
                        cout << "Ingrese la duracion de la pelicula: "<<endl;
                        cin>>duracion;
                        cout << "Ingrese el mes de estreno: "<<endl;
                        cin>>mes;
                        cout << "Ingrese el dia de estreno: "<<endl;
                        cin>>dia;
                        cout << "Ingrese la clasificacion de la pelicula: "<<endl;
                        cin>>clasificacion;
                        cout << "Ingrese si el formato es en 2D o 3D : "<<endl;
                        cin>>formato;

                        Guardar<<id<<" | "<<nom_pel<<" | "<<genero<<duracion<<" min"<<" | "<<mes<<"/"<<dia<<
                        " | "<<asiento_disp<<"/"<<cant_asiento<<" | "<<clasificacion<<" | "<<formato<<" | "<<endl;


                    }break;
                    case 3:{
                    //Van haber 10 salas, 6 salas 2d/3d, 3 salas 4d y una sala  de menos capacidad.
                    //el numero de la sala, conllevara la cantidad de asientos
                    }break;
                    case 4:{


                    }break;
                    }

                }while(opcion2!=7);

            }
            else {

                cout<<"Incorrecta"<<endl;
            }

            }break;
            case 2:{

            }break;
        }

    }while(opcion!=7);


}

void tabla_peliculas(){

}



int pago(){
    int x,billete_50,billete_20,billete_10,billete_5,billete_2,billete_1,moneda_50,moneda_100,moneda_200,moneda_500;
           cout<<"Ingrese el numero: ";cin>>x;

                   billete_50= x/50000;cout<<"Billetes de 50.000: "<<billete_50<<endl;
                   x=x%50000;

                   billete_20=x/20000;cout<<"Billetes de 20.000: "<<billete_20<<endl;
                   x=x%20000;

                   billete_10=x/10000;cout<<"Billetes de 10.000: "<<billete_10<<endl;
                   x=x%10000;

                   billete_5=x/5000;cout<<"Billetes de 5.000: "<<billete_5<<endl;
                   x=x%5000;

                   billete_2=x/2000;cout<<"Billetes de 2.000: "<<billete_2<<endl;
                   x=x%2000;

                   billete_1=x/1000;cout<<"Billetes de 1.000: "<<billete_1<<endl;
                   x=x%1000;

                   moneda_500=x/500;cout<<"Monedas de 500: "<<moneda_500<<endl;
                   x=x%500;

                   moneda_200=x/200;cout<<"Monedas de 200: "<<moneda_200<<endl;
                   x=x%200;

                   moneda_100=x/100;cout<<"Monedas de 100: "<<moneda_100<<endl;
                   x=x%100;

                   moneda_50=x/50;cout<<"Monedas de 50: "<<moneda_50<<endl;
                   x=x%50;



                    return x;

}
void generar_reporte(){

}



void array(int AntorAct[],int binario[],int posi, int n){

    for(int i=0;i<n;i++){
        AntorAct[i]=binario[posi+i]; }//se forma un arreglo desde una cadena de n longitud y desde una posicion inicial
}

void DetoBin( int arrayBin[8],int a){

    int array[8];
    int i=0;

    while(a!=1){// se convierte un numero "a" en binario en orden inverso

        array[i]=a%2;//residuo de la division para pasar a base 2
        a=a/2;
        i++;}

    array[i]=1;// cociente luego de terminada la conversion
    array[i+1]=0; // cero final para completar los 8 bis

    for(int j=0, k=7;j<8;j++,k--){//se invierte el arreglo anterior para obtener el binario correcto
        int tmp = array[j];
        array[j] = arrayBin[k];
        arrayBin[k] = tmp;}
}

int Nceros(int array[],int tam){

    int Nceros=0;

    for(int i=0;i<tam;i++){
        if(array[i]==0){Nceros+=1;}
    }

    return Nceros;
}

int Nunos(int array[],int tam){

    int Nunos=0;

    for(int i=0;i<tam;i++){
        if(array[i]==1){Nunos+=1;}
    }

    return Nunos;
}
bool metodo1(int n,string cont_ingresada){


    //-------------------------------------se obtiene el mensaje y el tamaño del archivo ejercicio1.txt

    ofstream escritura;
    ifstream ver;

    escritura.open("cont_ingresada.txt",ios::out);
    ofstream archivo;
    string contra_ingre;
    archivo.open("salida1.txt");//salida.txt en modo entrada de datos




    escritura<<cont_ingresada<<" ";

    escritura.close();
    ver.open("cont_ingresada.txt");
    char *mensaje=new char[100];
    int aux[8];

    ver.getline(mensaje,100);
    int tam=ver.gcount()-1;

    //-------------------------------------------------------------------------------------------------

    int binario[tam*8]; //variable que va a almacenar el binario del mensaje
    int salida[tam*8];//variable que va a almacenar el  binario del mensaje codificado

    //----------------------------se obtiene el binario del mensaje-------------------------------------

    int i=0;//variable para pasar todo el exto a binario
    for(int j=0;j<tam;j++){//se obtiene el binario de todo el mensaje

        DetoBin(aux,(int)mensaje[j]);

        for(int k=0;k<8;k++){binario[i]=aux[k];i++;}
    }
    //--------------------------------------------------------------------------------------------------

    for(int i=0;i<tam*8;i++){salida[i]=binario[i];}//copia de binario en salida para modificar salida

    //-------------------------------inicio metodo 1---------------------------------------------------

    int contador=0;
    int anterior[n];
    int actual[n];

    for(int i=0;i<n;i++){//se invierte el primer bloque de n bits

        array(anterior,binario,contador,n);

        if(anterior[i]==1){salida[i]=0;}

        else if(anterior[i]==0){salida[i]=1;}
    }

    for(int i=0;i<tam*8;i+=n){//aplicacion de condiciones

        array(anterior,binario,contador,n);
        contador+=n;
        array(actual,binario,contador,n);

        int nceros=Nceros(anterior,4);
        int nunos=Nunos(anterior,4);

        if(nceros==nunos){// se invierte cada bit del grupo
            int p=contador;
            for(int j=0;j<n;j++){
                if(actual[j]==1){salida[p]=0;p++;}
                else if(actual[j]==0){salida[p]=1;p++;}}}

        else if(nceros>nunos){//se invierte cada 2 bits...
            int p=contador;
            for(int j=1;j<n;j+=2){
                if(actual[j]==1){salida[p+1]=0;p+=2;}
                else if(actual[j]==0){salida[p+1]=1;p+=2;}}}

        else if(nceros<nunos){//se invierte cada 3 bits
            int p=contador;
            for(int j=2;j<n;j+=3){
                if(actual[j]==1){salida[p+2]=0;p+=3;}
                else if(actual[j]==0){salida[p+2]=1;p+=3;}}}

        if(contador==(tam*8)-n){break;}// valor maximo en el que inicia anterior para que actual no salga del tamaño de binario
    }


    ver.close();


    //----------------------------------almacenamiento del binario del mensaje codificado en salida.txt



    for(int i=0;i<tam*8;i++){archivo<<salida[i];}//escritura del binario del mensaje codificado en salida.txt


    archivo.close();

    ifstream contrasena_ingresada;
    contrasena_ingresada.open("salida1.txt",ios::in);
    getline(contrasena_ingresada,contra_ingre);

    string contr_correcta;
    ifstream comprobar("contrasena.txt",ios::in);
    getline(comprobar,contr_correcta);
    remove("ejercicio3.txt");remove("cont_ingresada.txt");
               if(contra_ingre==contr_correcta){


                   return true;
               }
               else {


                   return false;
              }
    //--------------------------------final del metodo 1---------------------------------

}
void printsala(int m,int n,char **matriz){

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                cout << *(*(matriz + i) + j) << " ";
            }
            cout << endl;
        }
        cout << endl;


}

int reserva_asiento(int m, int n,char **matriz,int num_boletas,int asiento_disponible){
    char fila;
    int columna;
    for (int i=0;i>num_boletas;i++) {
    do{
        cout<<"Ingrese la fila: "<<endl;cin>>fila;
        cout<<"Ingrese el asiento(1-20): "<<endl; cin>>columna;
    }

    while(fila<65 || (fila>77 && fila<97) || fila>109);

    columna=columna-1;

    if(fila>=97 && fila<=109)
        fila=fila-97;
    else
        fila=fila-65;




    if (matriz[int (fila)][columna] =='-'){
        matriz[int (fila)][columna] = '+';
        cout<<"Asiento reservado."<<endl;
        asiento_disponible--;


    }
    else{
        cout<<"Asiento ocupado."<<endl;

    }
    }
    return asiento_disponible;
}

int cancelar_reserva(int m, int n,char **matriz,int num_boletas,int asiento_disponible){
    char fila;
    int columna;
    for (int i=0;i>num_boletas;i++) {
    do{
        cout<<"Ingrese la fila: "<<endl;cin>>fila;
        cout<<"Ingrese el asiento(1-18): "<<endl; cin>>columna;
    }



    while(fila<65 || (fila>77 && fila<97) || fila>109);

    columna=columna-1;

    if(fila>=97 && fila<=109)
        fila=fila-97;
    else
        fila=fila-65;




    if (matriz[int (fila)][columna] =='+'){
        matriz[int (fila)][columna] = '-';
        cout<<"Cancelacion exitosa."<<endl;
        asiento_disponible++;

    }
    else{
        cout<<"Asiento esta vacio."<<endl;

    }
    }
    return asiento_disponible;
}






