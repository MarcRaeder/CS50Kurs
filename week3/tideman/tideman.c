#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

bool locked[MAX][MAX];
int preferences[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
} pair;

string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int candidate_count;
int pair_count;

bool has_cycle(int winner, int loser);
bool vote(int rank, string name, int ranks[]);
void add_pairs(void);
void lock_pairs(void);
void print_winner(void);
void record_preferences(int ranks[]);
void sort_pairs(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool candidate_exists = strcmp(candidates[i], name) == 0;
        if (candidate_exists)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }

    return;
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            bool compare_preferences = preferences[i][j] != preferences[j][i];
            if (compare_preferences)
            {
                pair p;
                if (preferences[i][j] > preferences[j][i])
                {
                    p.winner = i;
                    p.loser = j;
                }
                else
                {
                    p.winner = j;
                    p.loser = i;
                }

                pairs[pair_count++] = p;
            }
        }
    }

    return;
}

void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int max_index = i;
        int current_strength = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];

        for (int j = i + 1; j < pair_count; j++)
        {
            int temp_strength = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if (temp_strength > current_strength)
            {
                max_index = j;
                current_strength = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            }
        }

        pair temp = pairs[max_index];
        pairs[max_index] = pairs[i];
        pairs[i] = temp;
    }

    return;
}

bool has_cycle(int winner, int loser)
{
    while (winner != -1 && winner != loser)
    {
        bool found = false;

        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][winner])
            {
                found = true;
                winner = i;
            }
        }

        if (!found)
        {
            winner = -1;
        }
    }

    if (winner == loser)
    {
        return true;
    }

    return false;
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!has_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool found_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                found_source = false;
                break;
            }
        }

        if (found_source)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    
    return;
}
