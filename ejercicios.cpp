#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
	if (th.size() == 0 || ti.size() == 0){
		return false;
	}
	vector<pair<int, int>> individuosUnicos;
	int anio = th[0][HOGANIO], trimestre = th[0][HOGTRIMESTRE];
	for (individuo i: ti){
		if (i.size() != FILAS_INDIVIDUO){
			return false;
		} else if (perteneceBinario(make_pair(i[INDCODUSU], i[COMPONENTE]), individuosUnicos)) {
			return false;
		} else if (i[INDANIO] != anio || i[INDCODUSU] != trimestre){
			return false;
		} else if(i[COMPONENTE] > 20){
			return false;
		}
		insertarOrdenado(make_pair(i[HOGCODUSU], i[COMPONENTE]), individuosUnicos);
	}
	for (hogar h: th){
		if (h.size() != FILAS_HOGAR){
			return false;
		} else if(h[IV2] < h[II2]){
			return false;
		}
		 else if (h[HOGANIO] != anio || h[HOGTRIMESTRE] != trimestre){
			return false;
		}
	}
	return true;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector < int > resultado;
	for(int i = 0; i<th.size();i++){
	    if(th[i][IV1] == CASA && th[i][REGION] == region){
	        int cantidadHabitaciones = th[i][IV2];
	        if(cantidadHabitaciones > resultado.size()){
	            for(int j=resultado.size();j < cantidadHabitaciones;j++){
	                resultado.push_back(0);
	            }
	        }
	        resultado[cantidadHabitaciones-1] += 1;
	    }
	}
	// TODO
	
	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

//    vector<pair<int,float>> resp = {make_pair(1,-1.0),
//                                        make_pair(40, -1.0),
//                                        make_pair(41, -1.0),
//                                        make_pair(42,-1.0),
//                                        make_pair(43,-1.0),
//                                        make_pair(44,-1.0)};

    vector<pair<int,float>> resp;
    vector<int> regiones = {1,40,41,42,43,44};
    for(int j=0;j<regiones.size();j++){
        int hogaresValidos = 0;
        int hogaresCriticos = 0;
        for(hogar h : th){
            if(h[REGION]== regiones[j] && h[MAS_500] == 0 && h[IV1] == 1){
                hogaresValidos += 1;
                int individuosHogar = 0;
                int habitacionesHogar = h[IV2];
                for(individuo i : ti){
                    if(i[INDCODUSU] == h[HOGCODUSU]){
                        individuosHogar += 1;
                    }
                }
                if(habitacionesHogar / individuosHogar > 3){
                    hogaresCriticos += 1;
                }
            }
        }
        if(hogaresValidos == 0){
            pair<int,float> hogarRegioni = {regiones[j],0};
            resp.push_back(hogarRegioni);
        } else{
            pair<int,float> hogarRegioni = {regiones[j],(hogaresCriticos/hogaresValidos)};
            resp.push_back(hogarRegioni);
        }
    }

  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	bool resp = false;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
	int resp = -1;
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	join_hi resp = {make_pair(h,i)};
	
	// TODO
	
  return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
	
	// TODO
	
	return;
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
	
	// TODO
	
	return;
}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector < int > resp = {};
	
	// TODO
	
	return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
		
	// TODO
	
	return resp;
}
