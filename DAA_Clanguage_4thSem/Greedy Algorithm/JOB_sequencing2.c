#include <stdio.h> // Include standard input/output library

// Function prototype for the job scheduling function
void job(int profit[], int deadline[], int n, int max_deadline);

int main()
{
    int profit[20], deadline[20], n, max_deadline;

    // Prompt the user to enter the number of jobs
    printf("Enter number of jobs: ");
    // Read the number of jobs from user input
    scanf("%d", &n);

    // Prompt the user to enter the profits in descending order
    printf("Enter profits in descending order:\n");
    // Read the profits into the profit array
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    // Prompt the user to enter the deadlines corresponding to the profits
    printf("Enter deadlines corresponding to the profits:\n");
    // Read the deadlines into the deadline array
    for (int i = 0; i < n; i++) {
        scanf("%d", &deadline[i]);
    }

    // Prompt the user to enter the maximum deadline
    printf("Enter maximum deadline: ");
    // Read the maximum deadline from user input
    scanf("%d", &max_deadline);

    // Call the job scheduling function with the input data
    job(profit, deadline, n, max_deadline);

    return 0; // Return 0 to indicate successful execution
}

// Function to perform job scheduling
void job(int profit[], int deadline[], int n, int max_deadline)
{
    int schedule[20] = {0}; // Initialize schedule array with 0s, meaning no jobs are scheduled initially
    int total_profit = 0; // Initialize total profit to 0

    // Iterate through each job
    for (int i = 0; i < n; i++) {
        // Try to schedule the job before its deadline
        for (int j = deadline[i] - 1; j >= 0; j--) {
            if (schedule[j] == 0) { // Check if the slot is available
                schedule[j] = profit[i]; // Schedule the job in the available slot
                total_profit += profit[i]; // Add the profit to the total profit
                break; // Exit the loop once the job is scheduled
            }
        }
    }

    // Print the total profit
    printf("\nTotal profit: %d\n", total_profit);

    // Print the job schedule
    printf("Job schedule (by profit):\n");
    for (int i = 0; i < max_deadline; i++) {
        // Print the profit for each scheduled job in its respective slot
        printf("Slot %d: %d\n", i + 1, schedule[i]);
    }
}