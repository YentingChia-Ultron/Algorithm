#ifndef quick_find_hpp
#define quick_find_hpp
#include <vector>

class UF
{
private:
    int component;
    std::vector<int>id;
public:
    UF(int n);
    int getComponent();
    int find(int p);
    bool connected(int p, int q);
    void unionTwo(int p, int q);
    
};
#endif /* quick_find_hpp */
