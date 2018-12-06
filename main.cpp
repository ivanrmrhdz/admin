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
void addcliente();//agregar nuevo cliente
void eliminarcliente();//eliminar cliente
void modcliente();//modificar datos de cliente
void clear(); //limpia la pantalla 
void errord(); //evita que se ingrese datos incorrectos
void validar();//validacion de cuenta de cliente
void validaradmin();//validacion de admin
int menuusuario(string id);//menu de cliente
int abonar(string id);//abonar a la cuenta
int retirar(string id);//retirar de la cuenta
int estado(string id);//ver estadop de cuenta

//funcion principal
int main(){
	
	system("color 8F");//color de fondo y texto	
	clear();
	//Se muestra un menu al inciar el programa
	int n;
	do{
	cout<<"---------------------------"<<endl;
	cout<<"  Banco de America Central "<<endl;
	cout<<"---------------------------"<<endl;
	cout<<endl;
	cout<<"En que modo desea utilizar la consola?"<<endl;
	cout<<"1. Modo Cliente"<<endl;
	cout<<"2. Modo Administrador"<<endl;
	cout<<"3. Salir del sistema"<<endl;
	cout<<endl;
	cout << "Elija un opcion: ";
	cin >> n;
    }while(n < 1 || n > 4);

    //Dependiendo de la opciono que elija se llama a una funcion 
	switch(n)
	{		
		case 1:
			cout<<endl;
			validar();
			break;
		case 2:
			cout<<endl;
			validaradmin();
			break;
		case 3:
			cout<<endl;
			cout << "Que pase un buen dia!" << endl;
			system("pause");		
			break;
	
}
return 0;
}

//Validacion de la clave de administrador
void validaradmin(){
	
	clear();
	
	//se pide una clave preestablecida para el acceso como administrador 
	string clave;
	
	cout<<"BANCO DE AMERICA CENTRAL"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Ingrese la Clave de Administrador: ";
	cin.ignore();
	getline(cin, clave);
	
	//Se comprueba que sea la clave correcta
	if(clave=="admin"){
		cout<<"Clave Correcta"<<endl;
		system("pause");
		menu();
	}else{		
		cout<<"Clave Incorrecta, Intente de nuevo."<<endl;
		system("pause");
		validaradmin();
	}
}

//funcion menu
void menu(){
	
		int a;
	
		do{
		
		clear();		
		cout << "************************************" << endl;		
		cout << "          MODO ADMINISTRADOR        " << endl;		
		cout << "************************************" << endl;
		cout<<endl;
		cout<<endl;		
	    cout << "1.Mostrar clientes" << endl;	    
	    cout << "2.Agregar Nuevo Cliente" << endl;	    
	    cout << "3.Eliminar cuenta" << endl;
		cout << "4.Editar datos del cliente" << endl;	 
		cout << "5.Salir al Menu Inicial" << endl;	    
		cout << "6.Salir del sistema" << endl;	   
	    cout<<endl;	
	    cout << "Elija un opcion: ";
	    cin >> a;
	    errord();
    } while(a < 1 || a > 7);
	
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
		    modcliente();		
			break;
		case 5:
			cout<<endl;
		    main();		
			break;
		case 6:
			cout<<endl;
			cout << "Que pase un buen dia!" << endl;
			system("pause");
			break;
						
	}
		
}

//funcion mostrar cliente
void mcliente(){
	
	clear();
	cout<<"Clientes Registrados"<<endl;//Titulo en pantalla
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
	printf("Id \t Numero de cuenta\t Nombre\t\t\t\t Apellidos \t\t\t\t Saldo\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t\t %s\t\t\t %s\t\t\t $%s\n", row[0], row[1], row[2], row[3], row[4]);//Se muestran los datos de la tabla
		
	}
	mysql_free_result(res);
	mysql_close(conn);//se cierra la conexion
    } 
    //Press enter y regresa al menu
	system("pause");
	menu();
}

//funcion para agregar nuevo cliente
void addcliente(){
		
	clear();
	cout<<"Agregar Nuevo Cliente"<<endl;//Titulo en pantalla
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
   
      //Se usan strings para podes usar las variables en la sentencia SQL  
      string queryText;
      string num;
      string nombre;
      string apellido;
      string saldo;
      //Se piden los datos del cliente
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
    //Sentencia para guardarlos en la tabla
      queryText = "INSERT INTO cuentas(id, numcuenta, nombre, apellido, saldo) VALUES(NULL ,'"+ num +"', '"+ nombre +"','"+ apellido +"', '"+ saldo +"')" ;
      mysql_query(conn, queryText.c_str());

}

   mysql_close(conn);//se cierra la conexion	
   sleep(3);//pausa de 3 segundos
   cout<<"Registro Agregado Correctamente"<<endl;
   
system("pause");
menu();
}

//funcion para eliminar clientes existentes
void eliminarcliente(){
	
	clear();
	cout<<"Clientes Registrados"<<endl;//titulo en pantalla
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
	    
    //Comando de consulta, se muestran los registros para poder ver cual se eliminara 
     mysql_query(conn, "SELECT * FROM cuentas");
	res = mysql_use_result(conn);
	printf("Id \t Numero de cuenta\t Nombre\t\t Apellidos \t\t Saldo\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t\t %s\t\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4]);//muestra los datos de la tabla
	}
	mysql_free_result(res);
	
	string queryText;//para el comando sql
	string idt;//para identifica el registro que se eliminara 
	
	//Se pide al usuario que ingrese ID de cuenta a eliminar
	cout<<endl;
	cin.ignore();
	cout<<"Escriba el ID de la cuenta que desea Eliminar: ";
	getline(cin, idt);
	//El usuario confirma si quiere eliminar 
	int a;
	cout<<"Esta seguro que desea eliminar el cliente?"<<endl;
	cout<<"1. Si       2. No"<<endl;
	cin>>a; 	
	if(a==1){
	//Se ejecuta el comando para eliminar	
	queryText = "DELETE FROM cuentas WHERE cuentas.id = '"+ idt +"'" ;
    mysql_query(conn, queryText.c_str());
	
    sleep(3);
	cout<<"Se ha Eliminado Correctamente"<<endl;	
		
	}else{
	//se reinicia la funcion	
		eliminarcliente();
	}	
	
}
	mysql_close(conn);
	system("pause");
	mcliente();
}

//funcion para modificar cliente
void modcliente(){
	
	clear();
	/*Se avisa que solo se pueden modificar el nombre y los apellidos del cliente,
	esto porque el id y numero de cuenta son unicos, y el saldo se controla por el cliente mismo*/
	cout<<"Atencion!"<<endl;
	cout<<"Solo se puede modificar Nombres y Apellidos del cliente."<<endl;
	system("pause");
	clear();//limpia consola y sigue
	
	cout<<"Clientes Registrados"<<endl;//titulo en pantalla
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
    	   
    //Comando de consulta, se muestran la tabla para que se pueda seleccionar el id del resitro a modificar
     mysql_query(conn, "SELECT * FROM cuentas");
	res = mysql_use_result(conn);
	printf("Id \t Numero de cuenta\t Nombre\t\t Apellidos \t\t Saldo\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t\t %s\t\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4]);//muestra los datos de la tabla
	}
	mysql_free_result(res);
	cout<<endl;
	//dclaracion de variables a usar 
	int aux;
	string queryText;
	string idt;
	string nom;
	string apell;
	
	//se pide el id de cuenta que se desea modificar 
	cin.ignore();
	cout<<"Escriba el ID del cliente que desea modificar: ";
	getline(cin, idt);
	//selecciona una de esas opciones 
	cout<<"Desea modificar Nombres o Apellidos del cliente?"<<endl;
	cout<<"1. Nombres     2. Apellidos"<<endl;
	cin>>aux;
	
	if(aux==1){
	//opcion 1, Modifica los Nombres del cliente
	cin.ignore();
	cout<<"Ingrese los nuevos valores para Nombres del cliente: ";//se piden los nuevos valores 
	getline(cin, nom);
	queryText = "UPDATE cuentas SET nombre = '"+ nom +"' WHERE cuentas.id = '"+ idt +"';" ;//se ejecuta el comando sql
    mysql_query(conn, queryText.c_str());
	}else{
	//opcion 2, Modifica los Apellidos del cliente	
	cin.ignore();
	cout<<"Ingrese los nuevos valores para Apellidos del cliente: ";//se piden los nuevos valores 
	getline(cin, apell);
	queryText = "UPDATE cuentas SET apellido = '"+ apell +"' WHERE cuentas.id = '"+ idt +"';" ;//se ejecuta el comando sql
    mysql_query(conn, queryText.c_str());
	}
	
    sleep(3);//pausa de 3 segundos
	cout<<"Se ha Modificado Correctamente"<<endl;
		
	}
	mysql_close(conn);
	system("pause");
	mcliente();
	
	
	
	
}

/*
En la parte de cliente se trabaja con funciones int para que se pueda mantener el ID de la cuenta que se verifica al 
ingresar el numero de cuenta en la funcion de validar.
*/

//Validacion de la existencia de la cuenta de clientes 
void validar(){
	
	clear();
		
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
   
    string id;//varible para sacar el id de la cuenta 
   

	 //Se pide el numero de cuenta al usuario   	
 	string cuenta;
	cin.ignore();
	cout<<"Ingrese numero de cuenta: "; 

	getline(cin, cuenta);
	
	//Se comprueba si existe en la tabla un registro con ese numero de cuenta 
    string queryText;
    queryText="SELECT * FROM cuentas WHERE numcuenta='"+cuenta+"'"; 
    mysql_query(conn, queryText.c_str());
    res = mysql_use_result(conn);
	   
if ((row = mysql_fetch_row(res)) != NULL){
	row[0], row[1], row[2], row[3], row[4];
	
	 id=row[0];//se asigna el id a la variable
	 menuusuario(id);//llama a la funcion de menu y manda el id
}else{

//sigue pidiendo el numero hasta que ingrese uno correcto
   cout<< "Numero de cuenta incorrecto"<<endl;
   cout<<"Intente de nuevo"<<endl;
   system("pause");
   validar(); //reinicia la funcion

}
} 
	mysql_close(conn);//se cierra la conexion	
}

//Menu para el modo CLIENTE
int menuusuario(string id){
	
	int a;//variable para el menu
	string num=id;//id que viene desde la funcion validar y pasa a las otras funciones de cliente 
	//se usan para dar la bienvenida 
	string nombre;
    string apellido;
    
    //Conexion con SQL
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
 	
	//Se usa el id que se recibe para obtener el nombre y apellido del cliente 
   string queryText;
   queryText="SELECT * FROM cuentas WHERE cuentas.id='"+num+"'"; 
   mysql_query(conn, queryText.c_str());
   res = mysql_use_result(conn);

    while ((row = mysql_fetch_row(res)) != NULL){
	row[0], row[1], row[2], row[3], row[4];
	
//Se asignan los valores de la tabla a las variables string 
	 nombre=row[2];
	 apellido=row[3];
	 
    }   	
}
//Menu de Clientes 
    	do{
		clear();		
		cout << "------------------------------------" << endl;		
		cout <<  "Bienvenido "<<nombre<<" "<<apellido<<endl;		
		cout << "------------------------------------" << endl;
		cout<<endl;
		cout<<"Menu Principal"<<endl;
		cout<<endl;		
	    cout << "1.Ver Estado de cuenta" << endl;	    
	    cout << "2.Abonar a la cuenta" << endl;	    
	    cout << "3.Retirar dinero de la cuenta" << endl; 
		cout << "4.Salir al Menu Inicial" << endl; 
		cout << "5.Salir del Sistema" << endl;	   
	    cout<<endl;	
	    cout << "Elija un opcion: ";
	    cin >> a;
	    errord();
    } while(a < 1 || a > 6);
	
	//Para cada opcion, a la funcion correspondiente se le envia el ID de la cuenta que se esta usando
	switch(a)
	{
		
		case 1:
			cout<<endl;
			estado(num);
			break;
		case 2:
			cout<<endl;
			abonar(num);
			break;
		case 3:
			cout<<endl;
			retirar(num);
			break;
		case 4:
			cout<<endl;
			main();
			break;
		case 5:
			cout<<endl;
			cout << "Que pase un buen dia!" << endl;
			system("pause");
			break;
						
	}
	mysql_close(conn);
	return 0;
}

//Funcion para abonar a la cuenta
int abonar(string id){
	
	clear();
	cout<<"Abonar Dinero a la Cuenta"<<endl;//titulo en pantalla
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
    
	//Variables necesarias
    string queryText;
    string idt=id;
	string Text;
	string datos;
    string nombre;
    
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    }else{
    //Proceso para abonar a la cuenta
	    	
   
    //se hace una consulta para poder obtener el saldo de la cuenta
	queryText = "SELECT * FROM cuentas WHERE id ='"+ idt +"'" ;
    mysql_query(conn, queryText.c_str());
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL){
		 row[0], row[1], row[2], row[3], row[4];
	nombre = row[2];			
	Text = row[4];//se asigna el saldo a la variable
	}
	mysql_free_result(res);
		
	cout<<nombre<<" Su Saldo Actual es de: $";
    cout<<Text<<endl;//Se muestra el saldo actual de la cuenta
   
   
    float b;//variable que almacena la cantidad a depositar
    cout<<endl;
    cout<<"Cuanto desea abonar a su cuenta?: $";
    cin>>b;
 
   double sal = atof(Text.c_str());//Se convierte de String a double
   
   double resultado =sal + b ; //Hace la suma

    cout<<"Su saldo actual es de: $";
    cout << resultado << '\n'; //Muestra el resultado de la suma, es decir, el nuevo saldo
	
	//Se convierte el resultado a string para poder actualizar la tabla
	stringstream ss;    
  	ss<<resultado;       
    string Saldo= ss.str();	
    
	queryText = "UPDATE cuentas SET saldo = '"+Saldo+"' WHERE cuentas.id = '"+idt+"'" ;//se actualiza el registro en la tabla con el nuevo saldo
    mysql_query(conn, queryText.c_str());
	
}
	mysql_close(conn);
	//press enter y regresa al menu
	system("pause");
	menuusuario(idt);
return 0;
}

//Funcion para retirar dinero de la cuenta	
int retirar(string id){
		
	clear();
	cout<<"Retirar fondos de su cuenta"<<endl;//titulo en pantalla
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
     
	//Variables necesarias
    string queryText;
    string idt=id;
	string Text;
	string datos;
	string nombre;
	
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    }else{
	//Proceso para retirar dinero de la cuenta	
   
    //se hace una consulta para poder obtener el saldo de la cuenta
	queryText = "SELECT * FROM cuentas WHERE id ='"+ idt +"'" ;
    mysql_query(conn, queryText.c_str());
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL){
		 row[0], row[1], row[2], row[3], row[4];
		 
	nombre = row[2];		
	Text = row[4];//se asigna el saldo a la variable
	}
	mysql_free_result(res);
	
	cout<<nombre<<" Su Saldo Actual es de: $";
    cout<<Text<<endl;//Se muestra el saldo actual de la cuenta
   
   float b;//variable que almacena la cantidad a depositar
   cout<<endl;
   cout<<"Cuanto desea retirar de su cuenta?: $";
   cin>>b;//
 
   double sal = atof(Text.c_str());//se convierte el saldo a double
   
   double resultado =sal - b ;//hace la resta

    cout<<"Su saldo actual es de: $";
    cout << resultado << '\n'; //muestra el resultado de la resta, es decir, el nuevo valor par saldo
	//se convierte el resultado a string para poder actualizar la tabla
	stringstream ss;    
  	ss<<resultado;       
    string Saldo= ss.str();	
    queryText = "UPDATE cuentas SET saldo = '"+Saldo+"' WHERE cuentas.id = '"+idt+"'" ;//comando para actualizar la tabla
    mysql_query(conn, queryText.c_str());
}
	mysql_close(conn);
	//press enter y regresa al menu
	system("pause");
	menuusuario(idt);
return 0;
}	

//Funcion para ver el estado de cuenta
int estado(string id){
	
	clear();
	cout<<"Estado de Cuenta"<<endl;//titulo en pantalla
	cout<<endl;
	
	//conexion con MySQL y la base de datos
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","bancos",0,0,0);
     string queryText;
    string idt=id;
    if(conn==NULL)
    {  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");        
    }else{
   	
    //se hace una consulta que muestra los datos solo de un registro
	queryText = "SELECT * FROM cuentas WHERE id ='"+ idt +"'" ;
    mysql_query(conn, queryText.c_str());
    printf("Id \t Numero de cuenta\t Nombre\t\t Apellidos \t\t Saldo\n");//titulo de campos
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t\t %s\t\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4]);//se  uestran los datos de la tabla
	}	
    mysql_free_result(res);	
	}
	mysql_close(conn);
	//press enter y regresa al menu
	system("pause");
	menuusuario(idt);
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


