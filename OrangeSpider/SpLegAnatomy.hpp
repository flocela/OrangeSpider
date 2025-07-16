#ifndef SpLegAnatomy_hpp
#define SpLegAnatomy_hpp

class SpLegAnatomy
{
    public:
    
    SpLegAnatomy(float topLength, float midLength, float botLength);
    
    float getTopLength();
    float getMidLength();
    float getBotLength();

    private:
    
    float _topLength = 0.0f;
    float _midLength = 0.0f;
    float _botLength = 0.0f;

};

#endif /* SpLegAnatomy_hpp */
