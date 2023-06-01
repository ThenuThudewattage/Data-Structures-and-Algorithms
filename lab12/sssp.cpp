#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// supporting function to find the node with minimum distance
int minimum_distance(int time[], bool marked_arr[]){
    int minimum = INT_MAX, index;
              
    // Initialize time array with maximum values
    for(int i=0 ; i<6 ; i++){
        if(time[i]<=minimum && marked_arr[i]== false){
            minimum = time[i];
            index = i;
        }
    }
    return index;
}

// implementation of Dijkstra's algorithm
double Dijkstra(int graph[6][6],int source){
    int time[6];                            
    bool marked_arr[6];
      
    for(int k = 0; k<6; k++){
        time[k] = INT_MAX;
        marked_arr[k] = false;    
    }
    
    time[source] = 0;            
    
    for(int j = 0; j<6; j++){
        int min = minimum_distance(time,marked_arr); 
        marked_arr[min] = true;
        for(int k = 0; k<6; k++){
            if(!marked_arr[k] && time[min]!=INT_MAX && graph[min][k] && time[min]+graph[min][k]<time[k])
                time[k] = time[min] + graph[min][k];
        }
    }

    int sum = 0;
    cout << "\n--- source city = " << source << "---" << endl;
    // print the shortest time from source city to each city
    for(int i = 0; i<6; i++){ 
        cout << "Shortest time to City " << i << " -> " << time[i] << endl;
        sum += time[i];
    }
    double average = (double)sum/5;
    return average;
}

int main(){
    //graph according to the given scenario
    int graph[6][6]={
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};
    
    double min_avg = INT_MAX;
    for (int j = 0; j < 6; j++){
        double average = Dijkstra(graph,j);
        cout << "Average time: " << average << endl;
        if (average < min_avg){
            min_avg = average;
        }
    }
    cout << "\nMinimum average time: " << min_avg << endl;


    return 0;                           
}