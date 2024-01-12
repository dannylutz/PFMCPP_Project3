/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct SimpleOscillator
{

    SimpleOscillator();

    double frequency = 440.0;
    unsigned int waveform = 0;
    int octave = 0;
    double drift, output;


    void setOscillatorFrequency(double frequency);
    void sendOutputToOtherDevices(double output);
    void acceptControlVoltage(bool externalCV);
};

SimpleOscillator::SimpleOscillator(): drift(0.213), output(0.707)
{
    std::cout << "SimpleOscillator being constructed!\n" << std::endl;
}

void SimpleOscillator::setOscillatorFrequency(double oscFrequency)
{
    frequency = oscFrequency;
}

void SimpleOscillator::sendOutputToOtherDevices(double extOutput)
{
    output = extOutput;
}

void SimpleOscillator::acceptControlVoltage(bool externalCV)
{
    if (externalCV)
    {
        std::cout << "external CV enabled\n" << std::endl;
    }
    else
    {
        std::cout << "external CV not disabled\n" << std::endl;
    }
}

struct SamplePlayer
{
    SamplePlayer();

    int transpose = 0;
    bool loop = false;
    double sampleRate = 44100.0;
    int loopStart, loopEnd;

    struct Sample
    {
        Sample();

        std::string audioFile = "./samples/sample.wav\n";
        int channels = 2;
        int bitDepth = 16;
        double length;
        int index;
        SimpleOscillator oscillator;

        std::string printSampleInfo();
        void loadSample(std::string audioFile);
        void reduceBitDepth(int bitDepth, int bitDepthReduction = 2);
    };

    void modulateSampleRate(SimpleOscillator oscillator);    
    void playSample();
    void loopSample();
};

SamplePlayer::SamplePlayer(): loopStart(127900), loopEnd(865000)
{
    std::cout << "SamplePlayer being constructed!\n" << std::endl;
}


void SamplePlayer::Sample::loadSample(std::string audioFileToLoad)
{
    std::cout << "The sample " + audioFileToLoad + " has been loaded \n" << std::endl;
}

void SamplePlayer::playSample()
{
    std::cout << "Now playing the loaded sample\n" << std::endl;
}

void SamplePlayer::loopSample()
{
    loop = true;
    std::cout << "Looping file from sample number" + std::to_string(loopStart) + " to sample number " + std::to_string(loopEnd) << std::endl;
}

SamplePlayer::Sample::Sample(): length(2000.0), index(0)
{
    std::cout << "Sample being constructed!\n" << std::endl;
}

std::string SamplePlayer::Sample::printSampleInfo()
{
    std::string sampleInfo = " Sample file: " + audioFile +" Number of Channels: " + std::to_string(channels) + " Number of Bits: " + std::to_string(bitDepth) + " Sample Length: " + std::to_string(length) + " Sample Index: " + std::to_string(index) + "\n";

    return sampleInfo;
}

void SamplePlayer::Sample::reduceBitDepth(int depthOfBits, int reductionAmount)
{
    bitDepth = depthOfBits / reductionAmount;
}

void SamplePlayer::modulateSampleRate(SimpleOscillator oscillator)
{
    std::cout << "Sample rate of " + std::to_string(sampleRate) + " is being modulated by the simple oscillator's frequency of " + std::to_string(oscillator.frequency) + "and the simple oscillator's frequency. Also, bananas are berries and strawberries are not!!\n" << std::endl;
}

struct ADRAmpEnvelope
{
    ADRAmpEnvelope();

    double attack, decay, release;
    unsigned int polarity = 0;
    double amount = 0.707;

    void sendOutputToOtherDevices(double output);
    void applyEnvelopeToAudioInput(double input);
    void listenForTrigger();
};

ADRAmpEnvelope::ADRAmpEnvelope(): attack(0.012), decay(0.145), release(0.68)
{
    std::cout << "ADRAmpEnvelope being constructed!\n" << std::endl;
}

void ADRAmpEnvelope::sendOutputToOtherDevices(double outputAmount)
{
    amount = outputAmount;
}

void ADRAmpEnvelope::applyEnvelopeToAudioInput(double inputAmount)
{
    amount = inputAmount;
}

void ADRAmpEnvelope::listenForTrigger()
{
    std::cout << "The envelope generator is listening for trigger signal. While you're here -- did you know erogel is the world's lightest solid material? It's composed of 99.8% air and can support over 1,000 times its own weight\n" << std::endl;
}

struct SaturatingFilter
{
    SaturatingFilter();

    unsigned int filterType = 0;
    double cutoff = 1004.75;
    double resonance, drive, output;

    void setCutoff(double cutoff);
    void setDrive(double drive);
    void adjustOutputLevel(double output);
};

SaturatingFilter::SaturatingFilter(): resonance(0.99), drive(0.5), output(0.707)
{
    std::cout << "SaturatingFilter being constructed!\n" << std::endl;
}

void SaturatingFilter::setCutoff(double cutoffFq)
{
    cutoff = cutoffFq;
}

void SaturatingFilter::setDrive(double driveAmount)
{
    drive = driveAmount;
}

void SaturatingFilter::adjustOutputLevel(double outputAmount)
{
    output = outputAmount;
}

struct AudioInput
{
    AudioInput();

    double amplitude = 0.707;
    bool stereo = true;
    double hpfCutoff = 20.0;
    double saturation = 0.5;
    bool polarity;

    struct AudioInputProperties
    {
        AudioInputProperties();
        
        double sampleRate = 44100.0;
        int channels, bitDepth, bufferSize, deviceID;

        double getSampleRate();
        void setAudioDevice(int audioDeviceID);
        std::string getAudioProps(AudioInput audioInput);
    };

    void setInputAmplitude(double amplitude);
    void processInputStream(bool process);
    void invertInputPolarity(bool polarity);
};

AudioInput::AudioInput(): polarity(false)
{
    std::cout << "AudioInput being constructed!\n" << std::endl;
}

AudioInput::AudioInputProperties::AudioInputProperties(): channels(2), bitDepth(16), bufferSize(128), deviceID(0)
{
    std::cout << "AudioInputProperties being constructed!\n" << std::endl;
}

void AudioInput::setInputAmplitude(double amplitudeAmt)
{
    amplitude = amplitudeAmt;
}

void AudioInput::processInputStream(bool shouldProcess)
{
    if (shouldProcess)
    {
        std::cout << "A Lichtenberg figure is a branching, tree-like pattern that is created by the passage of high-voltage electrical discharges along the surface or through insulating materials. These figures can also appear on the skin of lightning strike victims\n" << std::endl;
    }
}

void AudioInput::invertInputPolarity(bool invert)
{
    if (invert)
    {
        polarity = true;
    }
    else
    {
        polarity = false;
    }
}

double AudioInput::AudioInputProperties::getSampleRate()
{
    return sampleRate;
}

void AudioInput::AudioInputProperties::setAudioDevice(int devID)
{
    deviceID = devID;
}

std::string AudioInput::AudioInputProperties::getAudioProps(AudioInput inputAudio)
{
    std::string audioProps = "Sample Rate: " + std::to_string(inputAudio.amplitude) + " Number of Channels: " + std::to_string(inputAudio.stereo) +
                             std::to_string(inputAudio.hpfCutoff) + " Resonance: " + std::to_string(inputAudio.saturation) + " Polarity: " + std::to_string(inputAudio.polarity) + "\n";

    return audioProps;
}

struct AudioChannel
{
    AudioChannel();

    double stereoPosition = 0.5;
    double channelVolume = 0.707;
    std::string channelName = "ch 1";
    bool channelMute;
    double reverbSend;

    void setVolume(double volume);
    void setStereoPosition(double position);
    void muteChannel(bool mute);
};

AudioChannel::AudioChannel(): channelMute(false), reverbSend(0.5)
{
    std::cout << "AudioChannel being constructed!\n" << std::endl;
}

void AudioChannel::setVolume(double vol)
{
    channelVolume = vol;
}

void AudioChannel::setStereoPosition(double strPosition)
{
    stereoPosition = strPosition;
}

void AudioChannel::muteChannel(bool mute)
{
    channelMute = mute;
}

struct ChannelEQ
{
    ChannelEQ();

    double highPassFrequency, highFrequencySelection, highFrequencyGain, lowFrequencySelection, lowFrequencyGain;

    void setHighPassFrequency(double highPassFrequency);
    void setLowFrequencySelection(double lowFrequencySelection);
    void setLowFrequencyGain(double lowFrequencyGain);
};

ChannelEQ::ChannelEQ(): highPassFrequency(20), highFrequencySelection(8.2), highFrequencyGain(0.5), lowFrequencySelection(245.45), lowFrequencyGain(1.2)
{
    std::cout << "ChannelEQ being constructed!\n" << std::endl;
}

void ChannelEQ::setHighPassFrequency(double hpFreq)
{
    highPassFrequency = hpFreq;
}

void ChannelEQ::setLowFrequencySelection(double lowFreqSel)
{
    lowFrequencySelection = lowFreqSel;
}

void ChannelEQ::setLowFrequencyGain(double lowFreqGain)
{
    lowFrequencyGain = lowFreqGain;
}

struct ChannelDynamics
{
    ChannelDynamics();

    double compressorThreshold, compressorRatio;
    double compressorAttack = 0.012;
    double compressorRelease = 0.68;
    double compressorMakeupGain = 0.5;

    void setCompressorThreshold(double compressorThreshold);
    void setCompressorAttack(double compressorAttack);
    void setCompressorMakeupGain(double compressorMakeupGain);
};

ChannelDynamics::ChannelDynamics(): compressorThreshold(-12.0), compressorRatio(1.5)
{
    std::cout << "ChannelDynamics being constructed!\n" << std::endl;
}

void ChannelDynamics::setCompressorThreshold(double compThreshold)
{
    compressorThreshold = compThreshold;
    std::cout << "Compressor threshold set to: " << compressorThreshold << std::endl;
}

void ChannelDynamics::setCompressorAttack(double compAttack)
{
    compressorAttack = compAttack;
}

void ChannelDynamics::setCompressorMakeupGain(double compMakeupGain)
{
    compressorMakeupGain = compMakeupGain;
}

struct Reverb
{
    Reverb();

    double reverbTime = 0.35;
    double reverbPreDelay = 0.012;
    double reverbDiffusion = 0.5;
    double reverbDamping = 0.5;
    double reverbOutput;

    void setReverbOutput(double reverbOutput);
    void setReverbTime(double reverbTime);
    void setReverbPreDelay(double reverbPreDelay);
};

Reverb::Reverb(): reverbOutput(0.707)
{
    std::cout << "Reverb being constructed!\n" << std::endl;
}

void Reverb::setReverbOutput(double reverbOut)
{
    reverbOutput = reverbOut;
}

void Reverb::setReverbTime(double verbTime)
{
    reverbTime = verbTime;
}

void Reverb::setReverbPreDelay(double verbPreDelay)
{
    reverbPreDelay = verbPreDelay;
}

struct AudioMixer
{
    AudioMixer();
    
    AudioInput audioInput;
    AudioChannel audioChannel;
    ChannelEQ channelEQ;
    ChannelDynamics channelDynamics;
    Reverb reverb;

    void positionAudioChannel(double position);
    void applyParallelEffects(std::string channelName, double amount);
    void processChannel(AudioInput audioInput);
};

AudioMixer::AudioMixer()
{
    std::cout << "AudioMixer being constructed!\n" << std::endl;
}
    
void AudioMixer::positionAudioChannel(double position)
{
    audioChannel.stereoPosition = position;
}

void AudioMixer::applyParallelEffects(std::string chName, double amt)
{
    if (audioChannel.channelName == chName)
    {
        audioChannel.reverbSend = amt;
    }
}

void AudioMixer::processChannel(AudioInput audioIn)
{
    audioIn.processInputStream(true);
}

/*
====================================================================
*/

int main()
{
    Example::main();
 
    SimpleOscillator osc;
    osc.setOscillatorFrequency(9.0210);
    osc.acceptControlVoltage(true);
    osc.sendOutputToOtherDevices(107.3);
    std::cout << "Setting Oscillator Frequency to " + std::to_string(osc.frequency) + " Hz\n" << std::endl;


    AudioInput audioInput;
    audioInput.processInputStream(true);
    audioInput.invertInputPolarity(false);
    audioInput.setInputAmplitude(3.9);
    std::cout << "Setting Input Amplitude to " + std::to_string(audioInput.amplitude) + " \n" << std::endl;

    SamplePlayer playa;
    playa.playSample();
    playa.loopSample();
    playa.modulateSampleRate(osc);
    

    SamplePlayer::Sample sampl;
    sampl.loadSample("./samples/snare.wav");
    sampl.printSampleInfo();
    std::cout << "Bit depth reduced to " + std::to_string(sampl.bitDepth) + " bits\n" << std::endl;
    
    AudioInput::AudioInputProperties audioInputProps;
    audioInputProps.getAudioProps(audioInput);
    audioInputProps.getSampleRate();
    audioInputProps.setAudioDevice(0);
    std::cout << "Audio Device sample rate is set to " + std::to_string(audioInputProps.sampleRate) + "\n" << std::endl;

    ADRAmpEnvelope envelope;
    envelope.listenForTrigger();
    envelope.sendOutputToOtherDevices(1080.12);
    envelope.applyEnvelopeToAudioInput(420.42);

    SaturatingFilter filta;
    filta.setCutoff(117.6);
    filta.adjustOutputLevel(11.76);
    filta.setDrive(1.073);
    std::cout << "Saturating Filter Cutoff frequency is set to " + std::to_string(filta.cutoff) + " Hz\n" << std::endl;
    
    AudioChannel audioChannel;
    audioChannel.setVolume(0.707);
    audioChannel.muteChannel(true);
    audioChannel.setStereoPosition(0.5);
    std::cout << "Audio Channel Volume is set to " + std::to_string(audioChannel.channelVolume) + " \n" << std::endl;
    
    ChannelEQ chanQ;
    chanQ.setHighPassFrequency(20.0);
    chanQ.setLowFrequencySelection(20.4);
    chanQ.setLowFrequencyGain(5.2);
    std::cout << "ChannelEQ High Pass Frequency is set to " + std::to_string(chanQ.highPassFrequency) + " Hz\n" << std::endl;

    ChannelDynamics chanDyn;
    chanDyn.setCompressorThreshold(-12.4);
    chanDyn.setCompressorAttack(0.012);
    chanDyn.setCompressorMakeupGain(0.5);
    std::cout << "ChannelDynamics Compressor Threshold is set to " + std::to_string(chanDyn.compressorThreshold) + " dB \n" << std::endl;

    Reverb reverb;
    reverb.setReverbOutput(0.707);
    reverb.setReverbTime(0.35);
    reverb.setReverbPreDelay(0.012);
    std::cout << "Reverb Time is set to " + std::to_string(reverb.reverbOutput) + " seconds \n" << std::endl;

    AudioMixer audioMixer;
    audioMixer.positionAudioChannel(0.5);
    audioMixer.applyParallelEffects("percs", 0.5);
    audioMixer.processChannel(audioInput);
    std::cout << "Audio Mixer Stereo Position is set to " + std::to_string(audioMixer.audioChannel.stereoPosition) + " \n" << std::endl;
    
    std::cout << "good to go!" << std::endl;

    return 0;
}
