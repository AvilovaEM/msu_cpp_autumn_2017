#include <iostream>
#include <chrono>
#include <cstdlib>

enum {
    NUMBER_OF_RUNS = 100,
    SIZE = 10000
};

class Timer
{
public:
    Timer()
        : start_(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        int all_time =  std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count();
        std::cout << all_time / NUMBER_OF_RUNS << " us" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};



void initializeMatrix(int** matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

void sumByColumns(int** matrix)
{
    volatile long long int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum += matrix[j][i];
        }
    }
}

int main()
{
    int** test_matrix;
    test_matrix = new int* [SIZE];
    for (int i=0; i < SIZE; i++)
    {
        test_matrix[i] = new int [SIZE];
    }
    initializeMatrix(test_matrix);

    Timer t;
    for (int k = 0; k < NUMBER_OF_RUNS; k++)
    {
        sumByColumns(test_matrix);
    }

    delete[] test_matrix;
    return 0;
}
