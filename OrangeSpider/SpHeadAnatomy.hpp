#ifndef SpHeadAnatomy_hpp
#define SpHeadAnatomy_hpp

class SpHeadAnatomy
{

    public:
    
    SpHeadAnatomy(float height, float radius);
    
    float getHeight();
    float getRadius();
    
    private:
    
    float _height;
    float _radius;

};

#endif /* SpHeadAnatomy_hpp */
