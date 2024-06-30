/*#include<iostream>
using namespace std;
void matrix_multiple(int *a,int *c,int n,int m)
{
    
    int b[n][m];
      for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          b[i][j]=0;
        }
    }
   for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                b[i][j] += a[i * m + k] * c[k * m + j];
            }
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          cout << b[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int n,m;
    cout<<"Enter row:";
    cin>>n;
     cout<<"Enter col:";
    cin>>m;
    int a[n][m],c[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<"enter first element-"<<"("<<i<<","<<j<<")"<<":";
            cin>>a[i][j];
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<"enter first element-"<<"("<<i<<","<<j<<")"<<":";
            cin>>c[i][j];
        }
    }
   matrix_multiple((int*)a,(int*)c,n,m);
   
}
*/
/*
#include<iostream>
using namespace std;
#include <time.h>
void matrix_multiple(int *a, int *c, int n, int m) {
    int **b = new int*[n];
    for(int i = 0; i < n; ++i)
        b[i] = new int[m];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            b[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                b[i][j] += a[i * m + k] * c[k * m + j];
            }
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          cout << b[i][j]<<" ";
        }
        cout<<"\n";
    }
  }

int main() {
    int n, m;
    cout << "Enter row: ";
    cin >> n;
    cout << "Enter col: ";
    cin >> m;
    
    int *a = new int[n * m];
    int *c = new int[n * m];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Enter first element-" << "(" << i << "," << j << "): ";
            cin >> a[i * m + j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Enter second element-" << "(" << i << "," << j << "): ";
            cin >> c[i * m + j];
        }
    }
    
   clock_t start = clock();
    matrix_multiple(a, c, n, m);
     clock_t end = clock();
     double elapsed_time = (double)(end - start);// / CLOCKS_PER_SEC;
      printf("Execution time: %f \n", elapsed_time);
    
    delete[] a;
    delete[] c;
    
    return 0;
}*/



/*
#include <iostream>
#include <vector>
#include <chrono> // for time measurement
#include <cstdlib> // for rand()
#include <ctime> // for time()

using namespace std;
using namespace std::chrono;

// Function to perform matrix multiplication
void matrix_multiply(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
     clock_t start_time, end_time;
    double execution_time;
     start_time = clock();
    int m = matrix1.size();
    int n = matrix2[0].size();
    int p = matrix2.size();

    // Resultant matrix initialized with zeros
    vector<vector<double>> result(m, vector<double>(n, 0));

    // Perform multiplication
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    end_time = clock();
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
     cout<<"Execution time:"<<execution_time<<"seconds";
  //  return result;
}

// Function to print a matrix
void print_matrix(const vector<vector<double>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, rows1, cols1, rows2, cols2;

    printf("Enter choice (1 to 5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            rows1 = cols1 = 1000;
            break;
        case 2:
            rows1 = cols1 = 2000;
            break;
        case 3:
            rows1 = cols1 = 2500;
            break;
        case 4:
            rows1 = cols1 = 3000;
            break;
        case 5:
            rows1 = cols1 = 3500;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    rows2 = cols2 = rows1;  // Ensure square matrices
    int size = rows1 * cols1;
    printf("Matrix size (elements): %d\n", size);

    // Seed the random number generator
    srand(time(NULL));

    // Define matrices based on user choice and initialize with random numbers
    vector<vector<double>> matrix1(rows1, vector<double>(cols1));
    vector<vector<double>> matrix2(rows2, vector<double>(cols2));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            matrix1[i][j] = ((double)rand()) / RAND_MAX;
            matrix2[i][j] = ((double)rand()) / RAND_MAX;
        }
    }


  int m = matrix1.size();
    int n = matrix1[0].size();


    // Start measuring time
   // auto start = high_resolution_clock::now();

   // vector<vector<double>> result = matrix_multiply(matrix1, matrix2);
     matrix_multiply(matrix1, matrix2);

    

    return 0;
}*/

#include <iostream>
#include <vector>
#include <chrono> // for time measurement
#include <cstdlib> // for rand()
#include <ctime> // for time()

using namespace std;
using namespace std::chrono;

// Template function for matrix multiplication
template<typename T>
std::vector<std::vector<T>> matrixMultiply(const std::vector<std::vector<T>>& mat1,
                                            const std::vector<std::vector<T>>& mat2,
                                            size_t m, size_t n) {

     clock_t start_time, end_time;
    double execution_time;
     start_time = clock();                           
    // Result matrix dimensions
    size_t p = mat2.size();
    
    // Check if dimensions are valid for multiplication
    if (m == 0 || n == 0 || p == 0 || mat1[0].size() != p) {
        throw std::invalid_argument("Invalid matrix dimensions for multiplication");
    }

    // Initialize result matrix
    std::vector<std::vector<T>> result(m, std::vector<T>(p, 0));

    // Perform matrix multiplication
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < p; ++j) {
            for (size_t k = 0; k < n; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
     end_time = clock();
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
     cout<<"Execution time:"<<execution_time<<"seconds";
    return result;
}

int main() {
    // Example matrices
       vector<vector<double>> mat1(1000, vector<double>(1000));
    vector<vector<double>> mat2(1000, vector<double>(1000));



    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            mat1[i][j] = ((double)rand()) / RAND_MAX;
            mat2[i][j] = ((double)rand()) / RAND_MAX;
        }
    }
 cout<<"dasd";
    try {
        // Multiply matrices
        auto result = matrixMultiply(mat1, mat2, 1000, 1000);

        // Print result
        /*for (const auto& row : result) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }*/
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

