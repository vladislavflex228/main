int** raiseMatrixPower(int** matrix,int SIZE,int power)
{
    int **saveMatrix = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        saveMatrix[i] = new int[SIZE];
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)  
        {
            saveMatrix[i][j] = matrix[i][j];
        }
            
    }
    int **currMatrix = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        currMatrix[i] = new int[SIZE];
    }

    for (int l = 1; l < power; l++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                int curr = 0;
                for (int k = 0; k < SIZE; k++)
                {
                    curr += matrix[i][k] * saveMatrix[k][j];
                }
                currMatrix[i][j] = curr;
            }
            
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                matrix[i][j] = currMatrix[i][j];
            }
            
        }
        
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete[] saveMatrix[i];      
    }
    delete[] saveMatrix;
    for (int i = 0; i < SIZE; i++)
    {
        delete[] currMatrix[i];      
    }
    delete[] currMatrix;
    

    
    return matrix;
}