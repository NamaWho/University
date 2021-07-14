#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <math.h>       /* floor */
#include <stdlib.h>
#include <cmath>        /* pow  */

class Heap
{
    std::vector<int> lista_;

public:
    Heap() {};

    void inserisci(int k)
    {
        lista_.push_back(k);
        std::make_heap (lista_.begin(),lista_.end());
    }

    bool isFirstChild( int i )
    {
        if( ( i!=0 ) && ( (i&(i-1)) == 0) )
            return true;
        else
            return false;
    }

    // --------------------------METODO DA AGGIUNGERE--------------------------

    void printHeap(){
        int k = 0;
        for (int i = 0; i < floor(log2(lista_.size())+1); ++i) {
            for (int j = 0; j < pow(2, i); ++j) {
                std::cout << lista_[k] << "\t";
                k++;
            }
            std::cout << std::endl;
        }
    }

    void printHeapWithSquareDescendants(int k){
        int count = 0;
        int index = -1;
        for (int i = 0; i < floor(log2(lista_.size())+1); ++i) {
            for (int j = 0; j < pow(2, i); ++j) {
                if (index == -1 && lista_[count] == k){
                    index = count;
                    std::cout << lista_[count] << "\t";
                }
                else if (index != -1 && (count == 2*index+1 || count == 2*index+2))
                    std::cout << "[" << lista_[count] << "]" << "\t";
                else
                    std::cout << lista_[count] << "\t";
                count++;
            }
            std::cout << std::endl;
        }
    }
/*
    void printHeapWithRightInSquare(int elem, int i = 0){
        if (i >= lista_.size()) return;
        if (isFirstChild(i+1)) std::cout << std::endl;
        if (2*i+1 < lista_.size() && lista_[2*i+2] == elem)
            std::cout << "[" << lista_[i] << "]\t";
        else std::cout << lista_[i] << "\t";
        printHeapWithRightInSquare(elem, i+1);
    }
*/
    // ------------------------------------------------------------------------

};

//======================================MAIN===================================

int main()
{
    int N;
    int K;
    int x;

    std::cin >> N >> K;
    Heap h;

    // riempio lo heap
    for( int i=0 ; i<N ; ++i )
    {
        std::cin >> x;
        h.inserisci(x);
    }

    // --------------------------CHIAMATA AL METODO----------------------------

    h.printHeap();
    h.printHeapWithSquareDescendants(6);
    //h.printHeapWithRightInSquare(9);

    // ------------------------------------------------------------------------
}

