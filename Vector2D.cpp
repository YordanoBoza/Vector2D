#include <iostream>
#include <cmath>
using namespace std;
 
//Clase Vector 2D
class Vector2D{
private:
    float x;
    float y;
    
public:
    //Constructor
    Vector2D(float x_1, float y_2){
        x = x_1;
        y = y_2;
    }

    // Función inline para calcular la magnitud
    inline float magnitud() const {
        float sum_cuad = pow(x, 2) + pow(y, 2);
        return sqrt(sum_cuad);
    }

    // Función const para mostrar el vector
    void mostrar() const {
        cout << "(" << x << ", " << y << ")" << endl;
    } 

    // Función friend para calcular el producto punto
    friend float productoPunto(const Vector2D& v1, const Vector2D& v2);

    // Sobrecarga del operador +
    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }
};

// Definición de la función friend
float productoPunto(const Vector2D& v1, const Vector2D& v2) {
    float c1 = v1.x * v2.x;
    float c2 = v1.y * v2.y;
    return c1 + c2;
}

int main() {
    Vector2D v1(3.5, 5);
    Vector2D v2(4.8, 6.2);
    
    cout << "Vector 1:";
    v1.mostrar();
    cout << "Vector 2:";
    v2.mostrar();

    cout << "\nMagnitud del vector 1: " << v1.magnitud() << endl;
    cout << "Magnitud del vector 2: " << v2.magnitud() << endl;

    cout << "\nProducto punto de v1 y v2: " << productoPunto(v1, v2) << endl;

    // Uso de la sobrecarga del operador +
    Vector2D v3 = v1 + v2;
    cout << "\nSuma de v1 y v2: ";
    v3.mostrar();

    // Lambda que determina si la magnitud supera un umbral
    auto superaUmbral = [](const Vector2D& v, float umbral) {
        return v.magnitud() > umbral;
    };

    float umbral = 7.0;
    if (superaUmbral(v1, umbral))
        cout << "\nLa magnitud de v1 supera el umbral (" << umbral << ")." << endl;
    else
        cout << "\nLa magnitud de v1 NO supera el umbral (" << umbral << ")." << endl;

    if (superaUmbral(v2, umbral))
        cout << "\nLa magnitud de v2 supera el umbral (" << umbral << ")." << endl;
    else
        cout << "\nLa magnitud de v2 NO supera el umbral (" << umbral << ")." << endl;

    return 0;
}
