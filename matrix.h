#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int N = 5;
double matrix[N][N];
double matrix_copy[N][N];
double x[N-1];

void CopyMatrix (){
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            matrix_copy[i][j] = matrix[i][j];
        }
    }
}

void GaussianElimination () {
    CopyMatrix();
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            double k = -matrix[j][i] / matrix[i][i];
            for(int p = 0; p <= N; p++) {
                matrix[j][p] = matrix[j][p] + matrix[i][p] * k;
            }
        }
    }
}

void pricePerUnitOfMeasured(){
    for(int i = N - 2; i >= 0; i--) {
        x[i] = matrix[i][N-1];
        for(int j = i + 1; j < N; j++) {
            x[i] = x[i] - matrix[i][j]*x[j];
        }
        x[i] = x[i]/matrix[i][i];
    }
}

void priceDifference(){
    for (int i=0; i <= N-2; i++){
        double sum = 0;
        int j;
        for (j=0; j <= N-2; j++){
            switch (j){
                case 0:
                    sum += matrix_copy[i][j]*0.129;
                    break;
                case 1:
                    sum += matrix_copy[i][j]*1.461;
                    break;
                case 2:
                    sum += matrix_copy[i][j]*85.07;
                    break;
                default:
                    sum += matrix_copy[i][j]*0.132;
                    break;
            }
        }
        sum = matrix_copy[i][j] - sum;
        cout << sum << "   ";
    }
    cout<<endl;
}

void AmountDifference(){
    for (int i=0; i<=N-2; i++){
        double sum;
        int j;
        for(j=0; j<=N-2; j++){
            sum = 0;
            switch (j){
                case 0:
                    sum = matrix_copy[i][j]*0.129;
                    break;
                case 1:
                    sum = matrix_copy[i][j]*1.461;
                    break;
                case 2:
                    sum = matrix_copy[i][j]*85.07;
                    break;
                default:
                    sum = matrix_copy[i][j]*0.132;
                    break;
            }
            cout<< matrix_copy[i][j] - (sum / x[j])<< "   "; 
        }
        cout<< endl;
    }
}

void loadFromFile (string fileName) {
    string text;
    ifstream file (fileName.c_str());

    if (!file.is_open()){
        throw "File can't be opened!.";
    }

    if (!file.good()){
        throw "There is a problem with the file.";
    }

    double kW_h;
    double m3; 
    double MW_h;
    double min;
    int row = 0;
     
    while(file >> kW_h >> m3 >> MW_h >> min) {
        if (row == 4){
            matrix[0][4] = kW_h;
            matrix[1][4] = m3;
            matrix[2][4] = MW_h;
            matrix[3][4] = min;
        } else{
            matrix[row][0] = kW_h;
            matrix[row][1] = m3;
            matrix[row][2] = MW_h;
            matrix[row][3] = min;
            row++;
        }
	}

    file.close();
}
