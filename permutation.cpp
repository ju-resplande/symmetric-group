#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int n){
    if (n == 1)
        return 1;

    return n*factorial(n-1);
}

class Permutation
{
public:
    int size;
    int* permutation;

    Permutation(int n, int array [])
    {
       this->size = n;
       this->permutation = new int[n];

       for (int i = 0; i < n; ++i)
            this->permutation[i] = array[i];
    }

    Permutation operator *(Permutation f){
        if (this->size != f.size)
            exit(0);

        int new_array[size];

        for (int i = 0; i < size; ++i){
            new_array[i] = this->permutation[f.permutation[i]-1];
        }

        return Permutation(size,new_array);
    };


    Permutation operator ^(int n){
        Permutation result(this->size, this->permutation);

        if (n < 0){
            result = inverse();
            n *= -1;
        }

        for (int i = 0; i < n-1; ++i)
            result = result * (*this);
        
        return result;
    };

    void print(){
        for (int i = 0; i < this->size; ++i)
            cout << this->permutation[i];

        cout << endl;
    }

    int** group(){
       int identity[this->size], **group, group_size;

       group_size = factorial(this->size);
       group = new int*[group_size];

       for (int i = 0; i < size; ++i)
         identity[i] = i+1;

       for (int i = 0; i < group_size; ++i){
            group[i] = new int[this->size];

            for (int j = 0; j < this->size; ++j)
                group[i][j] = identity[j];

           next_permutation(identity,identity+this->size);
        }

        return group;
    }

    Permutation inverse(){
        Permutation result(this->size, this->permutation);

        for (int i = 0; i < this->size; ++i)
            result.permutation[this->permutation[i]-1] = i+1;

        return result;  
    }    
};


int main(){
    int array[] = {1,3,4,2}, **group;
    Permutation pi(4,array);
    
    /*group = iota.group();

    for (int i = 0; i < factorial(4); ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << group[i][j];
        }

        cout << endl;
    }*/

    pi.inverse().print();

    return 0;
}
