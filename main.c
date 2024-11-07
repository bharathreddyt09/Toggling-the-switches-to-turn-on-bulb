#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to toggle the switch at index i using Grey code technique
void toggle_grey(int *switches, int i) {
    switches[i] = 1 - switches[i];
}

// Function to check if all switches are closed
bool all_closed(int *switches, int n) {
    for (int i = 0; i < n; i++) {
        if (switches[i] == 0) {
            return false;
        }
    }
    return true;
}

// Function to print the state of all switches
void print_switches(int *switches, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", switches[i]);
    }
    printf("\n");
}

int main() {
    int n;  // Number of switches
    
    // Take the number of switches from the user
    printf("Enter the number of switches: ");
    scanf("%d", &n);

    int switches[n];
    
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize all switches to a random state
    for (int i = 0; i < n; i++) {
        switches[i] = rand() % 2;  // Randomly assign 0 (open) or 1 (closed)
    }

    int presses = 0;  // Initialize the number of button presses

    // Print initial state of switches
    printf("Initial state of switches: ");
    print_switches(switches, n);

    // Iterate over each switch and toggle it using Grey code technique
    for (int i = 0; i < n; i++) {
        if (switches[i] == 0) {  // Only toggle if the switch is open (0)
            presses++;
            toggle_grey(switches, i);
            
            // Print the state of switches after each toggle
            printf("After pressing button %d, state of switches: ", presses);
            print_switches(switches, n);
        }

        // Check if all switches are closed
        if (all_closed(switches, n)) {
            break;
        }
    }

    // Output the results
    printf("Minimum button presses needed: %d\n", presses);
    printf("Final state of switches: ");
    print_switches(switches, n);

    // Check if all switches are closed and print the bulb status
    if (all_closed(switches, n)) {
        printf("The bulb is ON.\n");
    } else {
        printf("The bulb is OFF.\n");
    }

    return 0;
}
