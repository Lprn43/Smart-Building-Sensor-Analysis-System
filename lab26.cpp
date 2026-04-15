#include <iostream>
#include <iomanip>
using namespace std;
using namespace std;
const int ROOM = 4;
const int FLOOR = 5;
const int HOUR = 8;
double average(const double data[], int n);
double average(const int data[], int n);
int abnormalCount(const double temp[], int n, double minLimit, double ustLimit);
void printWarning(const double temp[], int n, double min, double ust);
void floorReport(const double templar[][4], int FLOORCount);
int maxIndex(const double data[], int n);
void energyAvg(const double hafta1[],const double hafta2[],int n);
int main() 
{
    double temp[] = {21.5, 22.0, 25.5, 29.3, 30.1, 27.8, 23.0, 21.0};

    double FLOORROOM[FLOOR][ROOM] = {
    {22.1, 23.4, 21.8, 24.0},
    {20.5, 19.8, 21.2, 20.9},
    {25.6, 26.2, 24.8, 25.1},
    {18.2, 17.9, 18.5, 19.0},
    {23.0, 22.8, 23.5, 22.6}
    };
    double co2[] = {412.5, 680.3, 1250.8, 520.1, 890.4};
    double thisWeek[] = {120.5, 118.3, 125.7, 122.1, 119.8, 131.2, 128.6};
    double lastWeek[] = {115.2, 117.0, 119.8, 121.5, 118.4, 125.3, 124.1};
    cout << "Average Temperature:" << average(temp,sizeof(temp)/sizeof(temp[0])) << endl;
    cout << "Abnormal Value Count:" << abnormalCount(temp,sizeof(temp)/sizeof(temp[0]),18,28) << endl;
    printWarning(temp,sizeof(temp)/sizeof(temp[0]),18,28);
    floorReport(FLOORROOM,FLOOR);
    cout << "!! WARNING !! Room With The Most CO2 Value: " << maxIndex(co2,sizeof(co2)/sizeof(co2[0])) << ".ROOM " << co2[maxIndex(co2,sizeof(co2)/sizeof(co2[0]))] << "ppm" << endl;
    energyAvg(lastWeek,thisWeek,7);
    return 0;
}
double average(const int data[], int n)
{
    double avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += data[i];
    }
    avg /= n;
    cout << "INT" << endl;
    return avg;
}
double average(const double data[], int n)
{
    double avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += data[i];
    }
    avg /= n;
    cout << "DOUBLE" << endl;
    return avg;
}
int abnormalCount(const double temp[], int n, double minLimit, double ustLimit)
{
    int abnormal = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] > ustLimit || temp[i] < minLimit)
        {
           abnormal++;
        }
        
    }
    return abnormal;
}
void printWarning(const double temp[], int n, double min, double ust)
{
    for (int i = 0; i < n; i++)
    {
        if (temp[i] > ust || temp[i] < min)
        {
           cout << "!!! WARNING !!! Temperature Anomaly Detected In " << i+1 << ". Floor (" << temp[i] << "C)" << endl; 
        }
    }
}
void floorReport(const double templar[][4], int FLOORCount)
{
    for (int i = 0; i < FLOORCount; i++)
    {   
        double avg = 0;
        for (int j = 0; j < ROOM; j++)
        {
            avg += templar[i][j];
        }
        avg /= ROOM;
        cout << i+1 << ". Floor Temperature Average :" << avg << endl;
    }
}
int maxIndex(const double data[], int n)
{
    int max;
    int compare = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] > compare)
        {
            max = i;
            compare = data[i];
        }
        
    }
    return max;
}
void energyAvg(const double hafta1[],const double hafta2[],int n)
{
    double w1avg = 0,w2avg = 0;
    double diff;
    for (size_t i = 0; i < n; i++)
    {
        w1avg += hafta1[i];
        w2avg += hafta2[i];
    }
    w1avg /= n;
    w2avg /= n;
    diff = w1avg - w2avg;
    double percentage;
    percentage = diff*100/w1avg;
    if (diff < 0)
    {
        cout << "Energy Consumption Increased %" << setprecision(3) << -percentage <<endl;
    }
    else
    {
        cout << "Energy Consumption Decreased %" << setprecision(3) << percentage <<endl;
    }
}