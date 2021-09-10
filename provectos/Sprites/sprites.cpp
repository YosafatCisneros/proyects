#include <iostream>
#include <vector>
#include <stack>
#include <fstream>



using namespace std;

int main() 
{

    ifstream fichero;
    
    fichero.open("dibujo.txt");
    int A = 20;
    string matriz[A][A];
    string matriz2[A][A];
    int Columnas = 0, Filas = 0;
    string cero_uno;
    while (fichero >> cero_uno) {
        if (cero_uno == " ")
            continue;
        if (cero_uno == ".")
            matriz[Columnas][Filas] = ("0");
        else
            matriz[Columnas][Filas] = ("1");
        matriz2[Columnas][Filas] = cero_uno;
        Filas++;
        if (cero_uno == "\n")
            Columnas++;
    }
    fichero.close();
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            cout << matriz2[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            cout << matriz[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    
    stack<pair<int, int> > pila;
    pair<int, int> actual;
    pair<int, int> coord_min;
    pair<int, int> coord_max;
    vector<pair<pair<int, int>, pair<int, int > > > vector_sol;
	int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            if (matriz[i][j] == "1") {
                actual = make_pair(i, j);
                pila.push(actual);
                matriz[i][j] = "0";
                int x1 = A;
                int x2 = 0;
                int y1 = A;
                int y2 = 0;

                while (!pila.empty()) {
                    actual = pila.top();

                    if (actual.first <= x1)
                        x1 = actual.first;
                    if (actual.first >= x2)
                        x2 = actual.first;
                    if (actual.second <= y1)
                        y1 = actual.second;
                    if (actual.second >= y2)
                        y2 = actual.second;
                    coord_min = make_pair(x1, y1);
                    coord_max = make_pair(x2, y2);
                    pila.pop();
                    for (int k = 0; k < 8; k++) {
                        int x = dx[k] + actual.first;
                        int y = dy[k] + actual.second;
                        if (x >= 0 && x < A && y >= 0 && y < A) {
                            if (matriz[x][y] == "1") {
                                pila.push(make_pair(x, y));
                                matriz[x][y] = "0";
                            }
                        }
                    }
                }
                vector_sol.push_back(make_pair(coord_min, coord_max));
            }
        }
    }
    
    
    
    
    for (int q = 0; q < vector_sol.size(); q++) {

        cout << "coordenadas iniciales del cuadrado " << q + 1 << " son: (" << vector_sol[q].first.second + 1 << " , " << vector_sol[q].first.first + 1 << ")" << endl;
        cout << "coordenadas finales del cuadrado " << q + 1 << " son: (" << vector_sol[q].second.second + 1 << " , " << vector_sol[q].second.first + 1 << ")" << endl;
        cout << "\n";
        for (int i = vector_sol[q].first.first; i <= vector_sol[q].second.first ; i++) {
			for (int j = vector_sol[q].first.second; j <= vector_sol[q].second.second; j++) {
            	if(i == vector_sol[q].first.first || i == vector_sol[q].second.first || j == vector_sol[q].first.second || j == vector_sol[q].second.second)
				matriz2[i][j]=("x");
			}
		}
    
	}
	fichero.close();
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            cout << matriz2[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}
