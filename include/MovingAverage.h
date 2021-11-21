
#pragma once
#include <vector>

class MovingAverage
{
public:
    MovingAverage(size_t windowSize) : mWindowSize(windowSize) { mValues.reserve(windowSize); }
    void addSample(double value);
    virtual double getMean() const;
    double getStandardDeviation() const;
    int getCount() const;

protected:
    size_t mWindowSize;
    std::vector<double> mValues;
};

class MovingAverageRejectOutliers : public MovingAverage
{
public:
    MovingAverageRejectOutliers(size_t windowSize, double standardDeviations) : MovingAverage(windowSize),
                                                                                rejectionThreshold(standardDeviations) {}

    double getMean(void) const override;

private:
    double rejectionThreshold;
};
