#include<iostream>
const int LOWER_LIMIT = 0;
const int UPPER_LIMIT = 100;
void Input_fun(int [], const int &);
void Output_fun(int [], const int &, int, int);
void Input_validation(int &);
int Find_Largest(int [], const int &);
int Find_Smallest(int [], const int &);

using namespace std;

int main()
{
	int smallest, largest;
    const int SIZE = 5;
	int Nums[SIZE];
    Input_fun(Nums,SIZE);
    smallest = Find_Smallest(Nums, SIZE);
    largest = Find_Largest(Nums, SIZE);
    Output_fun( Nums, SIZE, smallest, largest);// modify the ouput function to receive the largest and smallest elments and displays them along with all array elements 
 return 0;
}

void Input_fun(int Ns[],const int &S) // input (populating the array)	
{
	for(int i = 0; i< S; i++){
	    cout << "Enter a value: ";
	    cin >> Ns[i];
        Input_validation(Ns[i]);
        cout << endl;
	}
}

void Output_fun(int array1[], const int &S, int smallest, int largest) // output (displaying the array elements)
{
	cout << "All Elements of Array: " << endl;
    for(int i = 0; i< S; i++){
	    cout << array1[i] << endl;
    }
    cout << endl;

    cout << "Smallest Element: " << smallest << endl;
    cout << "Largest Element: " << largest << endl;
}

void Input_validation(int &num){ // accepts ints between 0 and 100 (try by value next time)
    while (num < LOWER_LIMIT || num > UPPER_LIMIT){
        cout << "Invalid Input. Enter an integer between 0 and 100: ";
        cin >> num;
    }
}

int Find_Largest(int array1[], const int &S) // finds the largest element in the array and returns it
{
    int largest = -1; //0-100 is our range
    for (int i = 0; i < S; i++){
        if (array1[i] > largest) {
            largest = array1[i];
        }
    }
    return largest;
}

int Find_Smallest(int array1[], const int &S) //  finds the smallest element in the array and returns it
{
    int smallest = 101; //0-100 is our range
    for (int i = 0; i < S; i++){
        if (array1[i] < smallest) {
            smallest = array1[i];
        }
    }
    return smallest;
}