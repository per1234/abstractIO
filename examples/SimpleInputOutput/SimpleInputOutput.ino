/* 
Turns an LED on when switch A is held down, when switch B is pressed and when switch C is released.

Connect LEDs via suitable resistors to pins 2 and 3
Connect switches to ground and to pin 4, 5 and 6
*/
 
#include <abstractIO.h>

Output* output1 = new SimpleOutput( 2 );
Output* output2 = new SimpleOutput( 3 );

Input* inputA = new SimpleInput( 4 );
Button* buttonB = (new SimpleInput( 5 ))->button();
Button* buttonC = (new SimpleInput( 6 ))->button();

void setup()
{
    Serial.begin( 9600 );
}

void loop()
{
    // Hold down the first switch to light the LED
    // Note that inputA is not a Button, and therefore doesn't have the pressed() and released() methods.
    output1->set( inputA->get() );
    output2->set( inputA->get() );
   
    // Flash LED#1 once when the 2nd button is pressed. Holding the switch down makes no difference.
    if ( buttonB->pressed() ) {
        Serial.println( "Button B pressed" );
        output1->set( true );
        delay( 200 );
    }
    // Flash LED#1 twice when the 2nd button is released.
    if ( buttonB->released() ) {
        Serial.println( "Button B released" );
        output1->set( true );
        delay( 50 );
        output1->set( false );
        delay( 50 );
        output1->set( true );
        delay( 50 );
    }

    // Flash LED#2 once when the 3rd button is released. Holding the switch down makes no difference.
    if ( buttonC->pressed() ) {
        Serial.println( "Button C pressed" );
        output2->set( true );
        delay( 200 );
    }

    // Flash LED#2 twice when the 3rd button is released.
    if ( buttonC->released() ) {
        Serial.println( "Button C released" );
        output2->set( true );
        delay( 50 );
        output2->set( false );
        delay( 50 );
        output2->set( true );
        delay( 50 );
    }
}

