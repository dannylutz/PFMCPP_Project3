 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    int timeRunning;

    struct Foot
    {
        void stepForward();
        int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howNotSlow, bool startWithLeftFoot);
};

void Person::Foot::stepForward()
{
    std::cout << "Stepped forward" << std::endl;
}

int Person::Foot::stepSize()
{
    return 1;
}

void Person::run(int howNotSlow, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    howNotSlow = distanceTraveled / timeRunning;
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
paste your code below
====================================================================

*/
struct SimpleOscillator
{
    
    double frequency = 440.0;
    unsigned int waveform = 0;
    int octave = 0;
    double drift = 0.213;
    double output = 0.707;

    void setOscillatorFrequency(double frequency);
    void sendOutputToOtherDevices(double output);
    void acceptControlVoltage(bool externalCV);
};

void SimpleOscillator::setOscillatorFrequency(double oscFrequency)
{
    SimpleOscillator simpleOscillator;
    simpleOscillator.frequency = oscFrequency;
}

void SimpleOscillator::sendOutputToOtherDevices(double extOutput)
{
    SimpleOscillator simpleOscillator;
    simpleOscillator.output = extOutput;
}

void SimpleOscillator::acceptControlVoltage(bool externalCV)
{
    if (externalCV)
    {
        std::cout << "external CV enabled" << std::endl;
    }
    else
    {
        std::cout << "external CV not disabled" << std::endl;
    }
}

struct SamplePlayer
{
    std::string audioFile = "./samples/sample.wav";
    int transpose = 0;
    bool loop = false;
    int loopStart = 12790;
    int loopEnd = 86500;

    struct Sample
    {
        double sampleRate = 44100.0;
        int channels = 2;
        int bitDepth = 16;
        double length = 2000.0;
        int index = 0;

        //3 member functions:
        std::string printSampleInfo(double sampleRate, int channels, int bitDepth, double length, int index);
        void modulateSampleRate(SamplePlayer samplePlayer, SimpleOscillator simpleOscillator); 
        void reduceBitDepth(int bitDepth, int bitDepthReduction = 2);
    };

    void loadSample(std::string audioFile);
    void playSample();
    void loopSample();

};

void SamplePlayer::loadSample(std::string audioFileToLoad)
{
    SamplePlayer samplePlayer;
    samplePlayer.audioFile = audioFileToLoad;
}

void SamplePlayer::playSample()
{
   
}

void SamplePlayer::loopSample()
{
    SamplePlayer samplePlayer;
    samplePlayer.loop = true;
}

std::string SamplePlayer::Sample::printSampleInfo(double sampRate, int numChannels, int numOfBits, double sampleLength, int sampleIndex)
{
        std::string sampleInfo = "Sample Rate: " + std::to_string(sampRate) + " Number of Channels: " +std::to_string(numChannels) + " Number of Bits: " + std::to_string(numOfBits) + " Sample Length: " + std::to_string(sampleLength) + " Sample Index: " + std::to_string(sampleIndex);
    
    return sampleInfo;
}

void SamplePlayer::Sample::reduceBitDepth(int depthOfBits, int reductionAmount)
{
    Sample sample;
    sample.bitDepth = depthOfBits / reductionAmount;
}

struct ADRAmpEnvelope
{
    double attack = 0.012;
    double decay = 0.145;
    double release = 0.68;
    unsigned int polarity = 0;
    double amount = 0.707;

    void sendOutputToOtherDevices(double output);
    void applyEnvelopeToAudioInput(double input);
    void listenForTrigger();
};

void ADRAmpEnvelope::sendOutputToOtherDevices(double outputAmount)
{
    ADRAmpEnvelope ampEnvelope;
    ampEnvelope.amount = outputAmount;
}

void ADRAmpEnvelope::applyEnvelopeToAudioInput(double inputAmount)
{
    ADRAmpEnvelope ampEnvelope;
    ampEnvelope.amount = inputAmount;    
}

void ADRAmpEnvelope::listenForTrigger()
{

}

struct SaturatingFilter
{
    unsigned int filterType = 0;
    double cutoff = 1004.75;
    double resonance = 0.99;
    double drive = 0.5;
    double output = 0.707;

    void setCutoff(double cutoff);
    void setDrive(double drive);
    void adjustOutputLevel(double output);
};

void SaturatingFilter::setCutoff(double cutoffFq)
{
    SaturatingFilter saturatingFilter;
    saturatingFilter.cutoff = cutoffFq;
}

void SaturatingFilter::setDrive(double driveAmount)
{
    SaturatingFilter saturatingFilter;
    saturatingFilter.drive = driveAmount;
}

void SaturatingFilter::adjustOutputLevel(double outputAmount)
{
    SaturatingFilter saturatingFilter;
    saturatingFilter.output = outputAmount;
}

struct AudioInput
{
    
    double amplitude = 0.707;
    bool stereo = true;
    double hpfCutoff = 20.0;
    double saturation = 0.5;
    bool polarity = true;

    struct AudioInputProperties
    {
        double sampleRate = 44100.0;
        int channels = 2;
        int bitDepth = 16;
        int bufferSize = 1024;
        int deviceID = 2;

        double getSampleRate(AudioInputProperties audioProps);
        void setAudioDevice(int audioDeviceID);
        std::string getAudioProps(AudioInput audioInput);
    };

    void setInputAmplitude(double amplitude);
    void processInputStream(bool process);
    void invertInputPolarity(bool polarity);
};

void AudioInput::setInputAmplitude(double amplitudeAmt)
{
    AudioInput audioInput;
    audioInput.amplitude = amplitudeAmt;
}

void AudioInput::processInputStream(bool shouldProcess)
{
    if (shouldProcess)
    {
        std::cout << "processing input stream" << std::endl;
    }
}

void AudioInput::invertInputPolarity(bool invert)
{
    if (invert)
    {
        AudioInput audioInput;
        audioInput.polarity = true;
    }
    
}

double AudioInput::AudioInputProperties::getSampleRate(AudioInput::AudioInputProperties inputAudio)
{
    double rate = inputAudio.sampleRate;
    return rate;
}

void AudioInput::AudioInputProperties::setAudioDevice(int devID)
{
    AudioInputProperties audioInput;
    audioInput.deviceID = devID;
}

std::string AudioInput::AudioInputProperties::getAudioProps(AudioInput inputAudio)
{
    std::string audioProps = "Sample Rate: " + std::to_string(inputAudio.amplitude) + " Number of Channels: " + std::to_string(inputAudio.stereo) +
    std::to_string(inputAudio.hpfCutoff) + " Resonance: " + std::to_string(inputAudio.saturation) + " Polarity: " + std::to_string(inputAudio.polarity);

    return audioProps;
}

struct AudioChannel
{
    double  stereoPosition = 0.5;
    double channelVolume = 0.707;
    std::string channelName = "ch 1";
    bool channelMute = false;
    double reverbSend = 0.5;


    void setVolume(double volume);
    void setStereoPosition(double position);
    void muteChannel(bool mute);
};

void AudioChannel::setVolume(double vol)
{
    AudioChannel audioChannel;
    audioChannel.channelVolume = vol;    
}

void AudioChannel::setStereoPosition(double strPosition)
{
    AudioChannel audioChannel;
    audioChannel.stereoPosition = strPosition;
}

void AudioChannel::muteChannel(bool mute)
{
    AudioChannel audioChannel;
    audioChannel.channelMute = mute;
}

struct ChannelEQ
{
    double highPassFrequency = 20.0;
    double highFrequencySelection = 8.2;
    double highFrequencyGain = 0.5;
    double lowFrequencySelection = 245.45;
    double lowFrequencyGain = 0.5;

    void setHighPassFrequency(double highPassFrequency);
    void setLowFrequencySelection(double lowFrequencySelection);
    void setLowFrequencyGain(double lowFrequencyGain);
};

void ChannelEQ::setHighPassFrequency(double hpFreq)
{
    ChannelEQ channelEQ;
    channelEQ.highPassFrequency = hpFreq;
}

struct ChannelDynamics
{
    double compressorThreshold = -12.0;
    double compressorRatio = 2.0;
    double compressorAttack = 0.012;
    double compressorRelease = 0.68;
    double compressorMakeupGain = 0.5;

    void setCompressorThreshold(double compressorThreshold);
    void setCompressorAttack(double compressorAttack);
    void setCompressorMakeupGain(double compressorMakeupGain);
};

void ChannelDynamics::setCompressorThreshold(double compThreshold)
{
    ChannelDynamics channelDynamics;
    channelDynamics.compressorThreshold = compThreshold;
}

void ChannelDynamics::setCompressorAttack(double compAttack)
{
    ChannelDynamics channelDynamics;
    channelDynamics.compressorAttack = compAttack;
}

void ChannelDynamics::setCompressorMakeupGain(double compMakeupGain)
{
    ChannelDynamics channelDynamics;
    channelDynamics.compressorMakeupGain = compMakeupGain;
}

struct Reverb
{
    double reverbTime = 0.35;
    double reverbPreDelay = 0.012;
    double reverbDiffusion = 0.5;
    double reverbDamping = 0.5;
    double reverbOutput = 0.707;

    void setReverbOutput(double reverbOutput);
    void setReverbTime(double reverbTime);
    void setReverbPreDelay(double reverbPreDelay);
};

void Reverb::setReverbOutput(double reverbOut)
{
    Reverb reverb;
    reverb.reverbOutput = reverbOut;
}

void Reverb::setReverbTime(double verbTime)
{
    Reverb reverb;
    reverb.reverbTime = verbTime;
}

void Reverb::setReverbPreDelay(double verbPreDelay)
{
    Reverb reverb;
    reverb.reverbPreDelay = verbPreDelay;
}

struct AudioMixer
{
    AudioInput audioInput;
    AudioChannel audioChannel;
    ChannelEQ channelEQ;
    ChannelDynamics channelDynamics;
    Reverb reverb;

    void positionAudioChannel(double position);
    void applyParallelEffects(std::string channelName, double amount);  
    void processChannel(AudioChannel audioChannel, double amount);
};

void AudioMixer::positionAudioChannel(double position)
{
    AudioMixer audioMixer;
    audioMixer.audioChannel.stereoPosition = position;
}

void AudioMixer::applyParallelEffects(std::string chName, double amt)
{
    AudioMixer audioMixer;
    if (audioMixer.audioChannel.channelName == chName)
    {
        audioMixer.audioChannel.reverbSend = amt;
    }
}

void AudioMixer::processChannel(AudioChannel chan, double amount)
{
    AudioMixer audioMixerChan;
    if (audioMixerChan.audioChannel.channelName == audioChannel.channelName)
    {
        AudioInput audioInput;
        audioInput.processInputStream(true);
    }
}

/*
====================================================================
*/

int main()
{
    std::cout << "good to go!" << std::endl;
}
