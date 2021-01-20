#include <iomanip>
#include <iostream>

#include "tools.h"
#include "graph.h"

using namespace std;

namespace sdds
{
#define GRAPH_WIDTH 65

    void printGraph(int samples[], int noOfSamples)
    {
        int max = findMax(samples, noOfSamples);
        line(GRAPH_WIDTH + 10, " Graph ");
        for (int i = 0; i < noOfSamples; i++)
        {
            printBar(samples[i], max);
        }
        line(GRAPH_WIDTH + 10);
    }

    void printBar(int val, int max)
    {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++)
        {
            cout << "*";
        }
        cout << " " << setw(GRAPH_WIDTH + 6 - barlength) << setiosflags(ios::left) << val << "|" << endl;
    }

    void getSamples(int samples[], int noOfSamples)
    {
        int i;
        for (i = 0; i < noOfSamples; i++)
        {
            line(28);
            cout << "\\ " << (i + 1) << "/" << setw(2) << setiosflags(ios::left) << noOfSamples
                 << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }

    int findMax(int samples[], int noOfSamples)
    {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++)
        {
            if (max < samples[i])
                max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }
}
