#include "quick_union.hpp"
#include <vector>

QU::QU(int n)
{
    for(int i=0;i<n;i++)
        id.push_back(i);
    component=n;
}

int QU::getComponent()
{
    return component;
}

int QU::root(int p)
{
    if(p>=id.size()) return -1;
    while(id[p]!=p) p=id[p];
    return p;
}

bool QU::connected(int p, int q)
{
    if((p>=id.size())||(q>=id.size()))
        return false;
    return (root(p)==root(q));
}

void QU::unionTwo(int p, int q)
{
    if((p>=id.size())||(q>=id.size())) return;
    if(connected(p,q)) return;
    id[root(p)]=root(q);
    component--;
}
