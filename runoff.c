#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char name[20];
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

//trackers
int current_round = 1;
int winner_count = 0;

// Function prototypes
bool vote(int voter, int rank, char name[20]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of/ candidates
    candidate_count = argc-1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for(int j=0;j<strlen(argv[i+1]);j++)
	{
		candidates[i].name[j] = argv[i + 1][j];
	}
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    printf("Number of voters: ");
    scanf("%d", &voter_count);

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[20];
	    printf("Rank %i: ", j+1);
	    scanf("%s", name);


            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    tabulate();

    for(int i=0;i<voter_count;i++)
    {
	    for(int j=0;j<candidate_count;j++)
	    {
		    printf("%d", preferences[i][j]);
	    }
	    printf("\n");
    }

    /*while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

	// Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;*/
}

// Record preference if vote is valid
bool vote(int voter, int rank, char name[20])
{
    for(int i=0;i<candidate_count;i++)
    {
	if(strcmp(name, candidates[i].name)==0)
	{
		preferences[voter][rank] = i;
		return true;
	}
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for(int i=0;i<voter_count;i++)
    {

		if(candidates[j].eliminated == false)
		{
			candidates[j].votes += 1;
		}
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for(int i=0;i<candidate_count;i++)
    {
	if(candidates[i].votes > (voter_count)/2)
	{
		winner_count +=1;
	}
    }

    if(winner_count > 1)
    {

    }
//	    current_round +=1;
//	    return false;
    else
    {
	for(int i=0;i<candidate_count;i++)
	{
		printf("%s is the winner with %d votes", candidates[i].name, candidates[i].votes);
	}
	return true;
    }
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
	int min=candidates[0].votes;
    	for(int i=0;i<candidate_count;i++)
	{
		if(candidates[i].votes <= min)
		{
			min = candidates[i].votes;
		}
	}
	return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}
