/*
EECS 348 Lab 5
Tatum Morris 
3062485
Description: Take in an array of numbers and print out various information of sales data relating to the given numbers and months. 
Date: 10/12/2023
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void salesReport(float* salesData, char** months) {
    printf("Monthly sales report for 2022:\n\n\n");
    printf("\tMONTH\tSALES\n\n");
    int i;
    for(i = 0; i < 12; i++) {
        printf("%s\t", months[i]);
        printf("$%.2f\n", salesData[i]);
    }
}

void MinMaxAverage(float* salesData, char** months){
    float sum = 0, min = salesData[0], max = salesData[0];
    int min_month, max_month;
    int i;
    for(i = 0; i < 12; i++) {
        sum = sum + salesData[i];
        if (salesData[i] < min){
            min = salesData[i];
            min_month = i;
        }
        if (salesData[i] > max){
            max = salesData[i];
            max_month = i;
        }
    }
    float average = sum/12;
    printf("\n\n\nSales Summary: \n");
    printf("Minimum sales: \t$%.2f\t(%s)\n", min, months[min_month]);
    printf("Maximum sales: \t$%.2f\t(%s)\n", max, months[max_month]);
    printf("Average sales: \t$%.2f\n", average);
}

void MovingAverage(float* salesData, char** months) {
    printf("\n\n\nSix-Month Moving Average Report: \n");
    int i;
    for (i = 0; i < 7; i++) {
        float movingAvg = (salesData[i] + salesData[i + 1]+ salesData[i + 2]+ salesData[i + 3]+ salesData[i + 4]+ salesData[i + 5]) / 6;
        printf("%s\t - \t%s\t", months[i], months[i+5]);
        printf("$%.2f\n",movingAvg);
    }
}


void HighToLow(float* salesData, char** months) {
    printf("\n\n\nSales Report (Highest to Lowest): \n\n");
    printf("\tMonth\tSales\n\n");  
    int i,j;
    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            if(salesData[j] > salesData[i]){
                float temp = salesData[i];
                char* temp_month = months[i];
                salesData[i] = salesData[j];
                months[i] = months[j];
                salesData[j] = temp;
                months[j] = temp_month;
            }
        }
    }
    for (i = 0; i < 12; i++){
        printf("\t%s\t$%.2f\n", months[i], salesData[i]);
    }
}



int main() {
    float numbers[] = { 23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char *months[12]= {"January","Feburary","March","April","May","June","July","August","September","October","November","December"};
    
    salesReport(numbers, months);
    MinMaxAverage(numbers, months);
    MovingAverage(numbers, months);
    HighToLow(numbers, months);

    return 0;
}
