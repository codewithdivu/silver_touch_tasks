#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int main()
{

    vector<Job> jobs = {
        {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};

    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.profit > b.profit; });

    int n = jobs.size();

    int parent[n + 1];
    fill(parent, parent + n + 1, -1);

    int maxDeadline = 0;
    for (const Job &job : jobs)
    {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<Job> result;

    for (const Job &job : jobs)
    {
        int availableSlot = find(parent, job.deadline);

        if (availableSlot > 0)
        {
            result.push_back(job);
            Union(parent, availableSlot, availableSlot - 1);
        }
    }

    int totalProfit = 0;
    cout << "Selected jobs: ";
    for (const Job &job : result)
    {
        cout << job.id << " ";
        totalProfit += job.profit;
    }
    cout << endl;
    cout << "Total profit: " << totalProfit << endl;

    return 0;
}
