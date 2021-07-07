////////programmazione dinamica
//plsc

///////////////////plsc
const int m=6; const int n=6;
int mat[m+1][n+1];
int plsc(char* a,char* b){  //complessità ?
    for (int i = 0; i <=n ; ++i) { //prima riga di zeri
        mat[0][i]=0;
    }
    for (int i = 1; i <=m ; ++i) {
        mat[i][0]=0; //prima colonna di zeri
        for (int j = 1; j <=n ; ++j) {
            if (a[i-1]==b[j-1]){
                mat[i][j]=mat[i-1][j-1] +1;
            }
            else  mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
        }
    }
    return mat[m][n];
}

void print(char* a, char* b, int i=m,int j=n){
    //non ci interessa stampare la colonna di zeri o la riga di zeri
    if (!i || !j) return;
    //lavoro con gli indici precedenti poichè la lunghezza della stringa è m o n ma l'accesso è in m-1 (casella 0)
    if (a[i-1] == b[j-1]){
        print(a, b, i-1, j-1);
        cout << a[i-1];
    }
    else {
        if (mat[i][j] == mat[i][j-1]) {
            print( a, b, i , j-1);}
        else print( a, b, i-1, j );
    }
}
