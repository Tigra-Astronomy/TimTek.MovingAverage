#include "MovingAverage.h"

/**
 * @brief Gets the arithmetic mean of samples, after rejecting values that are
 * more than the specified number of standard deviations from the mean.
 * @return The average of the samples after rejecting outliers.
 */

double MovingAverageRejectOutliers::getMean() const
    {
    double mean = MovingAverage::getMean(); // mean of all samples including outliers
    double stdDev = getStandardDeviation();
    double lowerBound = mean - (rejectionThreshold * stdDev);
    double upperBound = mean + (rejectionThreshold * stdDev);
    double clippedSum = 0.0;
    int usedSamples = 0.0;
    for (auto sample : mValues)
        {
        if (sample < lowerBound || sample > upperBound)
            continue; // Sample rejected because variance is too great
        clippedSum += sample;
        usedSamples++;
        }
    // Avoid division by zero if there are no samples.
    if (usedSamples == 0)
        return 0.0;
    auto result = clippedSum / usedSamples;
    return result;
    }