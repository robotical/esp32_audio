#include <math.h>
#include "SinWaveGenerator.h"

SinWaveGenerator::SinWaveGenerator(int sample_rate, int frequency, float magnitude)
{
    m_sample_rate = sample_rate;
    m_frequency = frequency;
    m_magnitude = magnitude;
    m_current_position = 0;
    m_bit_depth = 16;
}

void SinWaveGenerator::getFrames(Frame_t *frames, int number_frames)
{
    float full_wave_samples = m_sample_rate / m_frequency;
    float step_per_sample = M_TWOPI / full_wave_samples;
    // fill the buffer with data from the file wrapping around if necessary
    for (int i = 0; i < number_frames*2; i++)
    {
        if (!(i%2)){
            frames[i>>1].sample1 = 16384 * m_magnitude * sin(m_current_position);
        } else {
            frames[i>>1].sample2 = 16384 * m_magnitude * sin(m_current_position);
        }
        m_current_position += step_per_sample;
        // wrap around to maintain numerical stability
        if (m_current_position > M_TWOPI)
        {
            m_current_position -= M_TWOPI;
        }
    }
}
