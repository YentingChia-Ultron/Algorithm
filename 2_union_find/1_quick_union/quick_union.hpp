#ifndef quick_union_hpp
#define quick_union_hpp
#include <vector>

class QU
{
private:
    int component;
    std::vector<int>id;
public:
    QU(int n);
    int getComponent();
    int root(int p);
    bool connected(int p, int q);
    void unionTwo(int p, int q);
    
};
#endif /* quick_union_hpp */
