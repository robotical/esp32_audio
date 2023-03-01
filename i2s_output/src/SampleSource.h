#ifndef __sample_source_h__
#define __sample_source_h__

#include <Arduino.h>

typedef struct
{
    int16_t sample1;
    int16_t sample2;
} Frame_t;

//typedef uint8_t Frame_t;

/**
 * Base class for our sample generators
 **/
class SampleSource
{
public:
    virtual int sampleRate() = 0;
    // This should fill the samples buffer with the specified number of frames
    // A frame contains a LEFT and a RIGHT sample. Each sample should be signed 16 bits
    virtual void getFrames(Frame_t *frames, int number_frames) = 0;
    virtual int bitDepth() = 0;
};

#endif