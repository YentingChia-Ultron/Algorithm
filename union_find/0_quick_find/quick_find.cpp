#include "quick_find.hpp"
#include <vector>

UF::UF(int n)
{
    for(int i=0;i<n;i++)
        id.push_back(i);
    component=n;
}

int UF::getComponent()
{
    return component;
}

int UF::find(int p)
{
    if(p<id.size())
        return id[p];
    return -1;
}

bool UF::connected(int p, int q)
{
    if((p>=id.size())||(q>=id.size()))
        return false;
    return (id[p]==id[q]);
}

void UF::unionTwo(int p, int q)
{
    if((p>=id.size())||(q>=id.size())) return;
    if(id[p]==id[q]) return;
    for(int i=0;i<id.size();i++)
        if(id[i]==id[p])
            id[i]=id[q];
    component--;
}
