#include "MovingAverage.h"
#include <math.h>

/**
 * @brief Adds a new datum and (if the window is full) removes the oldest datum.
 * @param value The new datum to add.
 */
void MovingAverage::addSample(double value)
    {
    // Don't allow strang floating point numbers that will mess up the maths.
    if (std::isnan(value) || std::isinf(value))
        {
        return;
        }
    if (mValues.size() >= mWindowSize)
        {
        // Remove the oldest element from the front of the vector
        mValues.erase(mValues.begin());
        }
    // Add new element at the end of the vector
    mValues.push_back(value);
    }

/**
 * @brief gets the number of samples in the moving average window.
 * Initially this will be zero and will increase as data are added up to the window size.
 */
int MovingAverage::getCount() const
    {
    return mValues.size();
    }

/**
 * @brief Gets the arithmetic mean of all the samples in the moving average window.
 * @return The mean average of the samples in the moving average window.
 */
double MovingAverage::getMean() const
    {
    auto size = mValues.size();
    if (size == 0)
        {
        return 0;
        }
    double sum = 0;
    for (auto value : mValues)
        {
        sum += value;
        }
    return sum / size;
    }

/**
 * @brief Gets the standard deviation of all the samples in the moving average window.
 * @return The standard deviation of the samples in the moving average window.
 */
double MovingAverage::getStandardDeviation() const
    {
    auto size = mValues.size();
    if (size == 0)
        {
        return 0;
        }
    double mean = MovingAverage::getMean();
    double sum = 0;
    for (auto sample : mValues)
        {
        auto variance = sample - mean;
        sum += variance * variance;
        }
    return sqrt(sum / size);
    }