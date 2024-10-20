#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TALENT_DIFF 0.5
#define BET_AMOUNT 5.0
#define BET_WIN_GAIN 1.5
#define WIN_THRESHOLD 1000.0
#define TIME_LIMIT 30 // in seconds

// Function prototypes
int simulate_match(float talent1, float talent2);
void simulate_betting_until_threshold(float talent1, float talent2, float win_threshold, int time_limit);

int simulate_match(float talent1, float talent2)
{
    float chance = (float)rand() / RAND_MAX;
    float talent_diff = TALENT_DIFF; // 50% chance for the higher talent player to win

    if (talent1 > talent2)
    {
        return chance < talent_diff ? 1 : 0;
    }
    else
    {
        return chance < talent_diff ? 0 : 1;
    }
}

void simulate_betting_until_threshold(float talent1, float talent2, float win_threshold, int time_limit)
{
    float income = 0;
    int bet_count = 0;
    time_t start_time = time(NULL);
    time_t last_print_time = start_time;

    while (income < win_threshold)
    {
        if (talent1 > talent2)
        {
            if (simulate_match(talent1, talent2))
            {
                income += BET_WIN_GAIN; // Win: get $1.5 back
            }
            else
            {
                income -= BET_AMOUNT; // Lose: get $0 back, net loss $5
            }
        }
        else
        {
            if (simulate_match(talent2, talent1))
            {
                income += BET_WIN_GAIN; // Win: get $1.5 back
            }
            else
            {
                income -= BET_AMOUNT; // Lose: get $0 back, net loss $5
            }
        }

        bet_count++;

        // Print current status every second
        if (difftime(time(NULL), last_print_time) >= 1)
        {
            printf("Current Betting Income: $%.2f\n", income);
            printf("Total Bets Made: %d\n", bet_count);
            last_print_time = time(NULL);
        }

        // Check if time limit is reached
        if (difftime(time(NULL), start_time) > time_limit)
        {
            printf("Time limit reached. Betting stopped.\n");
            printf("Final Betting Income: $%.2f\n", income);
            printf("Total Bets Made: %d\n", bet_count);
            return;
        }

        // Check if win threshold is reached
        if (income >= win_threshold)
        {
            printf("Win threshold reached. Betting stopped.\n");
            printf("Final Betting Income: $%.2f\n", income);
            printf("Total Bets Made: %d\n", bet_count);
            return;
        }
    }
}

int main()
{
    srand(time(NULL));

    // Example talents for two players
    float talent1 = 0.8;
    float talent2 = 0.6;

    // Simulate betting until threshold
    simulate_betting_until_threshold(talent1, talent2, WIN_THRESHOLD, TIME_LIMIT);

    return 0;
}