/*		
	UNIVERSIDAD TECNICA DE COTOPAXI
TORRES SANTACRUZ CRISTIAN
*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
struct detalles{
	char hr[20], pdt[20];
	int cc, ci, pc, desc, va, tp, sum; 
};
struct datos{
	int a, pxv, nv, cap;
	char nom[20], ruta[30]; 
	struct detalles dt [10];
}d[10];
void ingresar ();
void imprimir ();
int nc, i, j;
float cont=0, sum=0;
int main(){
	ingresar ();
	imprimir ();
	getch ();
	return 0;
}
void ingresar (){
	cout<<"INGRESE EL NUMERO DE CARROS"<<endl;
	cin>>nc;
	for (int i=1; i<=nc; i++){
		fflush(stdin);
		cout<<"INGRESE EL NOMBRE Y APELLIDO DEL CHOFER ["<<i<<"]"<<endl;
		cin.getline(d[i].nom,20);
		cout<<"INGRESE LA RUTA"<<endl;
		cin.getline(d[i].ruta,30);
		cout<<"INGRESE EL ANIO"<<endl;
		cin>>d[i].a;
		cout<<"INGRESE EL PRECIO POR VIAJE"<<endl;
		cin>>d[i].pxv;
		cout<<"INGRESE EL NUMERO DE VIAJES"<<endl;
		cin>>d[i].nv;
		cout<<"INGRESE LA CAPACIDAD DE CARGA"<<endl;
		cin>>d[i].cap;
		for (int j=1; j<=d[i].nv; j++){
			fflush(stdin);
			cout<<"INGRESE LA HORA DE SALIDA Y LLEGADA ["<<j<<"]"<<endl;
			cin.getline(d[i].dt[j].hr,20);
			cout<<"INGRESE EL PRODUCTO"<<endl;
			cin.getline(d[i].dt[j].pdt,20);
			cout<<"INGRESE LA CANTIDAD DE CARGA"<<endl;
			cin>>d[i].dt[j].cc;
		}
	}
	system ("cls");
}
void imprimir (){
	cout<<endl;
	cout<<"EL NUMERO DE CARROS SON: "<<nc<<endl;
	for (int i=1; i<=nc; i++){
		fflush(stdin);
		cout<<endl;
		cout<<"EL NOMBRE Y APELLIDO DEL CHOFER ["<<i<<"]: "<<d[i].nom<<endl;
		cout<<"LA RUTA RECORRIDA: "<<d[i].ruta<<endl;
		cout<<"EL ANIO DEL CARRO: "<<d[i].a<<endl;
		cout<<"EL PRECIO BASICO POR EL VIAJE: $ "<<d[i].pxv<<endl;
		cout<<"EL NUMERO DE VIAJES DEL CHOFER: "<<d[i].nv<<endl;
		cout<<"LA CAPACIDAD DE CARGA: "<<d[i].cap<<endl;
		for (int j=1; j<=d[i].nv; j++){
			fflush(stdin);
			cout<<endl;
			cout<<"LA HORA DE SALIDA Y LLEGADA DEL VIAJE ["<<j<<"] ES: "<<d[i].dt[j].hr<<endl;
			cout<<"EL PRODUCTO LLEVADO ES: "<<d[i].dt[j].pdt<<endl;
			cout<<"LA CANTIDAD DE CARGA ES: "<<d[i].dt[j].cc<<endl;
			cout<<"EL COBRO INICIAL ES: $ "<<d[i].pxv<<endl;
			d[i].dt[j].pc=((d[i].dt[j].cc*100)/d[i].cap);
			cout<<"EL PORCENTAJE DE CARGA ES: "<<d[i].dt[j].pc<<" %"<<endl;
			if (d[i].dt[j].cc<d[i].cap){
				d[i].dt[j].desc=100*0.05;
				d[i].dt[j].tp=d[i].pxv-d[i].dt[j].desc;
				cout<<"EL DESCUENTO ES: $ "<<d[i].dt[j].desc<<endl;
			}
			if (d[i].dt[j].cc>d[i].cap){
				d[i].dt[j].va=100*0.1;
				d[i].dt[j].tp=d[i].pxv+d[i].dt[j].va;
				cout<<"EL VALOR ADICIONAL ES: $ "<<d[i].dt[j].va<<endl;
			}
			if (d[i].dt[j].cc==d[i].cap){
				d[i].dt[j].tp=d[i].pxv;
			}
			cout<<"EL PAGO TOTAL ES: $ "<<d[i].dt[j].tp<<endl;
			cont=cont+d[i].dt[j].tp;
		}
	}
	cout<<endl;
	cout<<"LA SUMA TOTAL DE LOS VIAJES DE LOS CHOFERES ES: $ "<<cont<<endl;
}
