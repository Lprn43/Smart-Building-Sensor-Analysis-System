This program coded around this requirements.
📌 SCENARIO: Smart Building Sensor Analysis System
A technology company has installed an IoT (Internet of Things) based sensor system in a 5-story building it manages. Each floor has 4 rooms; temperature, humidity, CO2, and energy consumption data are transmitted to a central system every hour. Software engineers process this data to:
• Detect abnormal temperature values ​​(< 18°C ​​or > 28°C) and generate alerts
• Calculate the average temperature on a floor basis and make heating/cooling decisions
• Report the percentage change in daily energy consumption compared to the previous week
• Detect the room with the highest CO2 value and trigger the ventilation system
Since the data will be processed without modification in this system, const accuracy is critical. An incorrect const error can lead to the corruption of sensor data in the production environment.

📌 FUNCTIONS YOU NEED TO WRITE
1. double average(const double data[], int n) → Returns the average of the array elements (const: data
cannot be changed)
2. double average(const int data[], int n) → Same function for int array (overloading)
3. int anomalousCount(const double temperature[], int n, double lowerLimit, double upperLimit) → Returns the number of elements outside the range
4. void printWarning(const double temperature[], int n, double lower, double upper) → Prints anomalous values ​​to the screen along with their index
5. void floorReport(const double temperatures[][4], int floorCount) → 2D array; average of each floor prints the temperature
6. int maxIndex(const double data[], int n) → Returns the index of the largest element (for CO2 detection)
