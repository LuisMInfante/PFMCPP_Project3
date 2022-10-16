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
 */



/*
1) Electric Guitar
5 properties:
    1) number of strings (int)
    2) length of neck (float)
    3) number of songs played (int)
    4) type of pick-ups (std::string)
    5) tuning (std::string)
3 things it can do:
    1) play a song
    2) tune to key
    3) change strings
*/

struct ElectricGuitar
{
    // number of strings (int)
	int numberOfStrings = 6;
    // length of neck (float)
	float lengthOfNeck = 25.5f;
    // number of songs played (int)
	int numberOfSongsPlayer = 250;
    // type of pick-ups (std::string)
	std::string pickup = "Bare Knuckle";
    // tuning (std::string)
	std::string tuning = "Standard";

    // play a song
	void playSong(std::string songName, int timesPlayed);
    // tune to key
	void tuneGuitar(std::string tuning);
    // change strings
	void changeStrings(int stringGauge);
};

/*
2) Gaming PC
5 properties:
    1) number of CPU cores (int)
    2) number of SSD cards (int)
    3) number of fans (int)
    4) height of PC (float)
    5) number of USB ports (int)
3 things it can do:
    1) play games
    2) code software
    3) play youtube videos
*/

struct GamingPc
{
    // number of CPU cores (int)
	int cpuCores = 8;
    // number of SSD cards (int)
	int solidStateDrives = 2;
    // number of fans (int)
	int numberOfFans = 4;
    // height of PC (float)
	float heightOfComputer = 14.f;
    // number of USB ports (int)
	int numberOfUsbPorts = 8;

	struct PcHealth
	{
		double timeOn = 3.65;
		double currentTemperature = 82.5;
		int currentFrameRate = 145;

		void performDiskCleanUp();
		void defragmentDrives();
		double increaseFanSpeed(double percentageIncrease); //returns resulting speed
	};

    // play games
	void playGame(std::string titleOfGame, float playTime, PcHealth framerate);
    // code software
	void codeSoftware(std::string codingLanguage, float timeCoding);
    // play youtube videos
	void playYoutubeVideos(int numberOfVideos);
};

/*
3) Phone
5 properties:
    1) Number of buttons (int)
    2) number of screens (int)
    3) number of speakers (int)
    4) percentage of charge (float)
    5) number of cameras (int)
3 things it can do:
    1) make a call
    2) text other people
    3) set an alarm
*/

struct Phone
{
    // Number of buttons (int)
	int numberOfButtons = 2;
    // number of screens (int)
    int numberOfScreens = 1;
    // number of speakers (int)
	int numberOfSpeakers = 2;
    // percentage of charge (float)
	float percentageOfCharge = 80.5f;
    // number of cameras (int)
	int numberOfCameras = 4;

	struct PhoneHealth
	{
		double ageOfBattery = 3;
		double amountOfDegredation = 24.5;
		double amountOfStorageUsed = 75.2;

		double clearStorage(double amountToRemove); //returns resulting available storage
		void replaceBattery();
		void runDiagnostics();
	};

    // make a call
	void makeCall(std::string personToCall, float lengthOfCall, PhoneHealth batteryPercentage);
    // text other people
	void textOtherPeople(int numberOfPeople);
    // set an alarm
	void setAnAlarm(float timeToWake, bool snooze);
};

/*
4) Audio Interface
5 properties:
    1) number of knobs (int)
    2) number of midi inputs (int)
    3) number of outputs (int)
    4) number of inputs (int)
    5) amount of gain (int)
3 things it can do:
    1) convert analog to digital signal
    2) turn up gain
    3) record audio
*/

struct AudioInterface
{
    // number of knobs (int)
	int numberOfKnobs = 4;
    // number of midi inputs (int)
	int numberOfMidiInputs = 1;
    // number of outputs (int)
	int numberOfOutputs = 4;
    // number of inputs (int)
	int numberOfInputs = 2;
    // amount of gain (int)
	int amountOfGain = 24;

    // convert analog to digital signal
	void convertAnalogToDigital(bool isAnalog);
    // turn up gain
	void turnUpGain(int gainToAdd, int currentGain);
    // record audio
	void recordAudio(int numberOfTracks, float lengthOfTrack, int numberOfTakes);

};

/*
5) GPU
5 properties:
    1) brand (std::string)
    2) clock speed (float)
    3) amount of power consumed (watts) (float)
    4) number of output ports (int)
    5) amount of memory (float)
3 things it can do:
    1) Run games
    2) render videos
    3) mine crypto
*/

struct Gpu
{
    // brand (std::string)
	std::string brand = "Nvidia";
    // clock speed (float)
	float clockSpeed = 1.26f;
    // amount of power consumed (watts) (float)
	float amountOfWatts = 384.f;
    // number of output ports (int)
	int numberOfOutputPorts = 4;
    // amount of memory (float)
	float amountOfMemory = 12.f;

    // Run games
	void runGames(int numberOfGames, float timePlayed);
    // render videos
	void renderVideos(int numberOfVideos, bool isUltraHighDef);
    // mine crypto
	void mineCrypto(std::string nameOfCypto, float amountOfTime);
};

/*
6) CPU
5 properties:
    1) brand (std::string)
    2) clock speed (float)
    3) number of cores (int)
    4) number of threads (int)
    5) number of bits (int)
3 things it can do:
    1) perform basic arithmatic 
    2) perform input operations
    3) decode data
*/

struct Cpu
{
    //1) brand (std::string)
	std::string brand = "AMD";
    //2) clock speed (float)
	float clockSpeed = 3.6f;
    //3) number of cores (int)
	int numberOfCores = 8;
    //4) number of threads (int)
	int numberOfThreads = 16;
    //5) number of bits (int)
	int numberOfBits = 64;

	// perform basic arithmetic 
	int performBasicArithmetic(int num1, int num2, bool isAddition); //returns the solution
    // perform input operations
	void performInputOperations();
    // decode data
	void decodeData();
};

/*
7) Display
5 properties:
    1) number of pixels (int)
    2) size of display in inches (double)
    3) brightness of diplay in nits (int)
    4) number of displays (int)
    5) pixels per inch (int)
3 things it can do:
    1) show home screen
    2) turn on
    3) lower brightness
*/

struct Display
{
    // number of pixels (int)
	int numberOfPixels = 2073600;
    // size of display in inches (double)
	double sizeOfDisplay = 24; 
    // brightness of diplay in nits (int)
	int brightness = 500;
    // number of displays (int)
	int numberOfDisplays = 1;
    // pixels per inch (int)
	int pixelsPerInch = 92;

    // show home screen
	void showHomeScreen();
    // turn on
	bool turnOn(); //returns true if display is on
    // lower brightness
	float lowerBrightness(float percentageChange); //returns level of brightness
};

/*
8) Keyboard
5 properties:
    1) number of keys (int)
    2) brand of switch (std::string)
    3) backlight power consumption (float)
    4) height of keyboard in inches (float)
    5) length of keyboard in inches (float)
3 things it can do:
    1) turn on backlight
    2) read fingerprint
    3) type a message
*/

struct Keyboard
{
    // number of keys (int)
	int numberOfKeys = 87;
    // brand of switch (std::string)
	std::string brandOfSwitch = "CherryMX";
    // backlight power consumption (float)
	float backlightPowerConsumption = 0.4f;
    // height of keyboard in inches (float)
	float heightOfKeyboard = 5.f;
    // length of keyboard in inches (float)
	float lengthOfKeyboard = 14.f;

    // turn on backlight
	bool turnOnBacklight(); //returns true if backlight is on
    // read fingerprint
	bool readFingerprint(); //returns true if fingerprint is valid
    // type a message
	void typeMessage();
};

/*
9) RAM
5 properties:
    1) number of ram sticks (int)
    2) total amount of memory (int)
    3) memory speed (mHz) (int)
    4) brand (std::string)
    5) type of RAM (std::string)
3 things it can do:
    1) store short term memory
    2) send information to CPU
    3) clear cache
*/

struct Ram
{
    // number of ram sticks (int)
	int numberOfSticks = 2;
    // total amount of memory (int)
	int totalMemory = 16;
    // memory speed (mHz) (int)
	int memorySpeed = 3200;
    // brand (std::string)
	std::string brand = "HyperX";
    // type of RAM (std::string)
	std::string type = "DDR4";

    // store short term memory
	void storeShortTermMemory();
    // send information to CPU
	void sendInfoToCpu();
    // clear cache
	bool clearCache(); //returns true if cache is cleared
};

/*	
10) Macbook
5 properties:
    1) GPU
    2) CPU
    3) Display
    4) Keyboard
    5) RAM
3 things it can do:
    1) Create music
    2) Play online videos
    3) Type emails
*/

struct Macbook
{
    // GPU
	Gpu brand;
    // CPU
	Cpu clockSpeed;
    // Display
	Display sizeOfDisplay;
    // Keyboard
	Keyboard numberOfKeys;
    // RAM
	Ram memorySpeed;

    // Create music
	void createMusic(double lengthOfSong, int beatPerMinute);
    // Play online videos
	void playOnlineVideos(int numberOfVideos);
    // Type emails
	void typeEmail();
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
