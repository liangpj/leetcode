#include "../header.h"

/**
There are N gas stations along a circular route,
where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas
to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
*/

/* 有两个很关键的点
1. 如果a->b->c, 如果a不能到达c,那么b也不能到达c。(这里隐含着a能到达b, 及cost(a) < gast(a))
因为 gas(a) + gas(b) + gas(c) < cost(a) + cost(b) + cost(c)
cost(b) + cost(c) > gas(b) + gas(c) + (gas(a) - cost(a)) > gas(b) + gas(c)
2. 如果能够从a点出发到达a点那么肯定有。总的cost要小于总的gas
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int leftGas = 0, diff = 0;
    int startPoint = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        int left = gas[i] - cost[i];
        if (leftGas >= 0 )
        {
            leftGas += left;
        }
        else
        {
            leftGas = left;
            startPoint = i;
        }
        diff += left;
    }
    return (diff >= 0 ? startPoint : -1);

}

int gas_main()
{
    vector<int> cost = {5};
    vector<int> gas = {4};
    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}
