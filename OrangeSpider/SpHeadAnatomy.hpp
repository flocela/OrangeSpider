#ifndef SpHeadAnatomy_hpp
#define SpHeadAnatomy_hpp

class SpHeadAnatomy
{

    public:
    
    SpHeadAnatomy(float height, float radius);
    bool operator== (const SpHeadAnatomy& o) const;
    
    float getHeight();
    float getRadius();
    
    private:
    
    float _height;
    float _radius;

};

#endif /* SpHeadAnatomy_hpp */
