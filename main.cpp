//Librerias
#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;

//Declaracion de funciones
void menu();//menu principal
void mcliente();//mostrar clientes
void addcliente();//
void eliminarcliente();//
void modcliente();
void clear(); //limpia la pantalla 
void errord(); //evita que se ingrese datos incorrectos

void cliente(){
	
	clear();
	cout<<"Clientes Registrados"<<endl;
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
    
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    }
    
    string queryText;
	cout<<endl;
	string idt;
	cin.ignore();
	cout<<"Escriba el ID de la cuenta que desea saldo: ";
	getline(cin, idt);
	string Text;
	string datos;
	int Result;//number which will contain the result	
	queryText = "SELECT * FROM cuentas WHERE id ='"+ idt +"'" ;
    mysql_query(conn, queryText.c_str());
	res = mysql_use_result(conn);
	printf("Id \t Numero de cuenta\t Nombre\t Apellidos \t\t Saldo\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t %s\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
		
		
		
	Text = row[4];//string containing the number

	}
	mysql_free_result(res);
	
	
	
   cout<<Text<<endl;
   string::size_type sz;
   float b=100.25;
 
double moon = atof(Text.c_str());
   
double resultado =moon + b ; // concatenar
    cout << resultado << '\n'; // mostrar
	
	stringstream ss;    
  	ss<<resultado;       
    string Saldo= ss.str();	
    
	queryText = "UPDATE cuentas SET saldo = '"+Saldo+"' WHERE cuentas.id = '"+idt+"'" ;
    mysql_query(conn, queryText.c_str());
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	mysql_close(conn);
	system("pause");

}	

int main(int argc, char** argv) {
	system("color 8F");//color de fondo y texto	
	
	menu();
	return 0;
}

//funcion menu
void menu()
{
		int a;
	
		do{
		
		clear();		
		cout << "************************************" << endl;		
		cout << "*           Menu Principal         *" << endl;		
		cout << "************************************" << endl;
		cout<<endl;
		cout<<endl;		
	    cout << "1.Mostrar clientes" << endl;	    
	    cout << "2.Agregar Nuevo Cliente" << endl;	    
	    cout << "3.Eliminar cuenta" << endl;
		cout << "4.Editar datos del cliente" << endl;	    
		cout << "5.Salir" << endl;	   
	    cout<<endl;	
	    cout << "Elija un opcion: ";
	    cin >> a;
	    errord();
    } while(a < 1 || a > 6);
	
	switch(a)
	{
		
		case 1:
			cout<<endl;
			mcliente();
			break;
		case 2:
			cout<<endl;
			addcliente();
			break;
		case 3:
			cout<<endl;
			eliminarcliente();		
			break;
		case 4:
			cout<<endl;
			cliente();
		//	modcliente();
		//	modcliente();		
			break;
		case 5:
			cout<<endl;
			cout << "Que pase un buen dia!" << endl;
			system("pause");
			break;
						
	}
		
}

//funcion mostrar cliente
void mcliente()
{
	clear();
	cout<<"Clientes Registrados"<<endl;
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
    
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    }else{
	
    
    //Comando de consulta, se muestran los resultados
    mysql_query(conn, "SELECT * FROM cuentas");
	res = mysql_use_result(conn);
	printf("Id \t Numero de cuenta\t Nombre\t Apellidos \t\t Saldo\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t %s\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4]), row[5];
	}
	mysql_free_result(res);
	mysql_close(conn);
    } 
  
	system("pause");
	menu();
}

void addcliente(){
	
	
	clear();
	cout<<"Agregar Nuevo Cliente"<<endl;
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
    
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    } else{
   
string queryText;
string num;
string nombre;
string apellido;
string saldo;

cin.ignore();
cout << "Ingrese numero de cuenta: ";
getline(cin, num);

cin.ignore();
cout << "Ingrese los Nombres del cliente: ";
getline(cin, nombre);

cin.ignore();
cout << "Ingrese los Apellidos del cliente: ";
getline(cin, apellido);

cin.ignore();
cout << "Ingrese Saldo Inicial: "; 
getline(cin, saldo);

queryText = "INSERT INTO cuentas(id, numcuenta, nombre, apellido, saldo) VALUES(NULL ,'"+ num +"', '"+ nombre +"','"+ apellido +"', '"+ saldo +"')" ;
mysql_query(conn, queryText.c_str());

}

mysql_close(conn);	
sleep(3);
cout<<"Registro Agregado Correctamente"<<endl;
system("pause");
menu();
}

void eliminarcliente(){
	
	clear();
	cout<<"Clientes Registrados"<<endl;
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
    
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    }
    
    //Comando de consulta, se muestran los resultados
     mysql_query(conn, "SELECT * FROM cuentas");
	res = mysql_use_result(conn);
	printf("Id \t Numero de cuenta\t Nombre\t Apellidos \t\t Saldo\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t %s\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
	}
	mysql_free_result(res);
	
	string queryText;
	cout<<endl;
	string idt;
	cin.ignore();
	cout<<"Escriba el ID de la cuenta que desea Eliminar: ";
	getline(cin, idt);
	
	int a;
	cout<<"Esta seguro que desea eliminar el cliente?"<<endl;
	cout<<"1. Si       2. No"<<endl;
	cin>>a; 	
	
	if(a==1){
		
	queryText = "DELETE FROM cuentas WHERE cuentas.id = '"+ idt +"'" ;
    mysql_query(conn, queryText.c_str());
	
    sleep(3);
	cout<<"Se ha Eliminado Correctamente"<<endl;	
		
	}else{
		
		eliminarcliente();
	}	
	
	mysql_close(conn);
	system("pause");
	mcliente();
}

void modcliente(){
	
	clear();
	cout<<"Atencion!"<<endl;
	cout<<"Solo se puede modificar Nombres y Apellidos del cliente."<<endl;
	system("pause");
	clear();
	
	cout<<"Clientes Registrados"<<endl;
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
    
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    }
    
    //Comando de consulta, se muestran los resultados
     mysql_query(conn, "SELECT * FROM cuentas");
	res = mysql_use_result(conn);
	printf("Id \t Numero de cuenta\t Nombre\t Apellidos \t\t Saldo\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t %s\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
	}
	mysql_free_result(res);
	cout<<endl;
	
	int aux;
	string queryText;
	string idt;
	string nom;
	string apell;
	
	cin.ignore();
	cout<<"Escriba el ID del cliente que desea modificar: ";
	getline(cin, idt);
	
	cout<<"Desea modificar Nombres o Apellidos del cliente?"<<endl;
	cout<<"1. Nombres     2. Apellidos"<<endl;
	cin>>aux;
	
	if(aux==1){
		
	cin.ignore();
	cout<<"Ingrese los nuevos valores para Nombres del cliente: ";
	getline(cin, nom);
	queryText = "UPDATE cuentas SET nombre = '"+ nom +"' WHERE cuentas.id = '"+ idt +"';" ;
    mysql_query(conn, queryText.c_str());
	}else{
		
	cin.ignore();
	cout<<"Ingrese los nuevos valores para Apellidos del cliente: ";
	getline(cin, apell);
	queryText = "UPDATE cuentas SET apellido = '"+ apell +"' WHERE cuentas.id = '"+ idt +"';" ;
    mysql_query(conn, queryText.c_str());
	}
	
    sleep(3);
	cout<<"Se ha Modificado Correctamente"<<endl;
		
	mysql_close(conn);
	system("pause");
	mcliente();
	
	
	
	
}

void clear() //Funcion que permite limpiar la pantalla
{
	
	system("cls");
}

void errord() //funcion que evita que se ingrese datos incorrectos
{
		//Ciclo while paraevitar datos incorrectos
		while(cin.fail()){

		//Limpia el buffer de los datos ingresados
		cin.clear();

		//Ignora los primeros 1000 caracteres o en este caso los numeros
		cin.ignore(1000,'\n');

		}
}


