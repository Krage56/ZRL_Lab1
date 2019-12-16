#include <iostream>

using namespace std;

int global_val = 33;

const short size_arr = 2;

struct City_district1{
    /*92*/
    char name[60];
    int count_inhabitants;
    char local_boss[21];
    float middle_age;
};

#pragma pack(push, 1)
struct City_district2{
    /*89*/
    char name[60];
    int count_inhabitants;
    char local_boss[21];
    float middle_age;
};
#pragma pack(pop)

void print__(){
    for(int i = 0; i < 12; i++){
        cout << "__";
    }
    cout << '\n';
}

void print(int *arr, int size){
    for(int i = 0; i < size; ++i){
        cout << &(arr[i]) << " ";
    }
    cout << '\n';
}

void print_arr_of_var(int **arr, short s){
    for(int i = 0; i < s; ++i){
        switch (arr[i][0]){
            case (33):
                cout << "global variable (";
                cout << arr[i] << ")";
                break;
            case (34):
                cout << "local auto variable (";
                cout << arr[i] << ")";
                break;
            case (35):
                cout << "dynamic variable (";
                cout << arr[i] << ")";
                break;
            default:
                break;
        }
        i == s - 1 ? cout << "" : cout << ", ";
    }
    cout << '\n';
    print__();
}

int** compare_var(int *a, int *b, int *c){
    const short size = 3;
    int **arr = new int*[size];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(arr[j] - arr[j + 1] > 0){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

void variables(){
    int local_auto_val = 34;
    int *dynamic_val = new int;
    *dynamic_val = 35;
    print_arr_of_var(compare_var(&global_val, &local_auto_val, dynamic_val), 3);
}

void arrays(){
    int static_one_dim_arr[size_arr]{1,2};
    int *dynamic_one_dim_arr = new int[size_arr];
    for(int i = 0; i < size_arr; ++i){
        dynamic_one_dim_arr[i] = i;
    }

    int static_two_dim_arr[size_arr][size_arr]{{5,6},{7,8}};
    int **dynamic_two_dim_arr = new int*[size_arr];
    for(int i = 0; i < size_arr; ++i){
        dynamic_two_dim_arr[i] = new int[size_arr];
    }
    for(int i = 0; i < size_arr; ++i){
        for(int j = 0; j < size_arr; ++j){
            dynamic_two_dim_arr[i][j] = i + j + 8;
        }
    }

    cout << "static one-dimensional array (";
    cout << &(static_one_dim_arr[0]) << ")" << endl;
    print(&static_one_dim_arr[0], size_arr);

    cout << "dynamic one-dimensional array (";
    cout << (dynamic_one_dim_arr) << ")" << endl;
    print(dynamic_one_dim_arr, size_arr);

    cout << "static two-dimensional array (";
    cout << &(static_two_dim_arr[0][0]) << ")" << endl;
    for(int j = 0; j < size_arr; j++){
        for(int k = 0; k < size_arr; k++){
            cout << &(static_two_dim_arr[j][k]) << " ";
        }
    }
    cout << '\n';

    cout << "dynamic two-dimensional array (";
    cout << (dynamic_two_dim_arr[0]) << ")" << endl;
    for(int j = 0; j < size_arr; j++){
        for(int k = 0; k < size_arr; k++){
            cout << &(dynamic_two_dim_arr[j][k]) << " ";
        }
    }
    cout << '\n';
    print__();
}


void structs(){
    int res = 60 + 21 + sizeof(int) + sizeof(float);
    City_district1 South_East;

    City_district2 South_West;

    cout << "Sum of all elements in structs: " << res << endl;
    cout << "Without pushing: " << sizeof(South_East) << endl;
    cout << "With pushing: " << sizeof(South_West) << endl;
    cout << "Struct without #pragma: " << endl;
    cout << &(South_East.name) << ", " << &(South_East.count_inhabitants)
         << ", " << &(South_East.local_boss) << ", "<<
         &(South_East.middle_age) << endl;

    cout << "Struct with #pragma: " << endl;
    cout << &(South_West.name) << ", " << &(South_West.count_inhabitants)
         << ", " << &(South_West.local_boss) << ", "<<
         &(South_West.middle_age) << endl;

    print__();
}

int main() {
    variables();
    arrays();
    structs();
    return 0;
}
