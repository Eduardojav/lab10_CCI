#include<iostream>
using namespace std;
int nufilA,nucolA,nufilB,nucolB,x=0,z=0;
int soraka(int **A,int a,int j,int i=0){//crea la matriz
  if(i==a)return 0;
    *(A+i)=new int[j];
    return soraka(A,a,j,++i);
}
int datos(int **A,int &a,int &b,int i=0,int j=0){// llena de datos la matriz
  cin>>*(*(A+i)+j);
  if(i!=a-1 or j!=b-1){
    if(j==b-1){i++;j=0;}
    else j++;
    datos(A,a,b,i,j);
   }
}
void prints(int **A,int a, int b, int i=0,int j=0){//imprime la matriz
    if(i==0 and j==0)cout<<'\n';
  cout<<*(*(A+i)+j);
  if(i!=a-1 or j!=b-1){
    if(j==b-1){
      cout<<'\n';
      i++;j=0;
    }
    else {
      cout<<' ';
      j++;
    }
   prints(A,a,b,i,j);
  }
  else cout<<'\n';
}
int marx(int**A,int a,int b,int &maximo,int i=0,int j=0){//busca el maximo de la matriz
    if(i!=a-1 or j!=b-1){
        if(j==b-1){i++;j=0;}
        else j++;
        int c=*(*(A+i)+j);
        if (c>maximo){
            maximo=c;
            }
    marx(A,a,b,maximo,i,j);}
    return maximo;}
int multiplicar(int **A,int **B,int **C,int a,int b,int y,int i=0,int j=0,int z=0){
  y=0;
  *(*(C+i)+j)=y;
  if(i!=a-1 or j!=b-1){
    if(j==b-1){i++;j=0;}
    else j++;
    if(z!=b-1){z++;
    y+=*(*(A+z)+j)* *(*(B+i)+z);}
    multiplicar(A,B,C,b,i,j,y);
  }
  }
int mins(int**A,int a,int b,int &minimo,int i=0,int j=0){//busca el minimo de la matriz
    if(i!=a-1 or j!=b-1){
        if(j==b-1){i++;j=0;}
        else j++;
        int c=*(*(A+i)+j);
        if (minimo>c){
            minimo=c;
            }
    mins(A,a,b,minimo,i,j);}
    return minimo;}
void suma(int**A,int**B,int**C,int a,int b,int i=0,int j=0){//suma las matrices
    *(*(C+i)+j)=*(*(A+i)+j)+*(*(B+i)+j);
    if(i!=a-1 or j!=b-1){
        if(j==b-1){i++;j=0;}
        else j++;
        suma(A,B,C,a,b,i,j);}}
void resta(int**A,int**B,int**C,int a,int b,int i=0,int j=0){//resta las matrices
    *(*(C+i)+j)=*(*(A+i)+j)-*(*(B+i)+j);
    if(i!=a-1 or j!=b-1){
        if(j==b-1){i++;j=0;}
        else j++;
        resta(A,B,C,a,b,i,j);}}
void suma2(int**A,int**B,int**C,int a,int b,int i=0,int j=0){//suma y divide la matriz
    *(*(C+i)+j)=(*(*(A+i)+j)+*(*(B+i)+j))/2;
    if(i!=a-1 or j!=b-1){
        if(j==b-1){i++;j=0;}
        else j++;
        suma2(A,B,C,a,b,i,j);}}
void comprobante(int a,int a2,int b,int b2,int&x,int&z){//mira valores para crear una matriz C
        if(a>=b){
            x=b;}
        else x=a;
        if(a2>=b2){
            z=b2;}
        else z=a2;}
void zed(int **ptr_Z,int a){//borra la matriz
    if(a==-1){
        delete[] ptr_Z;
        return;}
    if (a!=-1){
    delete[] ptr_Z[a];
    zed(ptr_Z,a-1);}
    }
  int main(){
    int g;
    cout<<"ingrese numero de filas de "<<endl;//pedimos datos para la matriz A
    cin>>nufilA;
    cout<<"ingrese numero de columnas de :"<<endl;
    cin>>nucolA;
    int **A =new int*[nufilA];
    soraka(A,nufilA,nucolA);
    datos(A,nufilA,nucolA);
    prints(A,nufilA,nucolA);
    cout<<"ingrese numero de filas de "<<endl;//pedimos datos para la matriz B
    cin>>nufilB;
    cout<<"ingrese numero de columnas de :"<<endl;
    cin>>nucolB;
    int **B =new int*[nufilB];
    soraka(B,nufilB,nucolB);
    datos(B,nufilB,nucolB);
    prints(B,nufilB,nucolB);
    //pedimos que accion quiere el usuario
    cout<<"que operacion quiere hacer:"<<endl;
    cout<<"buscar el maximo:1"<<endl;
    cout<<"buscar el minimo:2"<<endl;
    cout<<"restar matrices:3"<<endl;
    cout<<"sumar matrices:4"<<endl;
    cout<<"sumar y dividir entre 2 lasmatrices:5"<<endl;
    cout<<"multiplicar matrices:6"<<endl;
    cin>>g;
    if (g==3||g==4||g==5){//si escoje de 3 a 5 podemos hacer 3 acciones las cuales son suma,resta y suma entre 2
        comprobante(nufilA,nucolA,nufilB,nucolB,x,z);//le damos valores a x y z para poder sumar y restar si son de diferentes dimensiones
        int **C =new int*[x];//creamos la matriz C
        soraka(C,x,z);
        if(g==3){
            resta(A,B,C,x,z);
            prints(C,x,z);
        }
        if(g==4){
            suma(A,B,C,x,z);
            prints(C,x,z);}
        if (g==5){
            suma2(A,B,C,x,z);
            prints(C,x,z);}
        zed(C,x);}

    if(g==1){//si escoje 1 o 2 se puede buscar el max y el min
        x=marx(A,nufilA,nucolA,*((*A+0)+0));//buscamos el amyor de cada matriz y lo comparamos
        z=marx(B,nufilB,nucolB,*((*B+0)+0));
        if (x<=z){
            cout<<"el mayor elemento"<<z<<endl;}
        else{
            cout<<"el mayor elemento"<<x<<endl;}
        }
    if(g==2){
        x=mins(A,nufilA,nucolA,*((*A+0)+0));
        z=mins(B,nufilB,nucolB,*((*B+0)+0));
            if (x<=z){
            cout<<"el menor elemento"<<" "<<x<<" "<<endl;}
            else{
            cout<<"el menor elemento"<<" "<<z<<" "<<endl;}}
    if (g==6){//si escojes 6 es para multiplicar
        if(nucolA==nufilB){//si son iguales se puede multiplicar
                int **C =new int*[nucolA];//creamos la matriz C
                soraka(C,nucolA,nufilB);
                multiplicar(A,B,C,nucolA,nucolA,0);}
    else cout<<"no se puede"<<endl;//de caso contrario le decimos que no se puede
   zed(A,nufilA);
    zed(B,nufilB);
    return 0;}}
