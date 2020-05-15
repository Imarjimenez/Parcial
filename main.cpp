#include <iostream>
#include<fstream>
#include<math.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include <map>

#include <array>

using namespace std;
//Funciones para la encriptacion de la contraseña
template<typename T>
void array1(T AntorAct[],T binario[],int posi, int n);

int Nceros(int array[],int tam);

int Nunos(int array[],int tam);
bool metodo1(int semilla,string cont_ingresada);

void DetoBin( int arrayBin[8],int a);
bool verificar_arreglos(char *g, char *contras);


//Funciones del programa

void tabla_peliculas();
void estreno_peliculas();
bool verifica_id(int id,ifstream &Leer);
bool verifica_id_estreno(int id ,ifstream &Leer);
int pago(int valor_compra);

void actualizar_num_asientos( int id_aux);
void cancelacion_num_asientos(int id_aux);
bool buscar_pelicula(int id_aux);
void printsala(int num_sala);
int reserva_asiento( int num_sala, int id_aux);
void cancelar_reserva(int num_sala, int id_aux);
void modificar_asiento(int num_sala, string sillas);
int retorna_sala(int id_aux);
void actualizar_venta(int id_aux, int x);
int main()
{
    int opcion,opcion2,opcion3,semilla=4,id,num_sala,hora,asiento_disp,cant_asiento,id_aux,venta=0;
    string password,nom_pel,genero,duracion,clasificacion,formato,mes,dia,pelicula_aux;
    ofstream Guardar, Guardar_estreno,Reemplazo,Reporte;
    ifstream Leer, Leer_estreno,Reporte1;
    array<int,10> salas= {162,162,162,162,162,234,234,234,126,126};//asientos segun la sala



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
                Guardar.open("cartelera.txt",ios::out | ios::app); //abrir la base de datos
                Guardar_estreno.open("estreno.txt", ios::app); //abrir la base de datos
                Reporte.open("reporte.txt",ios::app);



                do{
                    //Menu para el administrador
                    cout << "Bienvenido admin, seleccione una opcion, presione 7 para finalizar: " << endl
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
                        cant_asiento=salas.at(num_sala-1);


                       ifstream Leer("cartelera.txt",ios::in);
                       if(verifica_id(id,Leer))
                       Guardar<<id<<"  "<<nom_pel<<"  "<<genero<<"  "<<duracion<<"  "<<num_sala<<"  "<<hora<<"  "<<asiento_disp<<
                               "  "<<cant_asiento<<"  "<<clasificacion<<"  "<<formato<<"  "<<endl;


                    }break;

                    case 2:{


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

                        ifstream Leer("estreno.txt",ios::in);
                        if(verifica_id_estreno(id,Leer))
                        Guardar_estreno<<id<<"  "<<nom_pel<<"  "<<genero<<"  "<<duracion<<
                            "  "<<dia<<" "<<mes<<"  "<<clasificacion<<"  "<<formato<<endl;


                    }break;
                    case 3:{
                    //Van haber 10 salas, 5 salas 2d/3d, 3 salas 4d y dos salas  de menos capacidad.
                    //el numero de la sala, conllevara la cantidad de asientos
                        cout<<"Ingrese el numero de la sala: ";cin>>num_sala;
                        printsala(num_sala);
                    }break;
                    case 4:{

                        if(verifica_id_estreno(id,Leer)){
                            Leer.open("reporte.txt");
                            Leer>>id;
                        while (!Leer.eof()) {


                            Leer>>venta;

                            cout<<"-------------------------------------------------------"<<endl;
                            cout<<"Id: "<<id<<endl<<"Numero de ventas: "<<venta<<endl;
                            cout<<endl;
                            Leer>>id;

                        }
                        Leer.close();



                        }
                        else {
                            cout<<"Pelicula no existe";
                        }




                    }break;
                    case 5:{
                        Guardar.close();
                        tabla_peliculas();


                    }break;
                    case 6:{
                        Guardar_estreno.close();
                        estreno_peliculas();

                    }break;
                    }

                }while(opcion2!=7);

            }
            else {

                cout<<"Incorrecta"<<endl;
            }

            }break;
            case 2:{
             do{
                //menu del usuario

                cout << "Bienvenido admin, seleccione una opcion, presione 0 para finalizar: " << endl
               << "1) Ver peliculas en cartelera. "<<endl
               << "2) Ver peliculas en estreno. "<<endl
               << "3) Comprar una entrada. "<<endl
               << "4) Cancelar una reserva."<<endl
               << "5) Salir del menu del usuario."<<endl;cin>>opcion3;

                switch (opcion3) {
                    case 1:{
                        Leer.open("cartelera.txt");
                        Leer>>id;
                    while (!Leer.eof()) {


                        Leer>>nom_pel;
                        Leer>>genero;
                        Leer>>duracion;
                        Leer>>num_sala;
                        Leer>>hora;
                        Leer>>asiento_disp;
                        Leer>>cant_asiento;
                        Leer>>clasificacion;
                        Leer>>formato;

                        cout<<"-------------------------------------------------------"<<endl;
                        cout<<"| "<<id<<" | "<<nom_pel<<" | "<<genero<<" | "<<duracion<<" min"<<" | "<<num_sala<<"/"<<hora<<" | "<<asiento_disp<<
                              "/"<<cant_asiento<<" | "<<clasificacion<<" | "<<formato<<" | "<<endl;
                        cout<<"-------------------------------------------------------"<<endl;
                        cout<<endl;
                        Leer>>id;

                    }
                    Leer.close();


                    }break;



                    case 2:{
                    Leer_estreno.open("estreno.txt");
                    Leer_estreno>>id;
                while (!Leer_estreno.eof()) {


                    Leer_estreno>>nom_pel;
                    Leer_estreno>>genero;
                    Leer_estreno>>duracion;

                    Leer_estreno>>dia;
                    Leer_estreno>>mes;
                    Leer_estreno>>clasificacion;
                    Leer_estreno>>formato;

                    cout<<"-------------------------------------------------------"<<endl;
                    cout<<"| "<<id<<" | "<<nom_pel<<" | "<<genero<<" | "<<duracion<<" min"<<" | "<<dia<<"/"<<mes
                          <<" | "<<clasificacion<<" | "<<formato<<" | "<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                    cout<<endl;
                    Leer_estreno>>id;

                }
                Leer_estreno.close();

                    }break;
                    case 3:{
                        system("cls");

                        cout<<"Escriba el id de la pelicula: "<<endl;cin>>id_aux;

                        if(buscar_pelicula(id_aux)){


                            //Freserva_asiento(retorna_sala(id_aux),id_aux);
                            pago((reserva_asiento(retorna_sala(id_aux),id_aux)));



                        }
                        else {
                            cout<<"Pelicula no encontrada"<<endl;
                        }

                    }break;
                    case 4:{
                         cout<<"Ingrese el id de la pelicula donde realizo la reserva: "<<endl;cin>>id_aux;
                        cancelar_reserva(retorna_sala(id_aux),id_aux);

                    }break;

                }

            }while(opcion3!=5);

            }break;
        }

    }while(opcion!=3);


}


//inicio de funciones


int pago(int valor_compra){
    int x,y,billete_50,billete_20,billete_10,billete_5,billete_2,billete_1,moneda_50,moneda_100,moneda_200,moneda_500;
           cout<<"Ingrese el dinero: ";cin>>y; x=y-valor_compra;int z=valor_compra-y;

           if(y<valor_compra){
           cout<<"Dinero incompleto, faltan "<<z<<endl;
           }
           else {


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




        }
        return x;

}

void estreno_peliculas(){ //elimina peliculas en estreno
    int id,num_sala,hora,asiento_disp=5,cant_asiento=128;;
    string nom_pel,genero,duracion,clasificacion,formato,mes,dia,pelicula_aux;
    ifstream Leer;
    ofstream Reemplazo;
    Leer.open("estreno.txt",ios::in);
    Reemplazo.open("auxiliar.txt");
    Leer>>id;
    bool encontrado = false;
    cout <<"Ingrese id de la pelicula a eliminar: ";
    cin>>pelicula_aux;

    if(Leer.is_open()){
    while (!Leer.eof()){

        Leer>>nom_pel;
        Leer>>genero;
        Leer>>duracion;
        Leer>>num_sala;
        Leer>>hora;
        Leer>>asiento_disp;
        Leer>>cant_asiento;
        Leer>>clasificacion;
        Leer>>formato;

        if(to_string(id)==pelicula_aux){
            encontrado = true;

            cout<<"Eliminada exitosamente"<<endl;
        }else{

            Reemplazo<<id<<"  "<<nom_pel<<"  "<<genero<<"  "<<duracion<<
                "  "<<dia<<" "<<mes<<"  "<<clasificacion<<"  "<<formato<<endl;


        }
        Leer>>id;
    }
    }
    if(encontrado==false)
        cout<<"Pelicula no esta en cartelera"<<endl;

    Leer.close();
    Reemplazo.close();

    string str("estreno.txt");
    remove(str.c_str());
    rename("auxiliar.txt","estreno.txt");

}


template<typename T>
void array1(T AntorAct[],T binario[],int posi, int n){

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

        array1(anterior,binario,contador,n);

        if(anterior[i]==1){salida[i]=0;}

        else if(anterior[i]==0){salida[i]=1;}
    }

    for(int i=0;i<tam*8;i+=n){//aplicacion de condiciones

        array1(anterior,binario,contador,n);
        contador+=n;
        array1(actual,binario,contador,n);

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
void printsala(int num_sala){
    string sillas;
    int Num_salas;
    int fila,columna;
    if(num_sala>=1 && num_sala<=5){
       fila=9;columna=18;
    }
    else if (num_sala>=6 && num_sala<=8) {
        fila=13;columna=18;
    }
    else if (num_sala>=9 && num_sala<=10) {
        fila=7;columna=18;
    }
    else {
        cout<<"Numero de sala no existe"<<endl;
    }


    ifstream Leer;
    Leer.open("salas.txt");
    Leer>>Num_salas;
    while (!Leer.eof()) {
        Leer>>sillas;
        if(Num_salas==num_sala){
            cout<<"La sala numero "<<num_sala<<" es"<<endl;
           // cout<<sillas<<endl;
            break;

        }
        Leer>>Num_salas;
    }
    Leer.close();

    for (int i=1;i<=(fila*columna);i++) {



        cout<<sillas.at(i-1);
        if(i%columna==0){
            cout<<endl;
        }

    }



}

int reserva_asiento(int num_sala,int id_aux){

    int fila,columna;

    if(num_sala>=1 && num_sala<=5){
       fila=9;columna=18;
    }
    else if (num_sala>=6 && num_sala<=8) {
        fila=13;columna=18;
    }
    else if (num_sala>=9 && num_sala<=10) {
        fila=7;columna=18;
    }
    else {
        cout<<"Numero de sala no existe"<<endl;
    }
    string sillas;
    int Num_salas, costo=7000;
    ifstream Leer;
    Leer.open("salas.txt",ios::in);
    Leer>>Num_salas;
    while (!Leer.eof()) {
        Leer>>sillas;
        if(Num_salas==num_sala){
            cout<<"La sala numero "<<num_sala<<" es"<<endl;

            break;

        }
        Leer>>Num_salas;
    }
    char matriz[fila][columna];
    Leer.close();
    int col=0;
    for (int i=0;i<(fila*columna);i++) {
        if(i%columna==0){
            col=0;

            cout<<endl;


        }
        cout<<sillas.at(i);
        matriz[i/columna][col]=sillas.at(i); //Guardar cada silla en una matriz----
        col++;
    }
    cout<<endl;


    int fila_usu,columna_usu;

        cout<<"Ingrese la fila:"
              " "<<endl;cin>>fila_usu;
        cout<<"Ingrese el asiento(1-18): "<<endl; cin>>columna_usu;




    if (matriz[fila_usu][columna_usu] =='+'){
        matriz[fila_usu][columna_usu] = '-';
        cout<<"Asiento reservado."<<endl;
        actualizar_num_asientos(id_aux);

        actualizar_venta(id_aux,1);




        sillas="";




        for (int i=0;i<fila;i++) {
            for (int j=0;j<columna;j++) {
                sillas=sillas+matriz[i][j];

            }

        }
    modificar_asiento(num_sala,sillas);
    if((num_sala>=1 && num_sala<=5) || (num_sala>=9 && num_sala<=10)){

        if(num_sala==0 || fila_usu==1){ //Es preferencial
            costo=costo+5000;

        }
    }
    else if (num_sala>=6 && num_sala<=8) {// Es 3d
        costo=costo+10000;
        if(num_sala==0 || fila_usu==1){ //Es preferencial
            costo=costo+5000;

        }
    }


    }
    else{
        cout<<"Asiento ocupado."<<endl;
        costo=0;

    }
    return costo;

}





void tabla_peliculas(){//elimina las peliculas en cartelera
    int id,num_sala,hora,asiento_disp,cant_asiento;
    string nom_pel,genero,duracion,clasificacion,formato,pelicula_aux;
    ifstream Leer;
    ofstream Reemplazo;
    Leer.open("cartelera.txt",ios::in);
    Reemplazo.open("auxiliar.txt");
    Leer>>id;
    bool encontrado = false;
    cout <<"Ingrese id de la pelicula a eliminar: ";
    cin>>pelicula_aux;

    if(Leer.is_open()){
    while (!Leer.eof()){

        Leer>>nom_pel;
        Leer>>genero;
        Leer>>duracion;
        Leer>>num_sala;
        Leer>>hora;
        Leer>>asiento_disp;
        Leer>>cant_asiento;
        Leer>>clasificacion;
        Leer>>formato;

        if(to_string(id)==pelicula_aux){
            encontrado = true;

            cout<<"Eliminada exitosamente"<<endl;
        }else{

            Reemplazo<<id<<"  "<<nom_pel<<"  "<<genero<<"  "<<duracion<<"  "<<num_sala<<"  "<<hora<<"  "<<asiento_disp<<
                    "  "<<cant_asiento<<"  "<<clasificacion<<"  "<<formato<<"  "<<endl;

        }
        Leer>>id;
    }
    }
    if(encontrado==false)
        cout<<"Pelicula no esta en cartelera"<<endl;

    Leer.close();
    Reemplazo.close();

    string str("cartelera.txt");
    remove(str.c_str());
    rename("auxiliar.txt","cartelera.txt");

}

bool verifica_id(int id_aux, ifstream &Leer){

    int id,num_sala,hora,asiento_disp,cant_asiento;
    string nom_pel,genero,duracion,clasificacion,formato,pelicula_aux;

    Leer>>id;
    while(!Leer.eof()){
        Leer>>nom_pel;
        Leer>>genero;
        Leer>>duracion;
        Leer>>num_sala;
        Leer>>hora;
        Leer>>asiento_disp;
        Leer>>cant_asiento;
        Leer>>clasificacion;
        Leer>>formato;

        if(id==id_aux){
            Leer.close();
            cout<<"La pelicula no se puede agregar debido a que  el Id ya existe"<<endl;
            return false;

        }
        Leer>>id;
    }
    Leer.close();
    return true;

}
bool verifica_id_estreno(int id_aux ,ifstream &Leer){
int id;
string nom_pel,genero,duracion,clasificacion,formato,mes,dia;
    Leer>>id;
    while(!Leer.eof()){
    Leer>>nom_pel;
    Leer>>genero;
    Leer>>duracion;

    Leer>>dia;
    Leer>>mes;
    Leer>>clasificacion;
    Leer>>formato;

    if(id==id_aux){
        Leer.close();
        cout<<"La pelicula no se puede agregar debido a que  el Id ya existe"<<endl;
        return false;

    }
    Leer>>id;
    }
Leer.close();
return true;
}

bool buscar_pelicula(int id_aux){//funcion donde revisa si el id existe
    ifstream Leer;
    Leer.open("cartelera.txt",ios::in);
    bool encontrado=false;
    int id,num_sala,hora,asiento_disp,cant_asiento;
    string nom_pel,genero,duracion,clasificacion,formato;



    Leer>>id;
    while(!Leer.eof() && !encontrado){
        Leer>>nom_pel;
        Leer>>genero;
        Leer>>duracion;
        Leer>>num_sala;
        Leer>>hora;
        Leer>>asiento_disp;
        Leer>>cant_asiento;
        Leer>>clasificacion;
        Leer>>formato;

        if(id==id_aux){
            Leer.close();
            cout<<"Continuemos con la compra"<<endl;
            return true;


        }
        Leer>>id;
    }
    Leer.close();
    if(!encontrado){
        cout<<"Pelicula no encontrada"<<endl;
        return false;
    }



}

void actualizar_num_asientos(int id_aux){
    int id,num_sala,hora,asiento_disp,cant_asiento,asiento_disp_aux;
    string nom_pel,genero,duracion,clasificacion,formato,pelicula_aux;
    ifstream Leer("cartelera.txt",ios::in);
    ofstream aux("auxiliar.txt",ios::out);
    Leer>>id;
    while(!Leer.eof()){
        Leer>>nom_pel;
        Leer>>genero;
        Leer>>duracion;
        Leer>>num_sala;
        Leer>>hora;
        Leer>>asiento_disp;
        Leer>>cant_asiento;
        Leer>>clasificacion;
        Leer>>formato;
        if(id==id_aux){
            asiento_disp_aux=asiento_disp-1;
            aux<<id<<"  "<<nom_pel<<"  "<<genero<<"  "<<duracion<<"  "<<num_sala<<"  "<<hora<<"  "<<asiento_disp_aux<<
                    "  "<<cant_asiento<<"  "<<clasificacion<<"  "<<formato<<"  "<<endl;
        }
        else {
            aux<<id<<"  "<<nom_pel<<"  "<<genero<<"  "<<duracion<<"  "<<num_sala<<"  "<<hora<<"  "<<asiento_disp<<
                    "  "<<cant_asiento<<"  "<<clasificacion<<"  "<<formato<<"  "<<endl;
        }
        Leer>>id;
    }
    Leer.close();
    aux.close();

    remove("cartelera.txt");
    rename("auxiliar.txt","cartelera.txt");
}

int retorna_sala(int id_aux){
ifstream Leer;
Leer.open("cartelera.txt",ios::in);

int id,num_sala,hora,asiento_disp,cant_asiento;
string nom_pel,genero,duracion,clasificacion,formato;



Leer>>id;
while(!Leer.eof()){
    Leer>>nom_pel;
    Leer>>genero;
    Leer>>duracion;
    Leer>>num_sala;
    Leer>>hora;
    Leer>>asiento_disp;
    Leer>>cant_asiento;
    Leer>>clasificacion;
    Leer>>formato;

    if(id==id_aux){
        Leer.close();
        return num_sala;



    }
    Leer>>id;
}
Leer.close();

}
void modificar_asiento(int num_sala,string Sillas){


        ifstream Leer;
        ofstream Reemplazo;
        string sillas;
        int Num_salas;

        Leer.open("salas.txt",ios::in);
        Reemplazo.open("auxiliar.txt");



        Leer>>Num_salas;
        while (!Leer.eof()) {
            Leer>>sillas;
            if(Num_salas==num_sala){
                Reemplazo<<Num_salas<<" "<<Sillas<<endl;



            }else{

                Reemplazo<<Num_salas<<" "<<sillas<<endl;
            }
            Leer>>Num_salas;
        }



        Leer.close();
        Reemplazo.close();


        remove("salas.txt");
        rename("auxiliar.txt","salas.txt");

}
void cancelar_reserva(int num_sala,int id_aux){
    int fila,columna;
    if(num_sala>=1 && num_sala<=5){
       fila=9;columna=18;
    }
    else if (num_sala>=6 && num_sala<=8) {
        fila=13;columna=18;
    }
    else if (num_sala>=9 && num_sala<=10) {
        fila=7;columna=18;
    }
    else {
        cout<<"Numero de sala no existe"<<endl;
    }

    string sillas;
    int Num_salas;
    ifstream Leer;
    Leer.open("salas.txt",ios::in);
    Leer>>Num_salas;
    while (!Leer.eof()) {
        Leer>>sillas;
        if(Num_salas==num_sala){
            cout<<"La sala numero "<<num_sala<<" es"<<endl;

            break;

        }
        Leer>>Num_salas;
    }
    char matriz[fila][columna];
    Leer.close();
    int col=0;
    for (int i=0;i<(fila*columna);i++) {
        if(i%columna==0){
            col=0;

            cout<<endl;


        }
        cout<<sillas.at(i);
        matriz[i/columna][col]=sillas.at(i); //Guardar cada silla en una matriz
        col++;
    }
    cout<<endl;



    int fila_usu,columna_usu;

        cout<<"Ingrese la fila:"
              " "<<endl;cin>>fila_usu;
        cout<<"Ingrese el asiento(1-18): "<<endl; cin>>columna_usu;




    if (matriz[fila_usu][columna_usu] =='-'){
        matriz[fila_usu][columna_usu] = '+';
        cout<<"Asiento cancelado."<<endl;
        actualizar_num_asientos(id_aux);
        actualizar_venta(id_aux,-1);
        sillas="";
        for (int i=0;i<fila;i++) {
            for (int j=0;j<columna;j++) {
                sillas=sillas+matriz[i][j];

            }

        }
    modificar_asiento(num_sala,sillas);



    }
    else{
        cout<<"No puedes realizar la cancelacion, este asiento esta disponible."<<endl;

    }


}

void actualizar_venta( int id_aux, int x){
    int id,venta;

    ifstream Leer("reporte.txt",ios::in);
    ofstream aux("auxiliar.txt",ios::out);
    Leer>>id;
    while(!Leer.eof()){
        Leer>>venta;
        if(id==id_aux){

            aux<<id<<"  "<<venta+x<<endl;
        }
        else {
            aux<<id<<"  "<<venta<<endl;
        }
        Leer>>id;
    }
    Leer.close();
    aux.close();

    remove("reporte.txt");
    rename("auxiliar.txt","reporte.txt");
}



