#ifndef SpLegAngles_hpp
#define SpLegAngles_hpp

class SpLegAngles
{
    public:

    SpLegAngles(float top_r, float mid_r, float bottom_r);
    bool operator==(const SpLegAngles& o) const;
    
    // Connection angle connects spider head to spider leg.
    float getConnectionAngle() const;
    float getMid1Angle() const;
    float getMid2Angle() const;
    
    private:
    
    float _connectionAngle_r = 0.0f;
    float _mid1Angle_r = 0.0f;
    float _mid2Angle_r = 0.0f;

};

#endif /* SpLegAngles_hpp */
