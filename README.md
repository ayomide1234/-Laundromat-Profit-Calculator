# -Laundromat-Profit-Calculator
The program allows users to input data regarding the number of loads washed on each day and provides various key statistics to help owners make informed decisions.

Upon running the program, users are greeted with information about the lab and the purpose of the laundromat profit calculator. They are then prompted to enter the number of days they want to analyze, ensuring the input is valid and not negative.
The program dynamically allocates an array to store the number of loads washed on each day based on the user's input. It then asks the user to input the number of loads washed on each day, ensuring the values are within an acceptable range (0 to 35 loads per day).
The program proceeds to calculate and display essential metrics. First, it calculates and shows the average loads washed per day, giving laundromat owners an idea of the daily workload. Next, it calculates and displays the total loads dried and the average loads dried per day, which provides insights into dryer utilization.

To provide financial insights, the program calculates the total revenue generated during the specified period. It factors in the revenue from washing and drying each load, which assists owners in understanding their income generation.
The laundromat profit calculator goes a step further by determining the number of profitable days. It checks the revenue generated for each day against a predefined threshold for profitability (i.e., revenue >= $97). This information is crucial for owners to assess the overall financial health of their business.

Finally, the program identifies and displays the day with the highest number of loads washed. This information helps owners understand peak usage times and plan resources accordingly.
Upon completion of the calculations, the program releases the dynamically allocated memory for the data array, ensuring efficient memory usage.
In summary, the "Laundromat Profit Calculator" is a user-friendly and valuable tool for laundromat owners. It offers key insights into operational performance, revenue generation, and profitability, empowering owners to make informed decisions to optimize their business's success.
