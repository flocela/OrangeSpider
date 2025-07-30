#ifndef SpLegAnatomy_hpp
#define SpLegAnatomy_hpp

class SpLegAnatomy
{
    public:
    
    SpLegAnatomy(float topLength, float midLength, float botLength);
    bool operator== (const SpLegAnatomy& o) const;
    
    float getTopLength() const;
    float getMidLength() const;
    float getBotLength() const;

    private:
    
    float _topLength = 0.0f;
    float _midLength = 0.0f;
    float _botLength = 0.0f;

};

#endif /* SpLegAnatomy_hpp */
