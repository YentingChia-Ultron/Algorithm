#include "weightedQU.hpp"
#include <vector>

weightedQU::weightedQU(int n)
{
    weight.resize(n, 1);
    for(int i=0;i<n;i++)
        id.push_back(i);
    component=n;
}

int weightedQU::getComponent()
{
    return component;
}

int weightedQU::root(int p)
{
    if(p>=id.size()) return -1;
    while(id[p]!=p) p=id[p];
    return p;
}

bool weightedQU::connected(int p, int q)
{
    if((p>=id.size())||(q>=id.size()))
        return false;
    return (root(p)==root(q));
}

void weightedQU::unionTwo(int p, int q)
{
    if((p>=id.size())||(q>=id.size())) return;
    if(connected(p,q)) return;
    int rp=root(p),rq=root(q);
    if(weight[rp]<weight[rq])
    {
        id[rp]=rq;
        weight[rq]+=weight[rp];
    }
    else
    {
        id[rq]=rp;
        weight[rp]+=weight[rq];
    }
    component--;
}

int weightedQU::getWeight(int p)
{
    return weight[p];
}
