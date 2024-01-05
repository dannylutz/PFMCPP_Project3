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

Thing 1: Simple Oscillator
*/
struct SimpleOscillator
{
    //frequency of oscllator in Hz
    double frequency = 440.0;
    //waveform selected
    unsigned int waveform = 0;
    //octave of oscillator
    int octave = 0;
    //drift applied to oscillator pitch
    double drift = 0.213;
    //output level of oscillator
    double output = 0.707;

    //3 things it can do:
    //generate audio rate frequencies
    void setOscillatorFrequency(double frequency);
    //    - generate low frequencies to modulate other devices
    void sendOutputToOtherDevices(double output);
    //    - accept 'control voltage' from other sources
    void acceptControlVoltage(bool externalCV);
};
/*

Thing 2: Sample Player
*/
struct SamplePlayer
{
    //audio file loaded
    std::string audioFile = "./samples/sample.wav";
    //transpose value of sample
    int transpose = 0;
    //loop state of sample
    bool loop = false;
    //loop start sample index
    int loopStart = 12790;
    //loop end sample index
    int loopEnd = 86500;

    struct Sample
    {
        //sample rate of audio file
        double sampleRate = 44100.0;
        //number of channels in audio file
        int channels = 2;
        //bit depth of audio file
        int bitDepth = 16;
        //length of audio file in milliseconds
        double length = 2000.0;
        //sample index
        int index = 0;

        //3 member functions:
        std::string printSample(double sampleRate, int channels, int bitDepth, double length, int index); //returns a string with all sample properties
        void modulateSampleRate(SamplePlayer samplePlayer, SimpleOscillator simpleOscillator); //modulates sample rate of sample);
        void reduceBitDepth(int bitDepth, double bitDepthReduction = 0.5);
    };

    //3 things it can do:
    //load sample
    void loadSample(std::string audioFile);
    //play sample
    void playSample();
    //loop sample
    void loopSample();
};
/*

Thing 3: ADR Amp Envelope
*/
struct ADRAmpEnvelope
{
    //attack time in seconds
    double attack = 0.012;
    //decay time in seconds
    double decay = 0.145;
    //release time in seconds
    double release = 0.68;
    //polarity of envelope
    unsigned int polarity = 0;
    //amplifier envelope amount
    double amount = 0.707;

    //3 things it can do:
    //generate 'control voltages'
    void sendOutputToOtherDevices(double output);
    //apply envelope to audio input via internal amplifier
    void applyEnvelopeToAudioInput(double input);
    //accept trigger signals
    void listenForTrigger();
};
/*

Thing 4: Saturating Flter
*/
struct SaturatingFilter
{
    //filter type
    unsigned int filterType = 0;
    //filter cutoff frequency in Hz
    double cutoff = 1004.75;
    //filter resonance
    double resonance = 0.99;
    //filter drive
    double drive = 0.5;
    //filter output level
    double output = 0.707;

    //3 things it can do:
    //filter audio input
    void setCutoff(double cutoff);
    //apply saturation to audio input
    void setDrive(double drive);
    //adjust output level
    void adjustOutputLevel(double output);
};
/*

Thing 5: Audio Input
*/
struct AudioInput
{
    //amount of amplitude
    double amplitude = 0.707;
    //number of channels
    bool stereo = true;
    //hpf cutoff frequency in kHz
    double hpfCutoff = 20.0;
    //amount of saturation
    double saturation = 0.5;
    //polarity of input (true == inverted)
    bool polarity = true;

    struct AudioInputProperties
    {
        //sample rate of audio stream
        double sampleRate = 44100.0;
        //number of channels in audio stream
        int channels = 2;
        //bit depth of audio stream
        int bitDepth = 16;
        //buffer size of audio stream
        int bufferSize = 1024;
        //audio class ID
        int classID = 2;

        //3 member functions:
        //return sample rate
        int getSampleRate(AudioInput audioInput); //returns sample rate
        //set audio device and properties
        void setAudioDevice(int channels, int bufferSize, int audioDeviceID = 0);
        //return audio properties string
        std::string getAudioProps(AudioInput audioInput); //returns a string with all audio properties
    };

    //3 things it can do:
    //ajust incoming signal amplitude
    void setInputAmplitude(double amplitude);
    //enable or diable processing incoming signal
    void processInputStream(bool process);
    //invert polarity of incoming signal
    void invertInputPolarity(bool polarity);
};
/*

Thing 6: Audio Channel
*/
struct AudioChannel
{
    //stereo position
    double  stereoPosition = 0.5;
    //channel volume
    double channelVolume = 0.707;
    //channel name
    std::string channelName = "ch 1";
    //channel mute state
    bool channelMute = false;
    //channel send amount to reverb
    double reverbSend = 0.5;

    //3 things it can do:
    //control the volume of a channel
    void setVolume(double volume);
    //control the stereo position of a channel
    void setStereoPosition(double position);
    //mute channel from summed output
    void muteChannel(bool mute);
};
/*

Thing 7: Channel EQ
*/
struct ChannelEQ
{
    //high-pass frequency in Hz
    double highPassFrequency = 20.0;
    //high frequenecy selection in kHz
    double highFrequencySelection = 8.2;
    //high frequency gain in dB
    double highFrequencyGain = 0.5;
    //low freuqency selection in Hz
    double lowFrequencySelection = 245.45;
    //low frequency gain in dB
    double lowFrequencyGain = 0.5;

    //3 things it can do:
    //high-pass filter signal
    void setHighPassFrequency(double highPassFrequency);
    //select low frequency to boost/cut
    void setLowFrequencySelection(double lowFrequencySelection);
    //boost or cut selected frequencies
    void setLowFrequencyGain(double lowFrequencyGain);
};
/*

Thing 8: Channel Dynamics
*/
struct ChannelDynamics
{
    //compressor threshold in dB
    double compressorThreshold = -12.0;
    //compressor ratio
    double compressorRatio = 2.0;
    //compressor attack time in seconds
    double compressorAttack = 0.012;
    //compressor release time in seconds
    double compressorRelease = 0.68;
    //compressor makeup gain in dB
    double compressorMakeupGain = 0.5;

    //3 things it can do:
    //compress signal below set threshold
    void setCompressorThreshold(double compressorThreshold);
    //adjust attack and release times
    void setCompressorAttack(double compressorAttack);
    //adjust makeup gain
    void setCompressorMakeupGain(double compressorMakeupGain);
};
/*

Thing 9: Reverb
*/
struct Reverb
{
    //reverb time in seconds
    double reverbTime = 0.35;
    //reverb pre-delay in seconds
    double reverbPreDelay = 0.012;
    //reverb diffusion amount
    double reverbDiffusion = 0.5;
    //reverb damping amount
    double reverbDamping = 0.5;
    //reverb output level
    double reverbOutput = 0.707;

    //3 things it can do:
    //apply reverb to signal
    void processChannelStream(int channel, double amount);
    //adjust reverb time
    void setReverbTime(double reverbTime);
    //adjust reverb pre-delay
    void setReverbPreDelay(double reverbPreDelay);
};
/*

Thing 10) Audio Mixer
*/
struct AudioMixer
{
    //Audio Input
    AudioInput audioInput;
    //Audio Channel
    AudioChannel audioChannel;
    //Channel EQ
    ChannelEQ channelEQ;
    //Channel Dynamics
    ChannelDynamics channelDynamics;
    //Reverb
    Reverb reverb;

    //3 things it can do:
    //position audio channel
    void positionAudioChannel(int channelIndex, double position);
    //apply parallel effects selectively
    void applyParallelEffects(std::string channelName, int channelIndex, double amount);  
    // process audio channels
    void processChannel(int channelIndex, double amount);
};

/*
====================================================================
*/

int main()
{
    std::cout << "good to go!" << std::endl;
}
