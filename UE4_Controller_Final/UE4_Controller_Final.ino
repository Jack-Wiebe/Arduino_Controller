#include <TM1637Display.h>


int mapKnob(int in)
{
  return map(in, 1023, 1, 0, 1001);
}

int calbrateVariance(int knob)
{
  int data = analogRead(knob);
  int noise  = 8;
  int low = data;
  int high = data+1;
  
  for(int i = 0; i<10000; i++)
  {
    data = analogRead(knob);
    if(data > high)
      high = data;

    if(data < low)
      low - data;
  }

  //1023 - (high - low)
  return(high - low) + noise;
  
}

//First Display and Light
const int CLK_01 = 23; //Set the CLK_01 pin connection to the display
const int DIO_01 = 22; //Set the DIO_01 pin connection to the display

const int RedLED_01 = 24;
const int GreenLED_01 = 25;

const int Knob_01 = A10;

int digit01_delta ;
int knob01_var;

int framecount_01 = 0;
bool digit_changed_01 = true;

//Second
const int CLK_02 = 27; //Set the CLK_01 pin connection to the display
const int DIO_02 = 26; //Set the DIO_01 pin connection to the display

const int RedLED_02 = 29;
const int GreenLED_02 = 28;

const int Knob_02 = A9;

int digit02_delta ;
int knob02_var;

int framecount_02 = 0;
bool digit_changed_02 = true;

//THIRD
const int CLK_03 = 31; //Set the CLK_01 pin connection to the display
const int DIO_03 = 30; //Set the DIO_01 pin connection to the display

const int RedLED_03 = 32;
const int GreenLED_03 = 33;

const int Knob_03 = A8;

int digit03_delta ;
int knob03_var;

int framecount_03 = 0;
bool digit_changed_03 = true;


//Fourth
const int CLK_04 = 34; //Set the CLK_01 pin connection to the display
const int DIO_04 = 35; //Set the DIO_01 pin connection to the display

const int RedLED_04 = 37;
const int GreenLED_04 = 36;

const int Knob_04 = A7;

int digit04_delta ;
int knob04_var;

int framecount_04 = 0;
bool digit_changed_04 = true;


//Firth
const int CLK_05 = 38; //Set the CLK_01 pin connection to the display
const int DIO_05 = 39; //Set the DIO_01 pin connection to the display

const int RedLED_05 = 40;
const int GreenLED_05 = 41;

const int Knob_05 = A6;

int digit05_delta ;
int knob05_var;

int framecount_05 = 0;
bool digit_changed_05 = true;

//Sixth
const int CLK_06 = 42; //Set the CLK_01 pin connection to the display
const int DIO_06 = 43; //Set the DIO_01 pin connection to the display

const int RedLED_06 = 44;
const int GreenLED_06 = 45;

const int Knob_06 = A5;

int digit06_delta ;
int knob06_var;

int framecount_06 = 0;
bool digit_changed_06 = true;

TM1637Display display(CLK_01, DIO_01);  //set up the 4-Digit Display.
TM1637Display display2(CLK_02, DIO_02);  //set up the 4-Digit Display.
TM1637Display display3(CLK_03, DIO_03);  //set up the 4-Digit Display.
TM1637Display display4(CLK_04, DIO_04);  //set up the 4-Digit Display.
TM1637Display display5(CLK_05, DIO_05);  //set up the 4-Digit Display.
TM1637Display display6(CLK_06, DIO_06);  //set up the 4-Digit Display.

//Controller cont(23,22,25,24,A10);

void setup()
{
  Serial.begin(9600);
  
  pinMode(RedLED_01, OUTPUT);
  pinMode(GreenLED_01, OUTPUT);
  pinMode(RedLED_02, OUTPUT);
  pinMode(GreenLED_02, OUTPUT);
  pinMode(RedLED_03, OUTPUT);
  pinMode(GreenLED_03, OUTPUT);
  pinMode(RedLED_04, OUTPUT);
  pinMode(GreenLED_04, OUTPUT);
  pinMode(RedLED_05, OUTPUT);
  pinMode(GreenLED_05, OUTPUT);
  //pinMode(RedLED_06, OUTPUT);
  //pinMode(GreenLED_06, OUTPUT);
  
  display.setBrightness(0x0a);  //set the diplay to maximum brightness
  display2.setBrightness(0x0a);  //set the diplay to maximum brightness
  display3.setBrightness(0x0a);  //set the diplay to maximum brightness
  display4.setBrightness(0x0a);  //set the diplay to maximum brightness
  display5.setBrightness(0x0a);  //set the diplay to maximum brightness
  display6.setBrightness(0x0a);  //set the diplay to maximum brightness


  digit01_delta = mapKnob(analogRead(Knob_01));
  knob01_var=calbrateVariance(Knob_01);
  digit02_delta = mapKnob(analogRead(Knob_02));
  knob02_var=calbrateVariance(Knob_02);
  digit03_delta = mapKnob(analogRead(Knob_03));
  knob03_var=calbrateVariance(Knob_03);
  digit04_delta = mapKnob(analogRead(Knob_04));
  knob04_var=calbrateVariance(Knob_04);
  digit05_delta = mapKnob(analogRead(Knob_05));
  knob05_var=calbrateVariance(Knob_05);
  digit06_delta = mapKnob(analogRead(Knob_06));
  knob06_var=calbrateVariance(Knob_06);
  
}



void loop()
{

  int num1 = Get_Values(Knob_01, knob01_var, digit_changed_01, framecount_01, digit01_delta);
  if(num1>0)
    Set_Values(num1, RedLED_01, GreenLED_01, display);

  int num2 = Get_Values(Knob_02, knob02_var, digit_changed_02, framecount_02, digit02_delta);
  if(num2>0)
    Set_Values(num2, RedLED_02, GreenLED_02, display2);

  int num3 = Get_Values(Knob_03, knob03_var, digit_changed_03, framecount_03, digit03_delta);
  if(num3>0)
    Set_Values(num3, RedLED_03, GreenLED_03, display3);

  int num4 = Get_Values(Knob_04, knob04_var, digit_changed_04, framecount_04, digit04_delta);
  if(num4>0)
    Set_Values(num4, RedLED_04, GreenLED_04, display4);

  int num5 = Get_Values(Knob_05, knob05_var, digit_changed_05, framecount_05, digit05_delta);
  if(num5>0)
    Set_Values(num5, RedLED_05, GreenLED_05, display5);

  int num6 = Get_Values(Knob_06, knob06_var, digit_changed_06, framecount_06, digit06_delta);
  if(num6>0)
    Set_Values(num6, RedLED_06, GreenLED_06, display6);

}

void Set_Values(int num, int green, int red, TM1637Display d)
{
  
  if(num > 1000 - knob01_var) num = 1000;
  if(num < knob01_var) num = 0;
  
  Num_Write(num, d); 
  Set_Lights(num, red, green);
}

int Get_Values(int _knob, int _variance , bool& _changed, int& _frame, int& _delta)
{
  float val = analogRead(_knob);
  int num = mapKnob(analogRead(_knob));

  if(_changed)
  {
    _frame++;
    if(_frame <= 2)
    {
      return;
    }
    else 
    {
      _frame = 0;
      _changed = false;
    }
  }else
  {
    _changed = true;
  }
  
  //Check for variance
  if(abs(_delta - val) < _variance)
  {
    return mapKnob(_delta);
  }
  
  _delta = val;
  return num;
}

void Set_Lights(int number, int red, int green)
{
  if(number > 500)
  {

    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    
  }else
  {

    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    
  }
}

// this functions writes values to the sev seg pins  
void Num_Write(int number, TM1637Display d) 
{
  d.showNumberDecEx(number, 64, true, 4); 
}
