// Link
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int N, w, h;
long long n, x, y;

int** getMat(int posX, int posY, int width, int height, int dim) {
	cerr << "PosX:" << posX << " PosY:" << posY << " W:" << width << " H:" << height << " Dim:" << dim << endl;
	int sX, sY, fX, fY;
	int dim2 = dim / 2;
	int** mat = new int* [width];
	for (int i = 0; i < width; i++) {
		mat[i] = new int[height];
		}
	if (dim == 1) {
		cout << "OK\n";
		mat[0][0] = 1;
		}
	else {
		sX = posX % dim2;
		sY = posY % dim2;
		if (posX < dim2 && posY < dim2) {
			fX = min(dim2, posX + width);
			fY = min(dim2, posY + height);
			int** mat1 = getMat(sX, sY, fX, fY, dim / 2);
			cerr << "SX:" << sX << " SY:" << sY << " fX:" << fX << " fY:" << fY << " Dim:" << dim << " 1el: " << mat1[0][0] << endl;
			for (int i = 0; i < fX - sX; i++) {
				for (int j = 0; j < fY - sY; j++) {
					mat[i][j] = mat1[i][j];
					}
				}
			}
		if (posX + width >= dim2 && posY < dim2) {
			sX = max(posX, dim2) % (dim2);
			sY = posY % (dim2);
			fX = min(dim - 1, posX + width) % (dim2 + 1);
			fY = min(dim2, posY + height) % (dim2 + 1);
			int** mat1 = getMat(sX, sY, fX, fY, dim2);
			cerr << "SX:" << sX << " SY:" << sY << " fX:" << fX << " fY:" << fY << " Dim:" << dim << " 1el: " << mat1[0][0] << endl;
			for (int i = sX; i < fX - sX; i++) {
				for (int j = 0; j < fY - sY; j++) {
					mat[i][j] = mat1[i][j];
					}
				}
			}
		if (posX < dim2 && posY + height >= dim2) {
			sX = posX % (dim2);
			sY = max(posY, dim2) % (dim2);
			fX = min(dim2, posX + width) % (dim2 + 1);
			fY = min(dim - 1, posY + height) % (dim2 + 1);
			int** mat1 = getMat(sX, sY, fX, fY, dim2);
			cerr << "SX:" << sX << " SY:" << sY << " fX:" << fX << " fY:" << fY << " Dim:" << dim << " 1el: " << mat1[0][0] << endl;
			for (int i = 0; i < fX - sX; i++) {
				for (int j = sY; j < fY - sY; j++) {
					mat[i][j] = mat1[i][j];
					}
				}
			}
		if (posX + width >= dim2 && posY + height >= dim2) {
			sX = max(posX, dim2) % (dim2);
			sY = max(posY, dim2) % (dim2);
			fX = min(dim - 1, posX + width) % (dim2 + 1);
			fY = min(dim - 1, posY + height) % (dim2 + 1);
			int** mat1 = getMat(sX, sY, fX, fY, dim2);
			cerr << "SX:" << sX << " SY:" << sY << " fX:" << fX << " fY:" << fY << " Dim:" << dim << " 1el: " << mat1[0][0] << endl;
			for (int i = sX; i < fX - sX; i++) {
				for (int j = sY; j < fY - sY; j++) {
					mat[i][j] = -mat1[i][j];
					}
				}
			}
		}
	return mat;
	}

void printMat() {
	int** mat = getMat(x, y, w, h, n);
	for (int i = 0; i <= w - x - 1; i++) {
		for (int j = 0; j <= h - y - 1; j++) {
			cout << mat[i][j] << " ";
			}
		cout << endl;
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n >> x >> y >> w >> h;
		printMat();
		cout << ":)" << endl;
		}

	return 0;
	}