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
#include <chrono>
#include <thread>
#include <random>

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
    void sweepFrequencies(double startFrequency, double stopFrequency, double timeInSeconds);
};

SimpleOscillator::SimpleOscillator(): drift(0.213), output(0.707)
{
    std::cout << "\nSimpleOscillator being constructed!\n" << std::endl;
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
        std::cout << "\nexternal CV enabled\n" << std::endl;
    }
    else
    {
        std::cout << "\nexternal CV not disabled\n" << std::endl;
    }
}

void SimpleOscillator::sweepFrequencies(double startFq, double stopFq, double numOfSeconds)
{
    double fqIncrement = 100;
    double totalSteps = (stopFq - startFq) / fqIncrement;
    double timeIncrement = numOfSeconds / totalSteps;
    double currentFq = startFq;

    while (currentFq <= stopFq)
    {
        std::cout << "\nCurrent Frequency: " << std::to_string(currentFq) + " Hz" << std::endl;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(timeIncrement * 1000)));
        currentFq += fqIncrement;
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

        std::string printSampleInfo();
        void loadSample(std::string audioFile);
        void reduceBitDepth(int bitDepth, int bitDepthReduction = 2);
        void loadingFileProgress(double length);
    };

    void modulateSampleRate(SimpleOscillator oscillator);    
    void playSample();
    void loopSample();
    void loopSampleNTimes(int numOfLoops);
};

SamplePlayer::SamplePlayer(): loopStart(127900), loopEnd(865000)
{
    std::cout << "\nSamplePlayer being constructed!\n" << std::endl;
}

void SamplePlayer::Sample::loadSample(std::string audioFileToLoad)
{
    std::cout << "\nThe sample " + audioFileToLoad + " has been loaded \n" << std::endl;
}

void SamplePlayer::playSample()
{
    std::cout << "\nNow playing the loaded sample\n" << std::endl;
}

void SamplePlayer::loopSample()
{
    loop = true;
    std::cout << "\nLooping file from sample number" + std::to_string(loopStart) + " to sample number " + std::to_string(loopEnd) << std::endl;
}

void SamplePlayer::modulateSampleRate(SimpleOscillator oscillator)
{
    std::cout << "\nSample rate of " + std::to_string(sampleRate) + " is being modulated by the simple oscillator's frequency of " + std::to_string(oscillator.frequency) + "and the simple oscillator's frequency. Also, bananas are berries and strawberries are not!!\n" << std::endl;
}

void SamplePlayer::loopSampleNTimes(int numOfLoops)
{
    loop = true;
    int loopCount = 1;
    while (numOfLoops > 0)
    {
        std::cout << "\nLooping file. Loop number " + std::to_string(loopCount) << std::endl;
        --numOfLoops;
        ++loopCount;
    }
    loop = false;
}

SamplePlayer::Sample::Sample(): length(2000.0), index(0)
{
    std::cout << "\nSample being constructed!\n" << std::endl;
}

std::string SamplePlayer::Sample::printSampleInfo()
{
    std::string sampleInfo = "\nSample file: " + audioFile +" Number of Channels: " + std::to_string(channels) + " Number of Bits: " + std::to_string(bitDepth) + " Sample Length: " + std::to_string(length) + " Sample Index: " + std::to_string(index) + "\n";

    return sampleInfo;
}

void SamplePlayer::Sample::reduceBitDepth(int depthOfBits, int reductionAmount)
{
    bitDepth = depthOfBits / reductionAmount;
}

void SamplePlayer::Sample::loadingFileProgress(double lengthOfFile)
{
    double originalLength = lengthOfFile;
    double loadRate = 800.00; //arbitrary number of samples per second
    double dataChunk = 100;

    while (lengthOfFile > 0) 
    {
        lengthOfFile -= dataChunk;
        if (lengthOfFile < 0) {
            lengthOfFile = 0;
    }

    double loadedPercentage = 100.0 * (1 - (lengthOfFile / originalLength));
    std::cout << "\nLoading progress: " << loadedPercentage << "%\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dataChunk / loadRate * 250)));
    }
    ++index;
    std::cout << "\nLoading complete. Sample available at index " + std::to_string(index) + "\n" << std::endl;
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
    void attackValueTooLow();
};

ADRAmpEnvelope::ADRAmpEnvelope(): attack(0.012), decay(0.145), release(0.68)
{
    std::cout << "\nADRAmpEnvelope being constructed!\n" << std::endl;
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
    std::cout << "\nThe envelope generator is listening for trigger signal. While you're here -- did you know erogel is the world's lightest solid material? It's composed of 99.8% air and can support over 1,000 times its own weight\n" << std::endl;
}

void ADRAmpEnvelope::attackValueTooLow()
{
    attack = 0.000;
    while (attack < 0.003)
    {
        std::cout << "\n*** Attack value too low. Please increase the attack value to a value higher than 3ms unless you are making a DX Lately Bass patch ***\n" << std::endl;
        attack += 0.001;
    }
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
    void increaseDrive(double increaseAmt);
};

SaturatingFilter::SaturatingFilter(): resonance(0.99), drive(0.1), output(0.707)
{
    std::cout << "\nSaturatingFilter being constructed!\n" << std::endl;
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

void SaturatingFilter::increaseDrive(double increaseAmount)
{
    while (drive < increaseAmount)
    {
        drive += 0.07;
        std::cout << "\nDrive increased to " + std::to_string(drive) << std::endl;       
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(40)));
    }
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
        void setDefaultDeviceSettings();
    };

    void setInputAmplitude(double amplitude);
    void processInputStream(bool process);
    void invertInputPolarity(bool polarity);
    void increaseSaturation();

};

AudioInput::AudioInput(): polarity(false)
{
    std::cout << "\nAudioInput being constructed!\n" << std::endl;
}

AudioInput::AudioInputProperties::AudioInputProperties(): channels(2), bitDepth(16), bufferSize(128), deviceID(0)
{
    std::cout << "\nAudioInputProperties being constructed!\n" << std::endl;
}

void AudioInput::setInputAmplitude(double amplitudeAmt)
{
    amplitude = amplitudeAmt;
}

void AudioInput::processInputStream(bool shouldProcess)
{
    if (shouldProcess)
    {
        std::cout << "\nA Lichtenberg figure is a branching, tree-like pattern that is created by the passage of high-voltage electrical discharges along the surface or through insulating materials. These figures can also appear on the skin of lightning strike victims\n" << std::endl;
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
    std::string audioProps = "\nSample Rate: " + std::to_string(inputAudio.amplitude) + " Number of Channels: " + std::to_string(inputAudio.stereo) +
                             std::to_string(inputAudio.hpfCutoff) + " Resonance: " + std::to_string(inputAudio.saturation) + "\nPolarity: " + std::to_string(inputAudio.polarity) + "\n";

    return audioProps;
}

void AudioInput::increaseSaturation()
{
    while (saturation < 1.0)
    {
        double increment = saturation/10;
        if (saturation + increment > 1.0)
        {
            saturation = 1.0;
            std::cout << "\nSaturation increased to " + std::to_string(saturation) << std::endl;
            return;
        }
        saturation += increment;
        std::cout << "\nSaturation increased to " + std::to_string(saturation) << std::endl;
    } 
}


void AudioInput::AudioInputProperties::setDefaultDeviceSettings()
{
    for (int i = 3; i >= 0; --i)
    {
        if (deviceID != 0)
        {
            std::cout << "\nPlease select a valid device ID\n" << std::endl;
        }
        else
        {
            sampleRate = 44100.0;
            channels = 2;
            bitDepth = 16;
            bufferSize = 128;
            std::cout << "\nDefault device connected, settings have been applied\n" << std::endl;
            return;
        }
    }
}

struct AudioChannel
{
    AudioChannel();

    double stereoPosition = 0.2;
    double channelVolume = 0.707;
    std::string channelName = "ch 1";
    bool channelMute;
    double reverbSend;

    void setVolume(double volume);
    void setStereoPosition(double position);
    void muteChannel(bool mute);
    void reduceVolumeTo50Percent();
};

AudioChannel::AudioChannel(): channelMute(false), reverbSend(0.5)
{
    std::cout << "\nAudioChannel being constructed!\n" << std::endl;
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

void AudioChannel::reduceVolumeTo50Percent()
{
    if (channelVolume <= 0.001)
    {
        std::cout << "Volume is at 0.0!\n" << std::endl;
        return;
    }
    while (channelVolume > 0.001)
    {   
        double increment = channelVolume / 2;
        channelVolume -= increment;
        std::cout << "\nVolume reduced to " + std::to_string(channelVolume) << std::endl;
    }
}

struct ChannelEQ
{
    ChannelEQ();

    double highPassFrequency, highFrequencySelection, highFrequencyGain, lowFrequencySelection, lowFrequencyGain;

    void setHighPassFrequency(double highPassFrequency);
    void setLowFrequencySelection(double lowFrequencySelection);
    void setLowFrequencyGain(double lowFrequencyGain);
    void sweepHighPassFrequency(double highPassFrequency, double time);
};

ChannelEQ::ChannelEQ(): highPassFrequency(20), highFrequencySelection(8.2), highFrequencyGain(0.5), lowFrequencySelection(245.45), lowFrequencyGain(1.2)
{
    std::cout << "\nChannelEQ being constructed!\n" << std::endl;
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

void ChannelEQ::sweepHighPassFrequency(double hpFreq, double timeToSweep)
{
    if (timeToSweep <= 0)
    {
        std::cerr << "\nTime to sweep must be positive.\n";
        return;
    }

    double frequencyIncrement = (hpFreq - highPassFrequency) / timeToSweep;
    int milliSecondsToWait = 1000; // Wait time in milliseconds for each step

    while (highPassFrequency < hpFreq)
    {
        highPassFrequency += frequencyIncrement;
        if (highPassFrequency > hpFreq) 
        {
            highPassFrequency = hpFreq;
        }

        std::cout << "\nHigh pass frequency increased to " << highPassFrequency << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(milliSecondsToWait));
    }
}

struct ChannelDynamics
{
    ChannelDynamics();

    double compressorThreshold, compressorRatio;
    double compressorAttack = 0.012;
    double compressorRelease = 0.68;
    double compressorMakeupGain = 0.5;
    double gainReduction = 0.09;

    void setCompressorThreshold(double compressorThreshold);
    void setCompressorAttack(double compressorAttack);
    void setCompressorMakeupGain(double compressorMakeupGain);
    void enableAutoMakeupGain(bool state);
};

ChannelDynamics::ChannelDynamics(): compressorThreshold(-12.0), compressorRatio(1.5)
{
    std::cout << "\nChannelDynamics being constructed!\n" << std::endl;
}

void ChannelDynamics::setCompressorThreshold(double compThreshold)
{
    compressorThreshold = compThreshold;
    std::cout << "\nCompressor threshold set to: " << compressorThreshold << std::endl;
}

void ChannelDynamics::setCompressorAttack(double compAttack)
{
    compressorAttack = compAttack;
}

void ChannelDynamics::setCompressorMakeupGain(double compMakeupGain)
{
    compressorMakeupGain = compMakeupGain;
}

void ChannelDynamics::enableAutoMakeupGain(bool state)
{
    if (state)
    {
        for (int i = 0; i < 10; ++i)
        {
            gainReduction += 0.01;
            compressorMakeupGain = gainReduction;
            std::cout << "\nMakeup gain is set to: " << gainReduction << std::endl;
        }
    }
}

struct Reverb
{
    Reverb();

    double reverbTime = 0.35;
    double reverbPreDelay = 0.012;
    double reverbDiffusion = 0.5;
    double reverbDamping = 0.5;
    double reverbOutput;
    bool incomingSignal;

    void setReverbOutput(double reverbOutput);
    void setReverbTime(double reverbTime);
    void setReverbPreDelay(double reverbPreDelay);
    void setIncomingSignal(bool incomingSignal);
};

Reverb::Reverb(): reverbOutput(0.707)
{
    std::cout << "\nReverb being constructed!\n" << std::endl;
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

void Reverb::setIncomingSignal(bool signal)
{
    double previousRtime = reverbTime;
    while (!signal)
    {
        reverbTime = 0.00001;
        std::cout << "\nNo incoming signal, setting reverb time set to: " << reverbTime << std::endl;
        return;
    }
    reverbTime = previousRtime;
    std::cout << "\nIncoming signal detected, setting reverb time back to: " << reverbTime << std::endl;
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
    void muteChannelOnSustainedClip();
};

AudioMixer::AudioMixer()
{
    std::cout << "\nAudioMixer being constructed!\n" << std::endl;
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

void AudioMixer::muteChannelOnSustainedClip()
{
    for (int i = 0; i < 20; ++i)
    {
        if (audioInput.amplitude > 1.5)
        {
            audioChannel.muteChannel(true);
            std::cout << "input channel is clipping, muting channel until level reduces to a safe level" << std::endl;
        }
        else
        {
            audioChannel.muteChannel(false);
            std::cout << "input channel has stopped clipping, unmuting channel" << std::endl;
            return;
        }
    }
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
    osc.sweepFrequencies(45, 6000, 2);

    AudioInput audioInput;
    audioInput.processInputStream(true);
    audioInput.invertInputPolarity(false);
    audioInput.setInputAmplitude(3.9);
    audioInput.increaseSaturation();
    std::cout << "Setting Input Amplitude to " + std::to_string(audioInput.amplitude) + " \n" << std::endl;

    SamplePlayer playa;
    playa.playSample();
    playa.loopSample();
    playa.modulateSampleRate(osc);
    playa.loopSampleNTimes(12);

    SamplePlayer::Sample sampl;
    sampl.loadSample("./samples/snare.wav");
    sampl.printSampleInfo();
    sampl.loadingFileProgress(5000);
    std::cout << "Bit depth reduced to " + std::to_string(sampl.bitDepth) + " bits\n" << std::endl;
    
    AudioInput::AudioInputProperties audioInputProps;
    audioInputProps.getAudioProps(audioInput);
    audioInputProps.getSampleRate();
    audioInputProps.setAudioDevice(1);
    audioInputProps.setDefaultDeviceSettings();
    audioInputProps.setAudioDevice(2);
    audioInputProps.setDefaultDeviceSettings();
    audioInputProps.setAudioDevice(0);
    audioInputProps.setDefaultDeviceSettings();
    
    std::cout << "Audio Device sample rate is set to " + std::to_string(audioInputProps.sampleRate) + "\n" << std::endl;

    ADRAmpEnvelope envelope;
    envelope.listenForTrigger();
    envelope.sendOutputToOtherDevices(1080.12);
    envelope.applyEnvelopeToAudioInput(420.42);
    envelope.attackValueTooLow();


    SaturatingFilter filta;
    filta.setCutoff(117.6);
    filta.adjustOutputLevel(11.76);
    filta.setDrive(0.1);
    filta.increaseDrive(0.7);
    std::cout << "Saturating Filter Cutoff frequency is set to " + std::to_string(filta.cutoff) + " Hz\n" << std::endl;
    
    AudioChannel audioChannel;
    audioChannel.setVolume(0.707);
    audioChannel.muteChannel(true);
    audioChannel.setStereoPosition(0.5);
    audioChannel.reduceVolumeTo50Percent();
    std::cout << "Audio Channel Volume is set to " + std::to_string(audioChannel.channelVolume) + " \n" << std::endl;
    
    ChannelEQ chanQ;
    chanQ.setHighPassFrequency(20.0);
    chanQ.setLowFrequencySelection(20.4);
    chanQ.setLowFrequencyGain(5.2);
    chanQ.sweepHighPassFrequency(60.0, 2.4);

    ChannelDynamics chanDyn;
    chanDyn.setCompressorThreshold(-12.4);
    chanDyn.setCompressorAttack(0.012);
    chanDyn.setCompressorMakeupGain(0.5);
    chanDyn.enableAutoMakeupGain(true);
    std::cout << "ChannelDynamics Compressor Threshold is set to " + std::to_string(chanDyn.compressorThreshold) + " dB \n" << std::endl;

    Reverb reverb;
    reverb.setReverbOutput(0.707);
    reverb.setReverbTime(0.35);
    reverb.setReverbPreDelay(0.012);
    reverb.setIncomingSignal(false);
    reverb.setIncomingSignal(true);
    std::cout << "Reverb Time is set to " + std::to_string(reverb.reverbOutput) + " seconds \n" << std::endl;

    AudioMixer audioMixer;
    audioMixer.positionAudioChannel(0.5);
    audioMixer.applyParallelEffects("percs", 0.5);
    audioMixer.processChannel(audioInput);

    audioMixer.audioInput.amplitude = 1.0;
    audioMixer.muteChannelOnSustainedClip();
    audioMixer.audioInput.amplitude = 1.6;
    audioMixer.muteChannelOnSustainedClip();
    audioMixer.audioInput.amplitude = 0.8;
    audioMixer.muteChannelOnSustainedClip();
    
    std::cout << "Audio Mixer Stereo Position is set to " + std::to_string(audioMixer.audioChannel.stereoPosition) + " \n" << std::endl;
    
    std::cout << "good to go!" << std::endl;

    return 0;
}
