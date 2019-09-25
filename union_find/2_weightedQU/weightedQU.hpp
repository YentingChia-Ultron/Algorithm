#ifndef weightedQU_hpp
#define weightedQU_hpp
#include <vector>

class weightedQU
{
private:
    int component;
    std::vector<int>id;
    std::vector<int>weight;
public:
    weightedQU(int n);
    int getComponent();
    int root(int p);
    bool connected(int p, int q);
    void unionTwo(int p, int q);
    int getWeight(int p);
    
};
#endif /* weightedQU_hpp */
