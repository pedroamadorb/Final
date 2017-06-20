#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
 
// Namespaces
using namespace std;

string op[3] = {"Abierto", "Cerrado", "Desocupado"};
 
// Crear clases contenidas
struct TPunto
{
	float x;
    float y;
};
 
struct Lugar
{
	string name;
};

struct Estado
{
	string state;
};
 
 
// Creamos la clase contenedor
class CMapa
{
	string nombreArchivo;
	string ciudad;
	vector<TPunto> listaPuntos;
	vector<Lugar> listaLugares;
	vector<Estado> listaEstados;
 
public:
 
	// Declaracion de constructores
	CMapa()
	{
		ciudad = "Lima";
		nombreArchivo = "datos.txt";
	}
 
	CMapa(string ciudad, string nombreArchivo)
	{
		this->ciudad = ciudad;
		this->nombreArchivo = nombreArchivo;
	}
 
	// Metodos de Procesamientos
	void agregarPunto(string name, float x, float y,string state)
	{
		listaLugares.push_back({ name });
		listaPuntos.push_back({ x,y });
		listaEstados.push_back({ state });
		grabarArchivo();
	}
 
	void listarPuntos()
	{
		int i = 0;
		while (i <= listaLugares.size() - 1) {
			cout << "Lugar " << listaLugares[i].name << "  Punto  x, y = (" << listaPuntos[i].x << ", " << listaPuntos[i].y << ")  Estado " << listaEstados[i].state<< endl;
			i = i + 1;
		}
	}
 
	void eliminarPuntoPorNombre(string name)
	{
		for (int i = listaLugares.size() - 1; i >= 0; i--){
			if (listaLugares[i].name == name){
				listaLugares.erase(listaLugares.begin() + i);
				listaPuntos.erase(listaPuntos.begin() + i);
			}
		}
		grabarArchivo();
	}
 
	void grabarArchivo()
	{
		// Creando el archivo
		ofstream archivo(nombreArchivo);
		archivo << "posX, posY" << endl;
		for (auto punto : listaPuntos)
			archivo << punto.x << ", " << punto.y << endl;
		archivo.close();
	}
 
	void listarPuntosMenos10()
	{
		int j = 0;
		double val;
		while (j <= listaLugares.size() - 1) 
		{
			val = sqrt(listaPuntos[j].x*listaPuntos[j].x + listaPuntos[j].y*listaPuntos[j].y);
			if (val < 10)
			{
				cout << "Distancia = ( " << val << ")  Lugar = <" << listaLugares[j].name << ">  Punto  x, y = (" << listaPuntos[j].x << ", " << listaPuntos[j].y << ")  Estado " << listaEstados[j].state<< endl;
			}
			j = j + 1;
			val = 0;
		}
	}
 
	void DistanciaPromedio()
	{
 
		int j = 0;
		double val=0;
		while (j <= listaLugares.size() - 1)
		{
			val = val + sqrt(listaPuntos[j].x*listaPuntos[j].x + listaPuntos[j].y*listaPuntos[j].y);
			j = j + 1;
		}
		double prom = val / (listaLugares.size());
		cout << "Distancia Promedio= ( " << prom << ") " << endl;
	}
 
	void DistanciaLejanos()
	{
 
		int j = 0;
		int a = 0;
		double val;
		double cont=0;
		while (j <= listaLugares.size() - 1)
		{
			val = sqrt(listaPuntos[j].x*listaPuntos[j].x + listaPuntos[j].y*listaPuntos[j].y);
			if (val > cont)
			{
				cont = val;
				a = j;
			}
			j = j + 1;
		}
 
		float x1 = listaPuntos[a].x;
		float y1 = listaPuntos[a].y;
		
        cout << "Primer lugar más lejano = <" << listaLugares[a].name << ">  Punto  x, y = (" << listaPuntos[a].x << ", " << listaPuntos[a].y << ")  Estado " << listaEstados[a].state<< endl;
			
		int i = 0;
		int b = 0;
		double cont1=0;
		while (i <= listaLugares.size() - 1)
		{
			val = sqrt(listaPuntos[i].x*listaPuntos[i].x + listaPuntos[i].y*listaPuntos[i].y);
			if (val > cont1 && i != a)
			{ 
				cont1 = val;
				b = i;
			}
			i = i + 1;
		}
 
		float x2 = listaPuntos[b].x;
		float y2 = listaPuntos[b].y;
		
		cout << "Segundo lugar más lejano = <" << listaLugares[b].name << ">  Punto  x, y = (" << listaPuntos[b].x << ", " << listaPuntos[b].y << ")  Estado " << listaEstados[b].state<< endl;

 
		double dist = val = sqrt((x1-x2)*(x1 - x2) + (y1-y2)*(y1 - y2));
		cout << "Distancia de los puntos más lejanos = ( " << dist << ")" << endl;
	}
 
	void DistanciaCercanos()
	{
 
		int j = 0;
		int a = 0;
		double val;
		double cont = sqrt(listaPuntos[0].x*listaPuntos[0].x + listaPuntos[0].y*listaPuntos[0].y);
		while (j <= listaLugares.size()-1)
		{
			val = sqrt(listaPuntos[j].x*listaPuntos[j].x + listaPuntos[j].y*listaPuntos[j].y);
			if (val < cont)
			{
				cont = val;
				a = j;
			}
			j = j + 1;
		}
	    float x1 = listaPuntos[a].x;
		float y1 = listaPuntos[a].y;
		
        cout << "Primer lugar más cercano = <" << listaLugares[a].name << ">  Punto  x, y = (" << listaPuntos[a].x << ", " << listaPuntos[a].y << ")  Estado " << listaEstados[a].state<< endl;
	

		int i = 0;
		int b = 0;
		double cont1 = sqrt(listaPuntos[0].x*listaPuntos[0].x + listaPuntos[0].y*listaPuntos[0].y);
		
		while (i <= listaLugares.size()-1)
		{
			val = sqrt(listaPuntos[i].x*listaPuntos[i].x + listaPuntos[i].y*listaPuntos[i].y);
			if (cont1 > val && i != a)
			{
				cont1 = val;
				b = i;
			}
			i = i + 1;
		}
 
		float x2 = listaPuntos[b].x;
		float y2 = listaPuntos[b].y;
		
		cout << "Segundo lugar más cercano = <" << listaLugares[b].name << ">  Punto  x, y = (" << listaPuntos[b].x << ", " << listaPuntos[b].y << ")  Estado " << listaEstados[b].state<< endl;

 
		double dist = val = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		cout << "Distancia de los puntos más cercanos = ( " << dist << ")" << endl;
	}
	
	void eliminarPuntoPorEstado(string state)
	{
		for (int i = listaLugares.size() - 1; i >= 0; i--){
			if (listaEstados[i].state == state){
				listaLugares.erase(listaLugares.begin() + i);
				listaPuntos.erase(listaPuntos.begin() + i);
				listaEstados.erase(listaEstados.begin() + i);
			}
		}
		grabarArchivo();
	}
	
	void listarPuntosPorEstado()
	{
		cout << "Lugares Abiertos:"<< endl;
		for (int i = listaLugares.size() - 1; i >= 0; i--){
			if (listaEstados[i].state == op[0]){
				cout << "Lugar " << listaLugares[i].name << "  Punto  x, y = (" << listaPuntos[i].x << ", " << listaPuntos[i].y << ")" << endl;
			
			}
		}
		cout<< endl;
		cout << "Lugares Cerrados:"<< endl;
		for (int i = listaLugares.size() - 1; i >= 0; i--){
			if (listaEstados[i].state == op[1]){
				cout << "Lugar " << listaLugares[i].name << "  Punto  x, y = (" << listaPuntos[i].x << ", " << listaPuntos[i].y << ")" << endl;
			
			}
		}
		cout<< endl;
		cout << "Lugares Desocupado:"<< endl;
		for (int i = listaLugares.size() - 1; i >= 0; i--){
			if (listaEstados[i].state == op[2]){
				cout << "Lugar " << listaLugares[i].name << "  Punto  x, y = (" << listaPuntos[i].x << ", " << listaPuntos[i].y << ")" << endl;
			
			}
		}
		cout<< endl;
		
	}
};
 
	int menu()
	{
		int opcion = 0;
		do
		{
			system("clear");
			cout << "MENU" << endl;
			cout << string(4, '~') << endl << endl;
 
			cout << "1. Agregar una nueva posicion" << endl;
			cout << "2. Eliminar posicion por nombre" << endl;
			cout << "3. Listar 100 primeros puntos" << endl;
			cout << "4. Listar los ubicados a menos de 10 metros" << endl;
			cout << "5. Calcular la distancia promedio entre cada punto" << endl;
			cout << "6. Determinar la distancia entre los puntos más lejanos" << endl;
			cout << "7. Determinar la distancia más corta entre los puntos" << endl;
			cout << "8. Eliminar posicion por estado" << endl;
			cout << "9. Listar coordenadas por estado" << endl;
 
			cout << "0. Para salir" << endl << endl;
			cout << "Opcion : ";
			cin >> opcion;
		} while (opcion < 0 || opcion > 9);
 
		return opcion;
	}
 
	// Programa Principal
	int main()
	{
		CMapa mapa;         // Mapa de Lima
 
		int opcion = 0;
		do
		{
			opcion = menu(); // Opcion del menu
			float x, y;
			string name;
			string state;
 
			// Creamos un switch de opciones
			switch (opcion)
			{
			case 1:     // Insertar Puntos
				system("clear");
				int n;
				cout << "Ingrese el nombre del lugar: "; cin >> name;
				cout << "Ingrese el valor de X: "; cin >> x;
				cout << "Ingrese el valor de Y: "; cin >> y;
				cout << "Ingrese el estado del lugar (1=Abierto, 2=Cerrado, 3=Desocupado): "; cin >> n;
				state=op[n-1];
				mapa.agregarPunto(name, x, y,state);
				break;
			case 2:     // Eliminar Puntos
				system("clear");
				cout << "Ingrese el nombre del lugar a borrar : "; cin >> name;
				mapa.eliminarPuntoPorNombre(name);
				cin.get();
				break;
			case 3:     // Listar Puntos
				system("clear");
				mapa.listarPuntos();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				break;
			case 4:     // Listar Puntos de Distancias Menos de 10
				system("clear");
				mapa.listarPuntosMenos10();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				break;
			case 5:     // Distancia Promedio entre Puntos
				system("clear");
				mapa.DistanciaPromedio();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				break;
			case 6:     // Distancias entre los más lejanos
				system("clear");
				mapa.DistanciaLejanos();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				break;
			case 7:     // Distancias entre los más cercanos
				system("clear");
				mapa.DistanciaCercanos();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				break;
			case 8:     // Eliminar Puntos
				system("clear");
				cout << "Ingrese el estado del lugar a borrar : "; cin >> state;
				mapa.eliminarPuntoPorEstado(state);
				cin.get();
				break;
			case 9:     // Eliminar Puntos
				system("clear");
				mapa.listarPuntosPorEstado();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				break;
			}
 
		} while (opcion != 0);
 
		return 0;
	}
