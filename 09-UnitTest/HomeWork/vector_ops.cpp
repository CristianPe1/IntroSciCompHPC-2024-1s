#include "vector_ops.hpp"
#include <cmath>
#include <numeric>

/**
 * @brief Calcula el promedio (media aritmética) de los valores en un vector de punto flotante.
 *
 * Esta función toma un vector de números de punto flotante `std::vector<double>` como entrada y calcula
 * su promedio. Utiliza la función `std::accumulate` de la biblioteca estándar para sumar todos los valores
 * en el vector, y luego divide el total por el número de elementos en el vector para obtener el promedio.
 *
 * @param data Una referencia constante a un vector de `std::vector<double>` que contiene los datos
 * sobre los cuales calcular el promedio.
 *
 * @return El promedio (media aritmética) de los valores contenidos en `data` como un `double`.
 * Si el vector está vacío, devuelve `0.0` debido a la división por cero.
 */
double mean(const std::vector<double> & data)
{ 
  //Si el vector está vacío antes de llamar a esta función.
  if (data.empty()) {
        return 0.0; 
    }
    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}


/**
 * @brief Determina si dos valores de punto flotante son cercanos entre sí.
 *
 * Esta función compara dos valores de punto flotante, `a` y `b`, y determina si son cercanos entre sí
 * dentro de una tolerancia especificada. La comparación toma en cuenta tanto una tolerancia absoluta
 * como una tolerancia relativa para proporcionar flexibilidad en la precisión numérica esperada,
 * lo que es especialmente útil en cálculos de punto flotante donde pueden surgir errores de precisión.
 *
 * @param a Primer valor de punto flotante para comparar.
 * @param b Segundo valor de punto flotante para comparar.
 * @param atol Tolerancia absoluta; la diferencia máxima permitida para que `a` y `b` se consideren cercanos. Valor predeterminado: 1e-8.
 * @param rtol Tolerancia relativa; factor que se multiplica por el valor absoluto de `b` para determinar
 * la tolerancia relativa permitida. Se suma a `atol` para calcular la tolerancia total. Valor predeterminado: 1e-5.
 *
 * @return `true` si `a` y `b` son cercanos dentro de las tolerancias especificadas; de lo contrario, `false`.
 * **/
bool isclose(double a, double b, double atol = 1e-8, double rtol = 1e-5) {
    return std::abs(a - b) <= (atol + rtol*std::abs(a-b));
}