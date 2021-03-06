// Wrapping_class.cpp : Defines the exported functions for the DLL application.


#include "stdafx.h"
#include <string>
#include <fstream>
#include "C:\Users\Eduardo Zepeda\Desktop\Proyecto_gm_final_parte1\mapa_Frontend2\mapa_Frontend2\mapa_Frontend\mapa_Frontend\Airport.h"
#include "C:\Users\Eduardo Zepeda\Desktop\Proyecto_gm_final_parte1\mapa_Frontend2\mapa_Frontend2\mapa_Frontend\mapa_Frontend\Airport.cpp"
#include "C:\Users\Eduardo Zepeda\Desktop\Proyecto_gm_final_parte1\mapa_Frontend2\mapa_Frontend2\mapa_Frontend\mapa_Frontend\Route.h"
#include "C:\Users\Eduardo Zepeda\Desktop\Proyecto_gm_final_parte1\mapa_Frontend2\mapa_Frontend2\mapa_Frontend\mapa_Frontend\Route.cpp"
#include "C:\Users\Eduardo Zepeda\Desktop\Proyecto_gm_final_parte1\mapa_Frontend2\mapa_Frontend2\mapa_Frontend\mapa_Frontend\Grafo.h"
#include "C:\Users\Eduardo Zepeda\Desktop\Proyecto_gm_final_parte1\mapa_Frontend2\mapa_Frontend2\mapa_Frontend\mapa_Frontend\Grafo.cpp"

using namespace std;

extern "C" __declspec(dllexport) int add_airport(char *id,char *country, char *num_routes, char *longitude, char *latitude) {
	Airport airport;
	airport.add_Airport(id,country,num_routes, latitude, longitude);
	return 1;
}

extern "C" __declspec(dllexport) void update_airport(char *_id, char *id, char *country, char *num_routes, char *latitude, char *longitude) {
	Airport airport;
	Airport nuevo(id, country, num_routes, latitude, longitude);
	airport.update_airport(_id, nuevo);
}

extern "C" __declspec(dllexport) void delete_airport(char *_id) {
	Airport airport;
	airport.delete_airport(_id);
}


extern "C" __declspec(dllexport) double get_latitude(char *id) {
	Airport airport;
	double latitude = airport.getLatititude(id);
	return latitude;
}

extern "C" __declspec(dllexport) double get_longitude(char *id) {
	Airport airport;
	double longitude = airport.getLongitude(id);
	return longitude;
}

extern "C" __declspec(dllexport) void add_route(char *id,char *origin, char *destination, char *distance) {
	Route route;
	route.add_Routes(id,origin, destination, distance);
	return;
}

extern "C" __declspec(dllexport) void delete_route(char *id) {
	Route route;
	route.delete_Route(id);
	return;
}

extern "C" __declspec(dllexport) double getLatitude(char *_id) {
	Airport airport;
	return airport.getLatititude(_id);
}

extern "C" __declspec(dllexport) double getLongitude(char *_id) {
	Airport airport;
	return airport.getLongitude(_id);
}

extern "C" __declspec(dllexport) void recuperarAeropuerto(char *str, int capacity) {
	string data, line;
	ifstream reader("Airports.txt");

	if (!reader) {
		data = "1";
		return;
	}

	while (reader >> line) {
		data += line + "\n";
	}

	strcpy_s(str, capacity, data.c_str());

	reader.close();
	return;
}

extern "C" __declspec(dllexport) void recuperarRutas(char *srt, int capacity) {

	std::string data, line;
	std::ifstream reader("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt");

	if (!reader) {
		data = "1";
		return;
	}

	while (reader >> line) {
		data += line + "\n";
	}

	strcpy_s(srt, capacity, data.c_str());

	reader.close();
	return;

}

extern "C" __declspec(dllexport) void get_route(const char *id_origen,const char *id_destino, char *srt, int capacity) {
	Grafo grafo;
	string route = grafo.crear_grafo(id_origen, id_destino);
	strcpy_s(srt, capacity, route.c_str());
}

