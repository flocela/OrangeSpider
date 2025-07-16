#ifndef SpLegAngles_hpp
#define SpLegAngles_hpp

class SpLegAngles
{
    public:

    SpLegAngles(float top_r, float mid_r, float bottom_r);
    
    float getTopAngle();
    float getMidAngle();
    float getBotAngle();
    
    private:
    
    float _topAngle_r = 0.0f;
    float _midAngle_r = 0.0f;
    float _botAngle_r = 0.0f;

};

#endif /* SpLegAngles_hpp */
