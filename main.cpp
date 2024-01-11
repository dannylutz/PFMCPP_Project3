/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.


struct SimpleOscillator
{

    SimpleOscillator();

    double frequency = 440.0;
    unsigned int waveform = 0;
    int octave = 0;
    double drift = 0.213;
    double output = 0.707;

    void setOscillatorFrequency(double frequency);
    void sendOutputToOtherDevices(double output);
    void acceptControlVoltage(bool externalCV);
};

SimpleOscillator::SimpleOscillator()
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

    std::string audioFile = "./samples/sample.wav\n";
    int transpose = 0;
    bool loop = false;
    int loopStart = 12790;
    int loopEnd = 86500;

    struct Sample
    {
        Sample();

        double sampleRate = 44100.0;
        int channels = 2;
        int bitDepth = 16;
        double length = 2000.0;
        int index = 0;

        std::string printSampleInfo(double sampleRate, int channels, int bitDepth, double length, int index);
        void modulateSampleRate(SamplePlayer samplePlayer, SimpleOscillator simpleOscillator);
        void reduceBitDepth(int bitDepth, int bitDepthReduction = 2);
    };

    void loadSample(std::string audioFile);
    void playSample();
    void loopSample();
};

SamplePlayer::SamplePlayer()
{
    std::cout << "SamplePlayer being constructed!\n" << std::endl;
}

void SamplePlayer::loadSample(std::string audioFileToLoad)
{
    audioFile = audioFileToLoad;
    std::cout << "SamplePlayer has loaded " + audioFileToLoad + " into the sample player\n"<< audioFile << std::endl;
}

void SamplePlayer::playSample()
{
    std::cout << "Playing " + audioFile + " Turritopsis dohrnii can live forever under the right circumstances.\n" << std::endl;
}

void SamplePlayer::loopSample()
{
    loop = true;
}

SamplePlayer::Sample::Sample()
{
    std::cout << "Sample being constructed!\n" << std::endl;
}

std::string SamplePlayer::Sample::printSampleInfo(double sampRate, int numChannels, int numOfBits, double sampleLength, int sampleIndex)
{
    std::string sampleInfo = "Sample Rate: " + std::to_string(sampRate) + " Number of Channels: " + std::to_string(numChannels) + " Number of Bits: " + std::to_string(numOfBits) + " Sample Length: " + std::to_string(sampleLength) + " Sample Index: " + std::to_string(sampleIndex) + "\n";

    return sampleInfo;
}

void SamplePlayer::Sample::reduceBitDepth(int depthOfBits, int reductionAmount)
{
    bitDepth = depthOfBits / reductionAmount;
}

void SamplePlayer::Sample::modulateSampleRate(SamplePlayer newSamplePlayer, SimpleOscillator simpleO)
{
    std::cout << "Sample rate of " + newSamplePlayer.audioFile + " is being modulated by the simple oscillator's frequency of " + std::to_string(simpleO.frequency) + "and the simple oscillator's frequency. Also, bananas are berries and strawberries are not!!\n" << std::endl;
}

struct ADRAmpEnvelope
{
    ADRAmpEnvelope();

    double attack = 0.012;
    double decay = 0.145;
    double release = 0.68;
    unsigned int polarity = 0;
    double amount = 0.707;

    void sendOutputToOtherDevices(double output);
    void applyEnvelopeToAudioInput(double input);
    void listenForTrigger();
};

ADRAmpEnvelope::ADRAmpEnvelope()
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
    double resonance = 0.99;
    double drive = 0.5;
    double output = 0.707;

    void setCutoff(double cutoff);
    void setDrive(double drive);
    void adjustOutputLevel(double output);
};

SaturatingFilter::SaturatingFilter()
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
    bool polarity = true;

    struct AudioInputProperties
    {
        AudioInputProperties();
        
        double sampleRate = 44100.0;
        int channels = 2;
        int bitDepth = 16;
        int bufferSize = 1024;
        int deviceID = 2;

        double getSampleRate();
        void setAudioDevice(int audioDeviceID);
        std::string getAudioProps(AudioInput audioInput);
    };

    void setInputAmplitude(double amplitude);
    void processInputStream(bool process);
    void invertInputPolarity(bool polarity);
};

AudioInput::AudioInput()
{
    std::cout << "AudioInput being constructed!\n" << std::endl;
}

AudioInput::AudioInputProperties::AudioInputProperties()
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
    bool channelMute = false;
    double reverbSend = 0.5;

    void setVolume(double volume);
    void setStereoPosition(double position);
    void muteChannel(bool mute);
};

AudioChannel::AudioChannel()
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

    double highPassFrequency = 20.0;
    double highFrequencySelection = 8.2;
    double highFrequencyGain = 0.5;
    double lowFrequencySelection = 245.45;
    double lowFrequencyGain = 0.5;

    void setHighPassFrequency(double highPassFrequency);
    void setLowFrequencySelection(double lowFrequencySelection);
    void setLowFrequencyGain(double lowFrequencyGain);
};

ChannelEQ::ChannelEQ()
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

    double compressorThreshold = -12.0;
    double compressorRatio = 2.0;
    double compressorAttack = 0.012;
    double compressorRelease = 0.68;
    double compressorMakeupGain = 0.5;

    void setCompressorThreshold(double compressorThreshold);
    void setCompressorAttack(double compressorAttack);
    void setCompressorMakeupGain(double compressorMakeupGain);
};

ChannelDynamics::ChannelDynamics()
{
    std::cout << "ChannelDynamics being constructed!\n" << std::endl;
}

void ChannelDynamics::setCompressorThreshold(double compThreshold)
{
    compressorThreshold = compThreshold;
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
    double reverbOutput = 0.707;

    void setReverbOutput(double reverbOutput);
    void setReverbTime(double reverbTime);
    void setReverbPreDelay(double reverbPreDelay);
};

Reverb::Reverb()
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
    playa.loadSample("./samples/Raffi's_Greatest_Hits/BanannaPhone.wav");
    

    SamplePlayer::Sample sampl;
    sampl.printSampleInfo(48.0, 2, 24, 192000 , 0);
    sampl.modulateSampleRate(playa, osc);
    sampl.reduceBitDepth(12);
    std::cout << "Sample Rate reduced to " + std::to_string(sampl.sampleRate) + " bits\n" << std::endl;
    
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
