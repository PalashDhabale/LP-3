#include<iostream>
using namespace std;

int main()
{
    cout<<"*** Fracctional Knapsack Problem ***"<<endl;
    cout<<"Enter the capacity of Knapsack : ";
    int capacity;
    cin>>capacity;
    cout<<"Enter the number of Objects : ";
    int n;
    cin>>n;
    float *profit = new float[n];
    float *weight = new float[n];
    float *profitByWeight = new float[n];
    float *res = new float[n];
    
    for(int i = 0 ;i < n ;i++)
    {
        res[i] = 0.0;
    }

    cout<<"taking Input "<<endl;
    cout<<"Enter the profit and weights "<<endl;
    for(int i = 0;i<n;i++)
    {
        cin >> profit[i];
        cout<<" ";
        cin >> weight[i];
        cout<<endl;
        profitByWeight[i] = profit[i]/weight[i];
    }
    
    //selecction sort in descending order;

    for(int i = 0 ; i<(n-1) ; i++)
    {
        int maximum = i;
        for(int j = i+1 ;j<n;j++)
        {
            if(profitByWeight[maximum] < profitByWeight[j] )
            {
                maximum = j;
            }
        }
        swap(profitByWeight[maximum] , profitByWeight[i]);
        swap(profit[maximum],profit[i]);
        swap(weight[maximum],weight[i]);
    }

    int i = 0;
    float totalProfit = 0;
    for(;i<n;i++)
    {
        if(weight[i] > capacity)
        {
            break;
        }
        else 
        {
            totalProfit = totalProfit + profit[i];
            capacity = capacity - weight[i];
            res[i] = 1.0; 
        }
    }

    if(weight[i] > capacity && capacity != 0 )
    {
        res[i] = capacity/weight[i];
        totalProfit = totalProfit + (res[i]*profit[i]);
    }

    cout<<"Total Profit "<<totalProfit;
    return 0;
}