#include<iostream>
#include<vector>
#include<math.h>
#include<string>

using namespace std;


class Matrix {
    private:
        int weigth=0;
        int height=0;
        vector < vector<int> > matriz;

    public:
        Matrix(){
            cout<<"Inizializando matriz...\n";
            cout<<"Digita las dimensiones de tu matriz: ";
            cin>>this->weigth>>this->height;
            this->matriz.resize(this->height, vector<int> (this->weigth));
        }

        ~Matrix(){
            cout<<"Thanks For use it..."<<endl;
            cout<<"Exit program..."<<endl;
        }

        void getDimensions(){
            cout<<"The dimanssions are: ";
            cout<<this->weigth<<" weight, "<<this->height<<" height."<<endl;
        }

        void setMatrixData(){
            cout<<"Digit the elements for your matrix: "<<endl;
            for(int i=0;i<this->height;i++){
                for(int j=0;j<this->weigth;j++){
                    cin>>this->matriz[i][j];
                }
            }
        }

        void getPrincipalDiagnonal(){
            cout<<"The principal diagonal elements are: "<<endl;

            for(int i=0;i<this->height;i++){
                for(int j=0;j<this->weigth;j++){
                    if(i==j){
                        cout<<this->matriz[i][j]<<" ";
                    }
                }
            }
            cout<<endl;
        }

        void getSecondDiagonal(){
            cout<<"The secondary diagonal elements are: "<<endl;
            for(int i=0;i<this->height;i++){
                for(int j=this->weigth-1;j>=0;j--){
                    if( (i+j) == (this->height-1) ){
                        cout<<this->matriz[i][j]<<" ";
                    }
                }
            }
            cout<<endl;
        }

        void printMatrix(){
            cout<<"Your matrix is: "<<endl;
            for(auto vect1D : matriz){
                for(int x : vect1D){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }
};


int main(){
    cout<<sqrt(144)<<endl;
    Matrix *m = new Matrix();
    m->getDimensions();
    m->setMatrixData();
    m->getPrincipalDiagnonal();
    m->getSecondDiagonal();
    m->printMatrix();
    return 0;
}