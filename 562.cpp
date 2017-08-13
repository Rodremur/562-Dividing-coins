/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 562 - Dividing coins
 * Fecha: 20-04-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

int n, t, i, j, k, e, dif1, dif2, dif_fin, sum;

int coinDiff(int n, int v[], int m) {
	int matrix[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			matrix[i][j] = 0;
		}
	}
	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			if (j < v[i])
				matrix[i][j] = matrix[i-1][j];
			else
				matrix[i][j] = max( (v[i] + matrix[i-1][j - v[i]]), matrix[i-1][j]);
		}
	}
	return matrix[n-1][m-1];
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	for (k = 0; k < t; k++) {
		scanf("%d", &n);
		n += 1;
		sum = 0;
		int v[n];
		v[0] = 0;
		for (e = 1; e < n; e++) {
			scanf("%d", &v[e]);
			sum += v[e];
		}
		dif1 = coinDiff(n, v, sum/2 + 1);
		dif2 = sum - dif1;
		dif_fin = dif2 - dif1;
		printf("%d\n", dif_fin);
	}
    return 0;
}
