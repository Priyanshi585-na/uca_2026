#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames)
{
    int frames[num_frames];
    int last_used[num_frames]; // Timestamp array
    int page_faults = 0;

    // Initialize empty slots
    for (int i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++)
    {
        int page = page_requests[time];
        bool hit = false;

        for (int i = 0; i < num_frames; i++)
        {
            if (frames[i] == page)
            {
                hit = true;
                last_used[i] = time;
                break;
            }
        }

        if (!hit)
        {
            page_faults++;

            int idx = -1;

            for (int i = 0; i < num_frames; i++)
            {
                if (frames[i] == -1)
                {
                    idx = i;
                    break;
                }
            }

            if (idx == -1)
            {
                idx = 0;
                for (int j = 0; j < num_frames; j++)
                {
                    if (last_used[j] < last_used[idx])
                    {
                        idx = j;
                    }
                }
            }
            last_used[idx] = time;
            frames[idx] = page;
        }
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main()
{
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_requests = sizeof(requests) / sizeof(requests[0]);

    simulate_lru(requests, num_requests, 3);
    return 0;
}
