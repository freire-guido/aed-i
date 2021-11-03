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
	vector<int> indcodusuUnicos;
	for (individuo i: ti){
		if (i.size() != FILAS_INDIVIDUO){
			return false;
		} else if (ti[0][INDANIO] != i[INDANIO] || ti[0][INDTRIMESTRE] != i[INDTRIMESTRE]){
			return false;
		} else if (perteneceBinario(make_pair(i[INDCODUSU], i[COMPONENTE]), individuosUnicos)) {
			return false;
		} else if (i[COMPONENTE] > 20){
			return false;
		} else if (!(i[INDCODUSU] > 0
		&& i[COMPONENTE] > 0
		&& (0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4)
		&& (0 < i[CH4] && i[CH4] <= 2)
		&& i[CH6] >= 0
		&& (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1)
		&& (-1 <= i[ESTADO] && i[ESTADO] <= 1)
		&& (0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4)
		&& (i[p47T] >= 0 || i[p47T] == -1)
		&& (0 <= i[PP04G] && i[PP04G] <= 10))){
			return false;
		}
		insertarOrdenado(make_pair(i[INDCODUSU], i[COMPONENTE]), individuosUnicos);
		if (!perteneceBinario(i[INDCODUSU], indcodusuUnicos)){
			insertarOrdenado(i[INDCODUSU], indcodusuUnicos);
		}
	}
	vector<int> hogcodusuUnicos;
	for (hogar h: th){
		if (h.size() != FILAS_HOGAR){
			return false;
		} else if (perteneceBinario(h[HOGCODUSU], hogcodusuUnicos)){
			return false;
		} else if (h[IV2] < h[II2]){
			return false;
		} else if (ti[0][INDANIO] != h[HOGANIO] || ti[0][INDTRIMESTRE] != h[HOGTRIMESTRE]){
			return false;
		} else if(!(h[HOGCODUSU] > 0 
		&& (0 < h[HOGTRIMESTRE] && h[HOGTRIMESTRE] <= 4) 
		&& (0 < h[II7] && h[II7] <= 3) 
		&& (h[REGION] == 1 || (40 <= h[REGION] && h[REGION] <= 44)) 
		&& (h[MAS_500] == 0 || h[MAS_500] == 1) 
		&& (0 < h[IV1] && h[IV1] <= 5) 
		&& h[IV2]> 0 
		&& h[II2] >= 1 
		&& (h[II3] == 1 || h[II3] == 2))){
				return false;
		}
		insertarOrdenado(h[HOGCODUSU], hogcodusuUnicos);
	}
	if (indcodusuUnicos != hogcodusuUnicos){
		return false;
	}
	return true;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector < int > resp;
	for (int i=0; i < th.size(); i++){
	    if (th[i][IV1] == CASA && th[i][REGION] == region){
	        if (th[i][IV2] > resp.size()){
	            for (int j=resp.size(); j < th[i][IV2]; j++){
	                resp.push_back(0);
	            }
	        }
	        resp[th[i][IV2]-1]++;
	    }
	}
	return resp;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {
	vector<int> regiones = {1,40,41,42,43,44};
	vector<pair<int, float>> res;
	for (int i=0; i < regiones.size(); i++){
		res.push_back(make_pair(regiones[i], 0));
	} //Ahora res contiene la lista de pares <region, float = 0>

	vector<pair<int, int>> habitantesPorHogcodusu;
	for (individuo i: ti){
		//Almacenamos indice para ver si pertenece y insertar (ordenado) al mismo tiempo.
		int indiceDei = indiceMenorigual(i[INDCODUSU], habitantesPorHogcodusu);
		if (indiceDei > -1 && habitantesPorHogcodusu[indiceDei].first == i[INDCODUSU]){
			habitantesPorHogcodusu[indiceDei].second++;
		} else {
			habitantesPorHogcodusu.insert(habitantesPorHogcodusu.begin() + indiceDei + 1, make_pair(i[INDCODUSU], 1));
		}
	} //Ahora habitantesPorHogcodusu es una lista (ordenada) de pares <hogcodusu, habitantes>.

	vector<int> validosPorRegion(6, 0); 
	for (hogar h: th){
		if (h[MAS_500] == 0 && h[IV1] == 1){
			int indiceEnRegion = indiceMenorigual(h[REGION], regiones);
			validosPorRegion[indiceEnRegion]++;
			int cantidadHabitantes = habitantesPorHogcodusu[indiceMenorigual(h[HOGCODUSU], habitantesPorHogcodusu)].second;
			if (cantidadHabitantes > 3 * h[II2]){
				res[indiceEnRegion].second++;
			}
		}
	} //Ahora res es una lista (ordenada) de pares <region, hogaresCriticos> para cada region.

	for (int i=0; i < regiones.size(); i++){
		if (validosPorRegion[i] != 0){
			res[i].second /= validosPorRegion[i];
		} else {
			res[i].second = 0;
		}
	}
	return res;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    return proporcionTeleworking(t2h,t2i) > proporcionTeleworking(t1h,t1i);
}

float proporcionTeleworking(eph_h encuestaHogar, eph_i encuestaIndividuo) {
    float trabajadores = 0, teleworkers = 0;
    for(hogar h : encuestaHogar){
        if(h[MAS_500] == 1 and (h[IV1] == 1 or h[IV1] == 2)){
            for(individuo i : encuestaIndividuo){
                if(i[INDCODUSU] == h[HOGCODUSU] && i[ESTADO] == 1 && i[PP04G] == 6){
                    teleworkers++;
                } else if(i[INDCODUSU] == h[HOGCODUSU] && i[ESTADO] == 1){
                    trabajadores++;
                }
            }
        }
    }
	return trabajadores == 0 ? 0 : teleworkers / trabajadores;
}


// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int subsidio = 0;
    for(hogar h : th){
        if(h[II7] == 1 and (cantidadHabitantes(h[HOGCODUSU],ti) - 2 > h[II2])){
            subsidio += monto;
        }
    }
  return subsidio;
}


// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
	join_hi resp;
	for(individuo i : ti){
	    for(hogar h : th){
	        if(i[INDCODUSU] == h[HOGCODUSU]){
	            resp.push_back({h,i});
	        }
	    }
	}
  return resp;
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
    for(int h=0;h<th.size();h++){
        if(th[h][REGION] == 1){
            th[h][REGION] = 43;
        }
    }
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
