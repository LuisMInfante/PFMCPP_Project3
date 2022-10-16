/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


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
